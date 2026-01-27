#pragma once
#include "AppBasePlus.h"
#include M_VulkanSdkHeader(shaderc/shaderc.hpp)
#ifdef NDEBUG
#pragma comment(lib, M_VulkanSdkLibrary(shaderc_combined.lib))
#else
#pragma comment(lib, M_VulkanSdkLibrary(shaderc_shared.lib))
#endif

VK_ENCAPSULATION_EXT_NAMESPACE_BEGIN

class FnCompileGlslToSpv {
	struct Includer : public shaderc::CompileOptions::IncluderInterface {
		struct Result_T : shaderc_include_result {
			std::string filepath;
			std::vector<char> code;
		};
		shaderc_include_result* GetInclude(const char* requested_source, shaderc_include_type, const char* requesting_source, size_t) override {
			auto& result = *(new Result_T);
			auto& filepath = result.filepath;
			auto& code = result.code;
			filepath = requesting_source;
			size_t pos = filepath.rfind('/');
			if (pos == -1)
				pos = filepath.rfind('\\');
			filepath.replace(pos + 1 + filepath.begin(), filepath.end(), requested_source);
			LoadFile(filepath.c_str(), code);
			static_cast<shaderc_include_result&>(result) = {
				filepath.c_str(),
				filepath.length(),
				code.data(),
				code.size(),
				this
			};
			return &result;
		}
		void ReleaseInclude(shaderc_include_result* data) override {
			delete static_cast<Result_T*>(data);
		}
	};

	shaderc::Compiler compiler;
	shaderc::CompileOptions options;
	shaderc::SpvCompilationResult result;
	/* Static Function */
	static void LoadFile(const char* filepath, std::vector<char>& binaries) {
		std::ifstream file(filepath, std::ios::ate | std::ios::binary);
		if (!file) {
			std::cout << std::format("[ vke::ext::FnCompileGlslToSpv ] ERROR\nFailed to open the file: {}\n", filepath);
			return;
		}
		size_t fileSize = size_t(file.tellg());
		binaries.resize(fileSize);
		file.seekg(0);
		file.read(reinterpret_cast<char*>(binaries.data()), fileSize);
		file.close();
	}
public:
	FnCompileGlslToSpv() {
		options.SetOptimizationLevel(shaderc_optimization_level_performance);
		options.SetIncluder(std::make_unique<Includer>());
	}
	/* Non-const Getter */
	shaderc::CompileOptions& Options() { return options; }
	/* Non-const Function */
	ArrayRef<const uint32_t> operator()(ArrayRef<const char> code, const char* filepath, const char* entry = "main") {
		result = compiler.CompileGlslToSpv(code, code.size(), shaderc_glsl_infer_from_source, filepath, entry, options);
		std::cout << result.GetErrorMessage();
		return { result.begin(), size_t(result.end() - result.begin()) * 4 };
	}
	ArrayRef<const uint32_t> operator()(const char* filepath, const char* entry = "main") {
		std::vector<char> binaries;
		LoadFile(filepath, binaries);
		if (size_t fileSize = binaries.size())
			return (*this)(binaries, filepath, entry);
		return {};
	}
};

inline oop::ShaderModule CreateShaderModuleFromGlsl(FnCompileGlslToSpv& fnCompiler, const char* filepath, const char* entry = "main") {
	auto code = fnCompiler(filepath, entry);
	if (code.size())
		return oop::ShaderModule({ code.size(), code });
	return {};
}

VK_ENCAPSULATION_NAMESPACE_END