#include M_VulkanSdkHeader(Volk/volk.h)
#include M_VulkanSdkHeader(vulkan/vk_enum_string_helper.h)
#pragma warning(disable:4267)
#pragma warning(disable:26437)
#undef MemoryBarrier // From winnt.h

/* Macro */
#define VK_ENCAPSULATION_VK_CORE_VERSION 328

#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
#define VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_THREAD
#define M_DeviceContextSpecifier thread_local
#else
#define M_DeviceContextSpecifier
#endif

#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_THREAD
#define M_ThreadContextSpecifier thread_local
#else
#define M_ThreadContextSpecifier
#endif

#ifdef VK_ENCAPSULATION_MAY_USE_OBJECT_SPECIFIC_HOST_MEMORY_ALLOCATOR
#define M_ObjectHostMemoryAllocator ObjectSpecificHostMemoryAllocator
#else
#define M_ObjectHostMemoryAllocator ObjectDefaultHostMemoryAllocator
#endif

#ifdef VK_ENCAPSULATION_RAII_ONLY_PROMOTED_FUNCTIONS
#define M_ConditionalDispatch(F, POSTFIX, ...) VK_ENCAPSULATION_NAMESPACE::F(__VA_ARGS__)
#elif defined VK_ENCAPSULATION_RAII_ONLY_EXTENSION_FUNCTIONS
#define M_ConditionalDispatch(F, POSTFIX, ...) VK_ENCAPSULATION_NAMESPACE::F##POSTFIX(__VA_ARGS__)
#else
#define M_ConditionalDispatch(F, POSTFIX, ...) (vk##F ? VK_ENCAPSULATION_NAMESPACE::F(__VA_ARGS__) : VK_ENCAPSULATION_NAMESPACE::F##POSTFIX(__VA_ARGS__))
#endif

#ifndef VK_ENCAPSULATION_NAMESPACE
#define VK_ENCAPSULATION_NAMESPACE vke
#endif

#ifndef VK_ENCAPSULATION_DISPATCH
#define VK_ENCAPSULATION_DISPATCH
#endif

#ifndef VK_ENCAPSULATION_INSTANCE_DISPATCH
#define VK_ENCAPSULATION_INSTANCE_DISPATCH
#endif

#ifndef VK_ENCAPSULATION_DEVICE_DISPATCH
#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
#define VK_ENCAPSULATION_DEVICE_DISPATCH DeviceContext::FunctionTable().
#else
#define VK_ENCAPSULATION_DEVICE_DISPATCH
#endif
#endif

#define M_DefineStaticDataMember(var) inline decltype(var) var

#define VK_ENCAPSULATION_NAMESPACE_BEGIN                   namespace VK_ENCAPSULATION_NAMESPACE {
#define VK_ENCAPSULATION_NAMESPACE_END                     }
#define VK_ENCAPSULATION_STRUCTURE_BEGIN(T)                template<bool forTemporaryUsage> struct Structure<Vk##T, forTemporaryUsage> : StructureBase<forTemporaryUsage, true>, Vk##T
#define VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(T)       template<bool forTemporaryUsage> struct Structure<Vk##T, forTemporaryUsage> : StructureBase<forTemporaryUsage, false>, Vk##T
#define VK_ENCAPSULATION_STRUCTURE_END(T)                  using T = Structure<Vk##T, false>; using T##_ = T; template<> struct _NativeType<T> { using type = Vk##T; }; template<> struct _NativeType<const T> { using type = const Vk##T; };
#define VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(T)  template<bool forTemporaryUsage> struct Structure<Vk##T, forTemporaryUsage> : StructureBase<forTemporaryUsage, false>
#define VK_ENCAPSULATION_TYPE_ALIAS(T0, T1)                using T0 = T1; using T0##_ = T0;

#define VK_ENCAPSULATION_RAII_NAMESPACE_BEGIN              namespace VK_ENCAPSULATION_NAMESPACE::raii {
#define VK_ENCAPSULATION_RAII_OBJECT_BEGIN(T)              template<> class Object<Vk##T> : public ObjectBase<Vk##T, M_ObjectHostMemoryAllocator>
#define VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_DEVICE(T)    template<> class Object<Vk##T> : public ObjectBase<Vk##T, M_ObjectHostMemoryAllocator>
#define VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(T) template<> class Object<Vk##T> : public ObjectBase<Vk##T, ObjectDefaultHostMemoryAllocator>
#define VK_ENCAPSULATION_RAII_OBJECT_END(T)                using T = Object<Vk##T>;

#define TemplateTypeName(T, ...) T<__VA_ARGS__>
#define DefineFunctionRaiiClass(F, InfoT)                        class _ : public Structure<Vk##InfoT, true> { public: _() = default; ~_() { F(*this); } }
#define DefineFunctionRaiiClass_L(F, InfoT, ArgT)                class _ : public Structure<Vk##InfoT, true> { ArgT arg; public: _(ArgT arg) : arg(arg) {} ~_() { F(*this, *&arg); } }
#define DefineFunctionRaiiClass_R(F, InfoT, ArgT)                class _ : public Structure<Vk##InfoT, true> { ArgT arg; public: _(ArgT arg) : arg(arg) {} ~_() { F(*&arg, *this); } }
#define DefineFunctionRaiiClass_Result(ResultT, F, InfoT)        class _ : public Structure<Vk##InfoT, true> { public: _() = default; ~_() { ResultT(*this); } operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; ResultT result = F(*this); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } }
#define DefineFunctionRaiiClass_ResultL(ResultT, F, InfoT, ArgT) class _ : public Structure<Vk##InfoT, true> { ArgT arg; public: _(ArgT arg) : arg(arg) {} ~_() { ResultT(*this); } operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; ResultT result = F(*this, *&arg); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } }
#define DefineFunctionRaiiClass_ResultR(ResultT, F, InfoT, ArgT) class _ : public Structure<Vk##InfoT, true> { ArgT arg; public: _(ArgT arg) : arg(arg) {} ~_() { ResultT(*this); } operator ResultT() { if (this->sType == VK_STRUCTURE_TYPE_MAX_ENUM) return VK_SUCCESS; ResultT result = F(*&arg, *this); this->sType = VK_STRUCTURE_TYPE_MAX_ENUM; return result; } }
#define DefineFunctionRaiiClass_TwoStruct(F, T0, T1, ...)        class _ : public Structure<Vk##T0, true>, public Structure<Vk##T1, true> { public: _() = default; using T0 = Structure<Vk##T0, true>; using T1 = Structure<Vk##T1, true>; using T0::ArrayRef; using T0::OptionalRef;\
_& PNextOf##T0(decltype(T0::pNext) pNext) & { T0::pNext = pNext; return *this; } _& AddNextStructureTo##T0(STypeStructureRef<true> next, bool allowDuplicate = false, OptionalRef<VkBaseOutStructure**> ppBack = {}) & { T0::AddNextStructure(next, allowDuplicate, ppBack); return *this; }\
_& PNextOf##T1(decltype(T1::pNext) pNext) & { T1::pNext = pNext; return *this; } _& AddNextStructureTo##T1(STypeStructureRef<true> next, bool allowDuplicate = false, OptionalRef<VkBaseOutStructure**> ppBack = {}) & { T1::AddNextStructure(next, allowDuplicate, ppBack); return *this; }\
_&& PNextOf##T0(decltype(T0::pNext) pNext) && { T0::pNext = pNext; return std::move(*this); } _&& AddNextStructureTo##T0(STypeStructureRef<true> next, bool allowDuplicate = false, OptionalRef<VkBaseOutStructure**> ppBack = {}) && { T0::AddNextStructure(next, allowDuplicate, ppBack); return std::move(*this); }\
_&& PNextOf##T1(decltype(T1::pNext) pNext) && { T1::pNext = pNext; return std::move(*this); } _&& AddNextStructureTo##T1(STypeStructureRef<true> next, bool allowDuplicate = false, OptionalRef<VkBaseOutStructure**> ppBack = {}) && { T1::AddNextStructure(next, allowDuplicate, ppBack); return std::move(*this); }\
__VA_ARGS__; ~_() { F(*this, *this); } }
#define DefineRaiiFunction(F, InfoT)                                  inline AUTO F() { DefineFunctionRaiiClass(F, InfoT); return _{}; }
#define DefineRaiiFunction_L(F, InfoT, ArgT, arg, ...)                inline AUTO F(ArgT arg __VA_ARGS__) { DefineFunctionRaiiClass_L(F, InfoT, decltype(arg)); return _{ arg }; }
#define DefineRaiiFunction_R(F, ArgT, arg, InfoT)                     inline AUTO F(ArgT arg) { DefineFunctionRaiiClass_R(F, InfoT, decltype(arg)); return _{ arg }; }
#define DefineRaiiFunction_Result(ResultT, F, InfoT)                  inline AUTO F() { DefineFunctionRaiiClass_Result(ResultT, F, InfoT); return _{}; }
#define DefineRaiiFunction_ResultL(ResultT, F, InfoT, ArgT, arg, ...) inline AUTO F(ArgT arg __VA_ARGS__) { DefineFunctionRaiiClass_ResultL(ResultT, F, InfoT, decltype(arg)); return _{ arg }; }
#define DefineRaiiFunction_ResultR(ResultT, F, ArgT, arg, InfoT)      inline AUTO F(ArgT arg) { DefineFunctionRaiiClass_ResultR(ResultT, F, InfoT, decltype(arg)); return _{ arg }; }
#define DefineRaiiFunction_TwoStruct(F, T0, T1, ...)                  inline AUTO F() { DefineFunctionRaiiClass_TwoStruct(F, T0, T1, __VA_ARGS__); return _{}; }
#define DefineSetter_Copy(F, T, var)                            _& F(T const& var) & { this->var = var; return *this; }                                                                            _&& F(T const& var) && { this->var = var; return std::move(*this); }
#define DefineSetter_CopyOptional(F, T, var, sw, op)            _& F(T const& var) & { this->var = var; sw = op; return *this; }                                                                   _&& F(T const& var) && { this->var = var; sw = op; return std::move(*this); }
#define DefineSetter_ArrayCopy(F, T, var)                       _& F(VK_ENCAPSULATION_NAMESPACE::ArrayRef<const T, false> var) & { std::memcpy(&this->var, var, sizeof this->var); return *this; } _&& F(VK_ENCAPSULATION_NAMESPACE::ArrayRef<const T, false> var) && { std::memcpy(&this->var, var, sizeof this->var); return std::move(*this); }
#define DefineSetter_Ref(F, T, var)                             _& F(OptionalRef<T> var) & { p##F = &var; return *this; }                                                                          _&& F(OptionalRef<T> var) && { p##F = &var; return std::move(*this); }
#define DefineSetter_PointerAndRef(F, T, var)                   DefineSetter_Copy(P##F, T*, p##F); DefineSetter_Ref(F, T, var)
#define DefineSetter_ArrayRef(F, T, var, count, ...)            _& F(ArrayRef<T> var) & { count = var.size(); p##F = var; __VA_ARGS__; return *this; }                                             _&& F(ArrayRef<T> var) && { count = var.size(); p##F = var; __VA_ARGS__; return std::move(*this); }
#define DefineSetter_ArrayRefIgnoreC(F, T, var)                 _& F(ArrayRef<T> var) & { p##F = var; return *this; }                                                                              _&& F(ArrayRef<T> var) && { p##F = var; return std::move(*this); }
#define DefineSetter_ArrayRefSpecialP(F, T, var, count, p)      _& F(ArrayRef<T> var) & { count = var.size(); p = var; return *this; }                                                             _&& F(ArrayRef<T> var) && { count = var.size(); p = var; return std::move(*this); }
#define DefineSetterForUnionWrapper_Copy(F, T, var)             _& F(T const& var) & { value.var = var; return *this; }                                                                            _&& F(T const& var) && { value.var = var; return std::move(*this); }
#define DefineSetterForUnionWrapper_ArrayCopy(F, T, var, count) _& F(VK_ENCAPSULATION_NAMESPACE::ArrayRef<T, false> var) & { std::memcpy(&value.var, var, sizeof value.var); return *this; }       _&& F(VK_ENCAPSULATION_NAMESPACE::ArrayRef<T, false> var) && { std::memcpy(&value.var, var, sizeof value.var); return std::move(*this); }
#define UsingRefType template<typename T> using ArrayRef = ArrayRef<T, !forTemporaryUsage>; template<typename T> using OptionalRef = OptionalRef<T, !forTemporaryUsage>;
#define StructureClassHeader(T, ...)         using _ = Structure; constexpr Structure() : Vk##T{ .sType = _sType<Vk##T>, __VA_ARGS__ } {} template<typename... Ts> constexpr Structure(Ts&&... args) requires(std::constructible_from<Vk##T, Ts...>) : Vk##T(std::forward<Ts>(args)...) { sType = _sType<Vk##T>; } DefineSetter_Copy(PNext, decltype(pNext), pNext) UsingRefType
#define StructureClassHeader_NoSType(T, ...) using _ = Structure; constexpr Structure() : Vk##T{ __VA_ARGS__ } {} template<typename... Ts> constexpr Structure(Ts&&... args) requires(std::constructible_from<Vk##T, Ts...>) : Vk##T(std::forward<Ts>(args)...) {} UsingRefType
#define StructureClassHeader_UnionWrapper(T) Structure() = default; Structure(const Vk##T& v) { std::memcpy(this, &v, sizeof v); } UsingRefType \
operator const Vk##T&() const { return reinterpret_cast<const Vk##T&>(*this); } operator Vk##T&() { return reinterpret_cast<Vk##T&>(*this); }\
const Vk##T* operator&() const { return reinterpret_cast<const Vk##T*>(this); } Vk##T* operator&() { return reinterpret_cast<Vk##T*>(this); }\
operator _OptionalRef<const Vk##T, false>() { return reinterpret_cast<const Vk##T&>(*this); } operator _OptionalRef<const Vk##T, true>() const& { return reinterpret_cast<const Vk##T&>(*this); } operator _OptionalRef<const Vk##T, true>() && = delete;\
operator    _ArrayRef<const Vk##T, false>() { return reinterpret_cast<const Vk##T&>(*this); } operator    _ArrayRef<const Vk##T, true>() const& { return reinterpret_cast<const Vk##T&>(*this); } operator    _ArrayRef<const Vk##T, true>() && = delete;
#define ObjectClassHeader(T) using Handle_T = Vk##T; friend OptionalRef<Vk##T>; friend OptionalRef<Vk##T, true>; friend OptionalRef<const Vk##T>; friend OptionalRef<const Vk##T, true>; friend ArrayRef<Vk##T>; friend ArrayRef<Vk##T, true>; friend ArrayRef<const Vk##T>; friend ArrayRef<const Vk##T, true>;\
public: Object() = default; Object(Object&&) noexcept = default; Object& operator=(Object&&) noexcept = default;\
operator const Vk##T&() const { return handle; } const Vk##T* operator&() const { return &handle; } Object* operator&() { return this; }\
operator OptionalRef<const Vk##T, false>() const { return handle; } operator OptionalRef<const Vk##T, true>() const& { return handle; } operator OptionalRef<const Vk##T, true>() && = delete; \
operator    ArrayRef<const Vk##T, false>() const { return handle; } operator    ArrayRef<const Vk##T, true>() const& { return handle; }    operator ArrayRef<const Vk##T, true>() && = delete;

VK_ENCAPSULATION_NAMESPACE_BEGIN

#include "VKStructureType.h"

/* Helper Class */
template<typename T>
struct _NativeType {
	using type = T;
};
template<typename T>
using Native_T = _NativeType<T>::type;
template<typename T>
using Ref = Native_T<T>&;
template<typename T>
const VkStructureType& sType = _sType<Native_T<T>>;

using EmptyList = std::initializer_list<std::monostate>;
template<typename T, bool fromLValue>
class _OptionalRef {
protected:
	T* const pointer = nullptr;
public:
	_OptionalRef(EmptyList = {}) {}
	_OptionalRef(T& value) : pointer(&value) {}
	_OptionalRef(T&&) requires(fromLValue) = delete;
	_OptionalRef(auto& wrapper) requires(requires { { wrapper.handle } -> std::same_as<T&>; }) : pointer(&wrapper.handle) {}
	template<bool fromLValue>
	_OptionalRef(const _OptionalRef<T, fromLValue>& other) : pointer(&other) {}
	template<bool fromLValue>
	_OptionalRef(const _OptionalRef<std::remove_const_t<T>, fromLValue>& other) requires(std::is_const_v<T>) : pointer(&other) {}
	T& Get() const {
	#ifndef NDEBUG
		if (!pointer)
			throw 0;
	#endif
		return *pointer;
	}
	operator T&() const { return Get(); }
	T* operator&() const { return pointer; }
	_OptionalRef& operator=(const _OptionalRef&) = delete;
};
template<bool fromLValue>
class _OptionalRef<void, fromLValue> {
protected:
	void* const pointer = nullptr;
public:
	_OptionalRef(EmptyList = {}) {}
	_OptionalRef(auto& value) : pointer(&value) {}
	_OptionalRef(auto&&) requires(fromLValue) = delete;
	void* operator&() const { return pointer; }
	_OptionalRef& operator=(const _OptionalRef&) = delete;
};
template<bool fromLValue>
class _OptionalRef<const void, fromLValue> {
protected:
	const void* const pointer = nullptr;
public:
	_OptionalRef(EmptyList = {}) {}
	_OptionalRef(const auto& value) : pointer(&value) {}
	_OptionalRef(auto&&) requires(fromLValue) = delete;
	const void* operator&() const { return pointer; }
	_OptionalRef& operator=(const _OptionalRef&) = delete;
};
template<typename T, bool fromLValue = false>
using OptionalRef = _OptionalRef<Native_T<T>, fromLValue>;
template<typename T>
using OptionalValue = _OptionalRef<const Native_T<T>, false>;
template<typename T, bool fromLValue>
class _ArrayRef {
protected:
	T* const pointer = nullptr;
	size_t count = 0;
public:
	using value_type = T;
	_ArrayRef(EmptyList = {}) {}
	_ArrayRef(T& data) : pointer(&data), count(1) {}
	_ArrayRef(T&&) requires(fromLValue) = delete;
	_ArrayRef(auto& wrapper) requires(requires { { wrapper.handle } -> std::convertible_to<T&>; }) : pointer(&wrapper.handle), count(1) {}
	_ArrayRef(std::initializer_list<std::remove_const_t<T>> list) requires(!fromLValue && std::is_const_v<T>) : pointer(list.begin()), count(list.size()) {}
	template<typename R>
	_ArrayRef(R&& range) requires(
		std::ranges::contiguous_range<R> &&
		std::ranges::sized_range<R> &&
		std::ranges::borrowed_range<R> &&
		std::convertible_to<std::iter_value_t<R>*, T*> &&
		sizeof(std::iter_value_t<R>) == sizeof(T)) : pointer(std::ranges::data(range)), count(std::ranges::size(range)) {}
	template<typename R>
	_ArrayRef(R&& range) requires(
		std::ranges::contiguous_range<R> &&
		std::ranges::sized_range<R> &&
		std::ranges::borrowed_range<R> &&
		requires { { std::ranges::data(range)->handle } -> std::convertible_to<T&>; } &&
		sizeof(std::iter_value_t<R>) == sizeof(T)) : pointer(&std::ranges::data(range)->handle), count(std::ranges::size(range)) {}
	_ArrayRef(size_t elementCount, T* pData) : pointer(pData), count(elementCount) {}
	_ArrayRef(size_t elementCount, auto* handles) requires(
		requires { { handles->handle } -> std::convertible_to<T&>; } &&
		sizeof* handles == sizeof(T)) : pointer(&handles->handle), count(elementCount) {}
	_ArrayRef(T* pData, size_t elementCount) : pointer(pData), count(elementCount) {}
	_ArrayRef(auto* handles, size_t elementCount) requires(
		requires { { handles->handle } -> std::convertible_to<T&>; } &&
		sizeof* handles == sizeof(T)) : pointer(&handles->handle), count(elementCount) {}
	template<bool fromLValue>
	_ArrayRef(const _ArrayRef<T, fromLValue>& other) : pointer(other), count(other.size()) {}
	template<bool fromLValue>
	_ArrayRef(const _ArrayRef<std::remove_const_t<T>, fromLValue>& other) requires(std::is_const_v<T>) : pointer(other), count(other.size()) {}
	operator T*() const { return pointer; }
	size_t Count() const { return count; }
	size_t size() const { return count; }
	T* operator->() const { return pointer; }
	T* data() const { return pointer; }
	T* begin() const { return pointer; }
	T* end() const { return pointer + count; }
	_ArrayRef& operator=(const _ArrayRef&) = delete;
};
template<bool fromLValue>
class _ArrayRef<void, fromLValue> {
protected:
	void* const pointer = nullptr;
	size_t count = 0;
public:
	using value_type = uint8_t;
	_ArrayRef(EmptyList = {}) {}
	template<typename R>
	_ArrayRef(R&& range) requires(
		std::ranges::contiguous_range<R> &&
		std::ranges::sized_range<R> &&
		std::ranges::borrowed_range<R> &&
		!std::is_const_v<std::iter_value_t<R>>) : pointer(std::ranges::data(range)), count(sizeof(std::iter_value_t<R>)* std::ranges::size(range)) {}
	_ArrayRef(size_t dataSize, void* pData) : pointer(pData), count(dataSize) {}
	_ArrayRef(void* pData, size_t dataSize) : pointer(pData), count(dataSize) {}
	template<typename T, bool fromLValue>
	_ArrayRef(const _ArrayRef<T, fromLValue>& other) requires(!std::is_const_v<T>) : pointer(other), count(other.size()) {}
	operator void*() const { return pointer; }
	size_t Count() const { return count; }
	size_t size() const { return count; }
	uint8_t* data() const { return reinterpret_cast<uint8_t*>(pointer); }
	uint8_t* begin() const { return reinterpret_cast<uint8_t*>(pointer); }
	uint8_t* end() const { return begin() + count; }
	_ArrayRef& operator=(const _ArrayRef&) = delete;
};
template<bool fromLValue>
class _ArrayRef<const void, fromLValue> {
protected:
	const void* const pointer = nullptr;
	size_t count = 0;
public:
	using value_type = const uint8_t;
	_ArrayRef(EmptyList = {}) {}
	template<typename T>
	_ArrayRef(std::initializer_list<T> list) requires(!fromLValue) : pointer(list.begin()), count(sizeof(T)* list.size()) {}
	template<typename R>
	_ArrayRef(R&& range) requires(
		std::ranges::contiguous_range<R> &&
		std::ranges::sized_range<R> &&
		std::ranges::borrowed_range<R>) : pointer(std::ranges::data(range)), count(sizeof(std::iter_value_t<R>)* std::ranges::size(range)) {}
	_ArrayRef(size_t dataSize, const void* pData) : pointer(pData), count(dataSize) {}
	_ArrayRef(const void* pData, size_t dataSize) : pointer(pData), count(dataSize) {}
	template<typename T, bool fromLValue>
	_ArrayRef(const _ArrayRef<T, fromLValue>& other) : pointer(other), count(other.size()) {}
	operator const void*() const { return pointer; }
	size_t Count() const { return count; }
	size_t size() const { return count; }
	const uint8_t* data() const { return reinterpret_cast<const uint8_t*>(pointer); }
	const uint8_t* begin() const { return reinterpret_cast<const uint8_t*>(pointer); }
	const uint8_t* end() const { return begin() + count; }
	_ArrayRef& operator=(const _ArrayRef&) = delete;
};
template<typename T, bool fromLValue = false>
using ArrayRef = _ArrayRef<Native_T<T>, fromLValue>;
template<typename T>
class CycleRef : public _ArrayRef<T, true> {
protected:
	size_t index = 0;
public:
	using _ArrayRef<T, true>::_ArrayRef;
	operator T&() const { return this->pointer[index]; }
	size_t Index() const { return index; }
	T& operator++() { index = (index + 1) % this->count; return *this; }
	T& operator++(int) { T& _ = *this; index = (index + 1) % this->count; return _; }
};

template<bool forTemporaryUsage = false>
class STypeStructureRef {
protected:
	VkBaseOutStructure* const pointer = nullptr;
public:
	STypeStructureRef() = default;
	STypeStructureRef(auto& structure) requires(requires { structure.sType; }) : pointer(reinterpret_cast<VkBaseOutStructure*>(&structure)) {}
	STypeStructureRef(auto&& structure) requires(requires { structure.sType; } && forTemporaryUsage) : STypeStructureRef(structure) {}
	template<bool forTemporaryUsage>
	STypeStructureRef(const STypeStructureRef<forTemporaryUsage>& other) : pointer(&other) {}
	VkBaseOutStructure* operator&() const { return pointer; }
	STypeStructureRef& operator=(const STypeStructureRef&) = delete;
};
template<typename T>
class _HandleRef : public OptionalRef<T> {
public:
	explicit _HandleRef(EmptyList) {}
	using OptionalRef<T>::OptionalRef;
	T& operator=(T handle) const { return OptionalRef<T>::Get() = handle; }
};
template<typename T>
using HandleRef = _HandleRef<Native_T<T>>;
template<typename T>
class _HandleArrayRef : public ArrayRef<T> {
public:
	explicit _HandleArrayRef(EmptyList) {}
	using ArrayRef<T>::ArrayRef;
};
template<typename T>
using HandleArrayRef = _HandleArrayRef<Native_T<T>>;

struct FLAGS {
	VkFlags flags;
	constexpr FLAGS(VkFlags flags) : flags(flags) {}
	template<typename T>
	constexpr operator T() requires(requires(T s) { s.sType; s.flags; } && std::same_as<T, Native_T<T>>) {
		return Native_T<T>{ .sType = _sType<Native_T<T>>, .flags = flags };
	}
};

#ifdef VK_ENCAPSULATION_RESULT_THROW
class RESULT {
	VkResult result;
	static void(*pfnOnFailure)(VkResult);
public:
	RESULT(VkResult result) : result(result) {}
	RESULT(RESULT&& other) noexcept : result(other.result) { other.result = VK_SUCCESS; }
	~RESULT() noexcept(false) {
		if (uint32_t(result) < VK_RESULT_MAX_ENUM)
			return;
		if (pfnOnFailure)
			pfnOnFailure(result);
		throw result;
	}
	operator VkResult() {
		VkResult result = this->result;
		this->result = VK_SUCCESS;
		return result;
	}
	static void FnOnFailure(void(*pfnOnFailure)(VkResult)) { RESULT::pfnOnFailure = pfnOnFailure; }
};
M_DefineStaticDataMember(RESULT::pfnOnFailure);
#elif defined VK_ENCAPSULATION_RESULT_NODISCARD
struct [[nodiscard]] RESULT {
	VkResult result;
	RESULT(VkResult result) : result(result) {}
	operator VkResult() const { return result; }
};
#pragma warning(disable:4834)
#pragma warning(disable:6031)
#else
using RESULT = VkResult;
#endif

#ifdef VK_ENCAPSULATION_ALLOW_RAII_FUNCTION
#define AUTO auto
#else
struct AUTO {
	AUTO(auto&&) {}
};
#endif

/* Context */
class InstanceContext {
protected:
	const VkInstance* pInstance = &nullInstance;
	static constexpr VkInstance nullInstance = VK_NULL_HANDLE;
	static InstanceContext context;
	static void Instance(OptionalRef<const VkInstance, true> instance) { context.pInstance = &instance ? &instance : &nullInstance; }
public:
	static VkInstance Instance() { return *context.pInstance; }
};
M_DefineStaticDataMember(InstanceContext::context);

class DeviceContext {
protected:
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	const VkDevice* pDevice = &nullDevice;
	const VolkDeviceTable* pFunctionTable = nullptr;
	static constexpr VkDevice nullDevice = VK_NULL_HANDLE;
	static M_DeviceContextSpecifier DeviceContext context;
	static void PhysicalDevice(VkPhysicalDevice physicalDevice) { context.physicalDevice = physicalDevice; }
	static void Device(OptionalRef<const VkDevice, true> device) { context.pDevice = &device ? &device : &nullDevice; }
	static void FunctionTable(OptionalRef<const VolkDeviceTable, true> functionTable) { context.pFunctionTable = &functionTable; }
public:
	static VkPhysicalDevice PhysicalDevice() { return context.physicalDevice; }
	static VkDevice Device() { return *context.pDevice; }
#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
	static const VolkDeviceTable& FunctionTable() { return *context.pFunctionTable;  }
#endif
};
M_DeviceContextSpecifier M_DefineStaticDataMember(DeviceContext::context);

class ThreadContext {
protected:
	VkQueue queue;
	VkCommandBuffer commandBuffer;
	const VkAllocationCallbacks* pAllocator;
	static M_ThreadContextSpecifier ThreadContext context;
	static void CommandBuffer(VkCommandBuffer commandBuffer) { context.commandBuffer = commandBuffer; }
public:
	static VkQueue Queue() { return context.queue; }
	static VkCommandBuffer CommandBuffer() { return context.commandBuffer; }
	static const VkAllocationCallbacks* PAllocator() { return context.pAllocator; }
	static OptionalRef<const VkAllocationCallbacks> Allocator() { if (PAllocator()) return *PAllocator(); return {}; }
	static void Queue(VkQueue queue) { context.queue = queue; }
#ifdef VK_ENCAPSULATION_MAY_USE_CUSTOM_HOST_MEMORY_ALLOCATOR
	static void Allocator(OptionalRef<const VkAllocationCallbacks> allocator) { context.pAllocator = &allocator; }
#endif
};
M_ThreadContextSpecifier M_DefineStaticDataMember(ThreadContext::context);

/* Object Base */
class ObjectDefaultHostMemoryAllocator {};
class ObjectSpecificHostMemoryAllocator {};

template<typename T_Handle, typename T_HostMemoryAllocator>
class ObjectBase {
protected:
	T_Handle handle = VK_NULL_HANDLE;
public:
	ObjectBase() = default;
	ObjectBase(ObjectBase&& other) noexcept : handle(other.handle) { other.handle = VK_NULL_HANDLE; }
	ObjectBase& operator=(ObjectBase&& other) noexcept { this->~ObjectBase(); handle = other.handle; other.handle = VK_NULL_HANDLE; return *this; }
	OptionalRef<const VkAllocationCallbacks> Allocator() const { return ThreadContext::Allocator(); }
};
template<typename T_Handle>
class ObjectBase<T_Handle, ObjectSpecificHostMemoryAllocator> {
protected:
	T_Handle handle = VK_NULL_HANDLE;
	const VkAllocationCallbacks* pAllocator = nullptr;
public:
	ObjectBase() = default;
	ObjectBase(ObjectBase&& other) noexcept : handle(other.handle), pAllocator(other.pAllocator) { other.handle = VK_NULL_HANDLE; other.pAllocator = nullptr; }
	ObjectBase& operator=(ObjectBase&& other) noexcept { this->~ObjectBase(); handle = other.handle; pAllocator = other.pAllocator; other.handle = VK_NULL_HANDLE; other.pAllocator = nullptr; return *this; }
	OptionalRef<const VkAllocationCallbacks> Allocator() const { if (pAllocator) return *pAllocator; return {}; }
	OptionalRef<const VkAllocationCallbacks> Allocator() { if (!pAllocator) pAllocator = ThreadContext::PAllocator(); return std::as_const(*this).Allocator(); }
};

namespace raii {
	template<typename T>
	class Object;
}

/* Structure Base */
template<bool forTemporaryUsage = false, bool isChainable = true>
struct StructureBase {
protected:
	StructureBase() = default;
	static VkBaseOutStructure** SetPNext(VkBaseOutStructure*& pBegin, VkBaseOutStructure* pNext, bool allowDuplicate = false) {
		if (!pNext)
			return nullptr;
		auto SetPNext_Internal = [](auto&& self, VkBaseOutStructure*& pBegin, VkBaseOutStructure* pNext, bool allowDuplicate)->VkBaseOutStructure** {
			if (pBegin == pNext)
				return nullptr;
			if (pBegin)
				if (!allowDuplicate &&
					pBegin->sType == pNext->sType)
					return nullptr;
				else
					return self(self, pBegin->pNext, pNext, allowDuplicate);
			else
				return &(pBegin = pNext);
		};
		return SetPNext_Internal(SetPNext_Internal, pBegin, pNext, allowDuplicate);
	}
public:
	StructureBase& AddNextStructure(STypeStructureRef<forTemporaryUsage> next, bool allowDuplicate = false, OptionalRef<VkBaseOutStructure**> ppBack = {}) requires(isChainable) {
		VkBaseOutStructure** _ = SetPNext(reinterpret_cast<VkBaseOutStructure*>(this)->pNext, reinterpret_cast<VkBaseOutStructure*>(&next), allowDuplicate);
		if (&ppBack)
			ppBack.Get() = _;
		if (*_)
			return **reinterpret_cast<StructureBase**>(_);
		else
			return *this;
	}
};

template<typename T, bool forTemporaryUsage = false>
struct Structure;
template<typename T>
Structure(T) -> Structure<T, false>;

/* Concept */
template<typename T>
concept IsNotPointer = !std::is_pointer_v<std::remove_reference_t<T>> && !std::is_null_pointer_v<std::remove_reference_t<T>>;
template<typename T>
concept IsNotRange = !std::ranges::range<T>;
template<typename T>
concept IsNotRangeOrPointer = IsNotRange<T> && IsNotPointer<T>;
template<typename T, typename VT>
concept IsDynamicArray = std::ranges::contiguous_range<T> && std::constructible_from<vke::ArrayRef<VT>, T&> && requires(T& r) { r.resize(size_t(1)); };
template<typename T>
concept IsDynamicByteArray = std::ranges::contiguous_range<T> && sizeof(std::ranges::range_value_t<T>) == 1 && requires(T& r) { r.resize(size_t(1)); };

template<typename T>
concept IsInStructure = requires(T s) { { s.pNext }-> std::same_as<const void*&>; };
template<typename T>
concept IsOutStructure = requires(T s) { { s.pNext }-> std::same_as<void*&>; };

/* Helper Function */
auto& Wrapper(auto& structure) {
	return reinterpret_cast<Structure<std::remove_cvref_t<decltype(structure)>>&>(structure);
}

auto CopyHandles(auto& dstHandles) {
	struct _ {
		using DynamicArrayRef = decltype(dstHandles);
		DynamicArrayRef dstHandles;
		_(DynamicArrayRef dstHandles) : dstHandles(dstHandles) {}
		void Src(ArrayRef<raii::Object<std::ranges::range_value_t<DynamicArrayRef>>> srcObjects) const {
			dstHandles.resize(srcObjects.size());
			for (auto p = std::ranges::data(dstHandles); auto& i : srcObjects)
				*p = i, p++;
		}
	};
	return _{ dstHandles };
}

/* Initialization Function */
inline RESULT Initialize() {
	return volkInitialize();
}

// ======== Encapsulation Of vulkan_core.h ========

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(Extent2D) {
	StructureClassHeader_NoSType(Extent2D);
	constexpr Structure(uint32_t width, uint32_t height = 0) : VkExtent2D(width, height) {}
	DefineSetter_Copy(Width, uint32_t, width);
	DefineSetter_Copy(Height, uint32_t, height);
};
VK_ENCAPSULATION_STRUCTURE_END(Extent2D)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(Extent3D) {
	StructureClassHeader_NoSType(Extent3D);
	constexpr Structure(uint32_t width, uint32_t height = 0, uint32_t depth = 0) : VkExtent3D(width, height, depth) {}
	DefineSetter_Copy(Width, uint32_t, width);
	DefineSetter_Copy(Height, uint32_t, height);
	DefineSetter_Copy(Depth, uint32_t, depth);
};
VK_ENCAPSULATION_STRUCTURE_END(Extent3D)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(Offset2D) {
	StructureClassHeader_NoSType(Offset2D);
	constexpr Structure(int32_t x, int32_t y = 0) : VkOffset2D(x, y) {}
	DefineSetter_Copy(X, int32_t, x);
	DefineSetter_Copy(Y, int32_t, y);
};
VK_ENCAPSULATION_STRUCTURE_END(Offset2D)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(Offset3D) {
	StructureClassHeader_NoSType(Offset3D);
	constexpr Structure(int32_t x, int32_t y = 0, int32_t z = 0) : VkOffset3D(x, y, z) {}
	DefineSetter_Copy(X, int32_t, x);
	DefineSetter_Copy(Y, int32_t, y);
	DefineSetter_Copy(Z, int32_t, z);
};
VK_ENCAPSULATION_STRUCTURE_END(Offset3D)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(Rect2D) {
	StructureClassHeader_NoSType(Rect2D);
	constexpr Structure(const VkOffset2D& offset, const VkExtent2D& extent) : VkRect2D(offset, extent) {}
	constexpr Structure(int32_t x, int32_t y, uint32_t width, uint32_t height) : VkRect2D({ x, y }, { width, height }) {}
	DefineSetter_Copy(Offset, VkOffset2D, offset);
	DefineSetter_Copy(Extent, VkExtent2D, extent);
};
VK_ENCAPSULATION_STRUCTURE_END(Rect2D)

VK_ENCAPSULATION_TYPE_ALIAS(BaseInStructure, VkBaseInStructure)

VK_ENCAPSULATION_TYPE_ALIAS(BaseOutStructure, VkBaseOutStructure)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferMemoryBarrier) {
	StructureClassHeader(BufferMemoryBarrier, .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED, .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED, .size = VK_WHOLE_SIZE);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags, srcAccessMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags, dstAccessMask);
	DefineSetter_Copy(SrcQueueFamilyIndex, uint32_t, srcQueueFamilyIndex);
	DefineSetter_Copy(DstQueueFamilyIndex, uint32_t, dstQueueFamilyIndex);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferMemoryBarrier)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DispatchIndirectCommand) {
	StructureClassHeader_NoSType(DispatchIndirectCommand);
	DefineSetter_Copy(X, uint32_t, x);
	DefineSetter_Copy(Y, uint32_t, y);
	DefineSetter_Copy(Z, uint32_t, z);
};
VK_ENCAPSULATION_STRUCTURE_END(DispatchIndirectCommand)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DrawIndexedIndirectCommand) {
	StructureClassHeader_NoSType(DrawIndexedIndirectCommand);
	DefineSetter_Copy(IndexCount, uint32_t, indexCount);
	DefineSetter_Copy(InstanceCount, uint32_t, instanceCount);
	DefineSetter_Copy(FirstIndex, uint32_t, firstIndex);
	DefineSetter_Copy(VertexOffset, int32_t, vertexOffset);
	DefineSetter_Copy(FirstInstance, uint32_t, firstInstance);
};
VK_ENCAPSULATION_STRUCTURE_END(DrawIndexedIndirectCommand)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DrawIndirectCommand) {
	StructureClassHeader_NoSType(DrawIndirectCommand);
	DefineSetter_Copy(VertexCount, uint32_t, vertexCount);
	DefineSetter_Copy(InstanceCount, uint32_t, instanceCount);
	DefineSetter_Copy(FirstVertex, uint32_t, firstVertex);
	DefineSetter_Copy(FirstInstance, uint32_t, firstInstance);
};
VK_ENCAPSULATION_STRUCTURE_END(DrawIndirectCommand)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ImageSubresourceRange) {
	StructureClassHeader_NoSType(ImageSubresourceRange, .levelCount = VK_REMAINING_MIP_LEVELS, .layerCount = VK_REMAINING_ARRAY_LAYERS);
	DefineSetter_Copy(AspectMask, VkImageAspectFlags, aspectMask);
	DefineSetter_Copy(BaseMipLevel, uint32_t, baseMipLevel);
	DefineSetter_Copy(LevelCount, uint32_t, levelCount);
	DefineSetter_Copy(BaseArrayLayer, uint32_t, baseArrayLayer);
	DefineSetter_Copy(LayerCount, uint32_t, layerCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageSubresourceRange)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageMemoryBarrier) {
	StructureClassHeader(ImageMemoryBarrier, .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED, .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags, srcAccessMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags, dstAccessMask);
	DefineSetter_Copy(OldLayout, VkImageLayout, oldLayout);
	DefineSetter_Copy(NewLayout, VkImageLayout, newLayout);
	DefineSetter_Copy(SrcQueueFamilyIndex, uint32_t, srcQueueFamilyIndex);
	DefineSetter_Copy(DstQueueFamilyIndex, uint32_t, dstQueueFamilyIndex);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(SubresourceRange, VkImageSubresourceRange, subresourceRange);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageMemoryBarrier)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryBarrier) {
	StructureClassHeader(MemoryBarrier);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags, srcAccessMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags, dstAccessMask);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryBarrier)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PipelineCacheHeaderVersionOne) {
	StructureClassHeader_NoSType(PipelineCacheHeaderVersionOne);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCacheHeaderVersionOne)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AllocationCallbacks) {
	StructureClassHeader_NoSType(AllocationCallbacks);
	DefineSetter_PointerAndRef(UserData, void, userData);
	DefineSetter_Copy(FnAllocation, PFN_vkAllocationFunction, pfnAllocation);
	DefineSetter_Copy(FnReallocation, PFN_vkReallocationFunction, pfnReallocation);
	DefineSetter_Copy(FnFree, PFN_vkFreeFunction, pfnFree);
	DefineSetter_Copy(FnInternalAllocation, PFN_vkInternalAllocationNotification, pfnInternalAllocation);
	DefineSetter_Copy(FnInternalFree, PFN_vkInternalFreeNotification, pfnInternalFree);
};
VK_ENCAPSULATION_STRUCTURE_END(AllocationCallbacks)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ApplicationInfo) {
	StructureClassHeader(ApplicationInfo);
	DefineSetter_ArrayRefIgnoreC(ApplicationName, const char, applicationName);
	DefineSetter_Copy(ApplicationVersion, uint32_t, applicationVersion);
	DefineSetter_ArrayRefIgnoreC(EngineName, const char, engineName);
	DefineSetter_Copy(EngineVersion, uint32_t, engineVersion);
	DefineSetter_Copy(ApiVersion, uint32_t, apiVersion);
};
VK_ENCAPSULATION_STRUCTURE_END(ApplicationInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(FormatProperties) {
	StructureClassHeader_NoSType(FormatProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(FormatProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ImageFormatProperties) {
	StructureClassHeader_NoSType(ImageFormatProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageFormatProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(InstanceCreateInfo) {
	StructureClassHeader(InstanceCreateInfo);
	DefineSetter_Copy(Flags, VkInstanceCreateFlags, flags);
	DefineSetter_Ref(ApplicationInfo, const VkApplicationInfo, applicationInfo);
	DefineSetter_Copy(EnabledLayerCount, uint32_t, enabledLayerCount);
	DefineSetter_ArrayRefSpecialP(EnabledLayers, const char* const, enabledLayers, enabledLayerCount, ppEnabledLayerNames);
	DefineSetter_Copy(EnabledExtensionCount, uint32_t, enabledExtensionCount);
	DefineSetter_ArrayRefSpecialP(EnabledExtensions, const char* const, enabledExtensions, enabledExtensionCount, ppEnabledExtensionNames);
};
VK_ENCAPSULATION_STRUCTURE_END(InstanceCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MemoryHeap) {
	StructureClassHeader_NoSType(MemoryHeap);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryHeap)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MemoryType) {
	StructureClassHeader_NoSType(MemoryType);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryType)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PhysicalDeviceFeatures) {
	StructureClassHeader_NoSType(PhysicalDeviceFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PhysicalDeviceLimits) {
	StructureClassHeader_NoSType(PhysicalDeviceLimits);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLimits)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PhysicalDeviceMemoryProperties) {
	StructureClassHeader_NoSType(PhysicalDeviceMemoryProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMemoryProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PhysicalDeviceSparseProperties) {
	StructureClassHeader_NoSType(PhysicalDeviceSparseProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSparseProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PhysicalDeviceProperties) {
	StructureClassHeader_NoSType(PhysicalDeviceProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(QueueFamilyProperties) {
	StructureClassHeader_NoSType(QueueFamilyProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceQueueCreateInfo) {
	StructureClassHeader(DeviceQueueCreateInfo);
	DefineSetter_Copy(Flags, VkDeviceQueueCreateFlags, flags);
	DefineSetter_Copy(QueueFamilyIndex, uint32_t, queueFamilyIndex);
	DefineSetter_Copy(QueueCount, uint32_t, queueCount);
	DefineSetter_ArrayRef(QueuePriorities, const float, queuePriorities, queueCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceQueueCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceCreateInfo) {
	StructureClassHeader(DeviceCreateInfo);
	DefineSetter_Copy(Flags, VkDeviceCreateFlags, flags);
	DefineSetter_Copy(QueueCreateInfoCount, uint32_t, queueCreateInfoCount);
	DefineSetter_ArrayRef(QueueCreateInfos, const VkDeviceQueueCreateInfo, queueCreateInfos, queueCreateInfoCount);
	DefineSetter_Copy(EnabledExtensionCount, uint32_t, enabledExtensionCount);
	DefineSetter_ArrayRefSpecialP(EnabledExtensions, const char* const, enabledExtensions, enabledExtensionCount, ppEnabledExtensionNames);
	DefineSetter_Ref(EnabledFeatures, const VkPhysicalDeviceFeatures, enabledFeature);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ExtensionProperties) {
	StructureClassHeader_NoSType(ExtensionProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(ExtensionProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(LayerProperties) {
	StructureClassHeader_NoSType(LayerProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(LayerProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubmitInfo) {
	StructureClassHeader(SubmitInfo);
	DefineSetter_Copy(WaitSemaphoreCount, uint32_t, waitSemaphoreCount);
	DefineSetter_ArrayRef(WaitSemaphores, const VkSemaphore, waitSemaphores, waitSemaphoreCount);
	DefineSetter_ArrayRefIgnoreC(WaitDstStageMask, const VkPipelineStageFlags, waitDstStageMasks);
	DefineSetter_Copy(CommandBufferCount, uint32_t, commandBufferCount);
	DefineSetter_ArrayRef(CommandBuffers, const VkCommandBuffer, commandBuffers, commandBufferCount);
	DefineSetter_Copy(SignalSemaphoreCount, uint32_t, signalSemaphoreCount);
	DefineSetter_ArrayRef(SignalSemaphores, const VkSemaphore, signalSemaphores, signalSemaphoreCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SubmitInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MappedMemoryRange) {
	StructureClassHeader(MappedMemoryRange, .size = VK_WHOLE_SIZE);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(MappedMemoryRange)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryAllocateInfo) {
	StructureClassHeader(MemoryAllocateInfo);
	DefineSetter_Copy(AllocationSize, VkDeviceSize, allocationSize);
	DefineSetter_Copy(MemoryTypeIndex, uint32_t, memoryTypeIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryAllocateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MemoryRequirements) {
	StructureClassHeader_NoSType(MemoryRequirements);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryRequirements)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SparseMemoryBind) {
	StructureClassHeader_NoSType(SparseMemoryBind);
	DefineSetter_Copy(ResourceOffset, VkDeviceSize, resourceOffset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
	DefineSetter_Copy(Flags, VkSparseMemoryBindFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseMemoryBind)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SparseBufferMemoryBindInfo) {
	StructureClassHeader_NoSType(SparseBufferMemoryBindInfo);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(BindCount, uint32_t, bindCount);
	DefineSetter_ArrayRef(Binds, const VkSparseMemoryBind, binds, bindCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseBufferMemoryBindInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SparseImageOpaqueMemoryBindInfo) {
	StructureClassHeader_NoSType(SparseImageOpaqueMemoryBindInfo);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(BindCount, uint32_t, bindCount);
	DefineSetter_ArrayRef(Binds, const VkSparseMemoryBind, binds, bindCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseImageOpaqueMemoryBindInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ImageSubresource) {
	StructureClassHeader_NoSType(ImageSubresource);
	DefineSetter_Copy(AspectMask, VkImageAspectFlags, aspectMask);
	DefineSetter_Copy(MipLevel, uint32_t, mipLevel);
	DefineSetter_Copy(ArrayLayer, uint32_t, arrayLayer);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageSubresource)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SparseImageMemoryBind) {
	StructureClassHeader_NoSType(SparseImageMemoryBind);
	DefineSetter_Copy(Subresource, VkImageSubresource, subresource);
	DefineSetter_Copy(Offset, VkOffset3D, offset);
	DefineSetter_Copy(Extent, VkExtent3D, extent);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
	DefineSetter_Copy(Flags, VkSparseMemoryBindFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseImageMemoryBind)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SparseImageMemoryBindInfo) {
	StructureClassHeader_NoSType(SparseImageMemoryBindInfo);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(BindCount, uint32_t, bindCount);
	DefineSetter_ArrayRef(Binds, const VkSparseImageMemoryBind, binds, bindCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseImageMemoryBindInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindSparseInfo) {
	StructureClassHeader(BindSparseInfo);
	DefineSetter_Copy(WaitSemaphoreCount, uint32_t, waitSemaphoreCount);
	DefineSetter_ArrayRef(WaitSemaphores, const VkSemaphore, waitSemaphores, waitSemaphoreCount);
	DefineSetter_Copy(BufferBindCount, uint32_t, bufferBindCount);
	DefineSetter_ArrayRef(BufferBinds, const VkSparseBufferMemoryBindInfo, bufferBinds, bufferBindCount);
	DefineSetter_Copy(ImageOpaqueBindCount, uint32_t, imageOpaqueBindCount);
	DefineSetter_ArrayRef(ImageOpaqueBinds, const VkSparseImageOpaqueMemoryBindInfo, imageOpaqueBinds, imageOpaqueBindCount);
	DefineSetter_Copy(ImageBindCount, uint32_t, imageBindCount);
	DefineSetter_ArrayRef(ImageBinds, const VkSparseImageMemoryBindInfo, imageBinds, imageBindCount);
	DefineSetter_Copy(SignalSemaphoreCount, uint32_t, signalSemaphoreCount);
	DefineSetter_ArrayRef(SignalSemaphores, const VkSemaphore, signalSemaphores, signalSemaphoreCount);
};
VK_ENCAPSULATION_STRUCTURE_END(BindSparseInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SparseImageFormatProperties) {
	StructureClassHeader_NoSType(SparseImageFormatProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseImageFormatProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SparseImageMemoryRequirements) {
	StructureClassHeader_NoSType(SparseImageMemoryRequirements);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseImageMemoryRequirements)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FenceCreateInfo) {
	StructureClassHeader(FenceCreateInfo);
	DefineSetter_Copy(Flags, VkFenceCreateFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(FenceCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SemaphoreCreateInfo) {
	StructureClassHeader(SemaphoreCreateInfo);
	DefineSetter_Copy(Flags, VkSemaphoreCreateFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(SemaphoreCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(EventCreateInfo) {
	StructureClassHeader(EventCreateInfo);
	DefineSetter_Copy(Flags, VkEventCreateFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(EventCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueryPoolCreateInfo) {
	StructureClassHeader(QueryPoolCreateInfo);
	DefineSetter_Copy(Flags, VkQueryPoolCreateFlags, flags);
	DefineSetter_Copy(QueryType, VkQueryType, queryType);
	DefineSetter_Copy(QueryCount, uint32_t, queryCount);
	DefineSetter_Copy(PipelineStatistics, VkQueryPipelineStatisticFlags, pipelineStatistics);
};
VK_ENCAPSULATION_STRUCTURE_END(QueryPoolCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferCreateInfo) {
	StructureClassHeader(BufferCreateInfo);
	DefineSetter_Copy(Flags, VkBufferCreateFlags, flags);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(Usage, VkBufferUsageFlags, usage);
	DefineSetter_Copy(SharingMode, VkSharingMode, sharingMode);
	DefineSetter_ArrayRef(QueueFamilyIndices, const uint32_t, queueFamilyIndices, queueFamilyIndexCount, sharingMode = VkSharingMode(bool(queueFamilyIndices)));
};
VK_ENCAPSULATION_STRUCTURE_END(BufferCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferViewCreateInfo) {
	StructureClassHeader(BufferViewCreateInfo, .range = VK_WHOLE_SIZE);
	DefineSetter_Copy(Flags, VkBufferViewCreateFlags, flags);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Range, VkDeviceSize, range);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferViewCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageCreateInfo) {
	StructureClassHeader(ImageCreateInfo, .mipLevels = 1, .arrayLayers = 1, .samples = VK_SAMPLE_COUNT_1_BIT);
	DefineSetter_Copy(Flags, VkImageCreateFlags, flags);
	DefineSetter_Copy(ImageType, VkImageType, imageType);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Extent, VkExtent3D, extent);
	DefineSetter_Copy(MipLevels, uint32_t, mipLevels);
	DefineSetter_Copy(ArrayLayers, uint32_t, arrayLayers);
	DefineSetter_Copy(Samples, VkSampleCountFlagBits, samples);
	DefineSetter_Copy(Tiling, VkImageTiling, tiling);
	DefineSetter_Copy(Usage, VkImageUsageFlags, usage);
	DefineSetter_Copy(SharingMode, VkSharingMode, sharingMode);
	DefineSetter_ArrayRef(QueueFamilyIndices, const uint32_t, queueFamilyIndices, queueFamilyIndexCount, sharingMode = VkSharingMode(bool(queueFamilyIndices)));
	DefineSetter_Copy(InitialLayout, VkImageLayout, initialLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SubresourceLayout) {
	StructureClassHeader_NoSType(SubresourceLayout);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(RowPitch, VkDeviceSize, rowPitch);
	DefineSetter_Copy(ArrayPitch, VkDeviceSize, arrayPitch);
	DefineSetter_Copy(DepthPitch, VkDeviceSize, depthPitch);
};
VK_ENCAPSULATION_STRUCTURE_END(SubresourceLayout)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ComponentMapping) {
	StructureClassHeader_NoSType(ComponentMapping);
	DefineSetter_Copy(R, VkComponentSwizzle, r);
	DefineSetter_Copy(G, VkComponentSwizzle, g);
	DefineSetter_Copy(B, VkComponentSwizzle, b);
	DefineSetter_Copy(A, VkComponentSwizzle, a);
};
VK_ENCAPSULATION_STRUCTURE_END(ComponentMapping)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewCreateInfo) {
	StructureClassHeader(ImageViewCreateInfo);
	DefineSetter_Copy(Flags, VkImageViewCreateFlags, flags);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(ViewType, VkImageViewType, viewType);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Components, VkComponentMapping, components);
	DefineSetter_Copy(SubresourceRange, VkImageSubresourceRange, subresourceRange);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ShaderModuleCreateInfo) {
	StructureClassHeader(ShaderModuleCreateInfo);
	DefineSetter_Copy(Flags, VkShaderModuleCreateFlags, flags);
	DefineSetter_Copy(CodeSize, size_t, codeSize);
	_&  Code(ArrayRef<const uint32_t> code) &  { codeSize = 4 * code.size(); pCode = code; return *this; };
	_&& Code(ArrayRef<const uint32_t> code) && { return std::move(Code(code)); };
};
VK_ENCAPSULATION_STRUCTURE_END(ShaderModuleCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCacheCreateInfo) {
	StructureClassHeader(PipelineCacheCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineCacheCreateFlags, flags);
	DefineSetter_Copy(InitialDataSize, size_t, initialDataSize);
	DefineSetter_ArrayRef(InitialData, const void, initialData, initialDataSize);
	_&  InitialData(const IsNotRangeOrPointer auto& initialData) &  { return InitialData({ sizeof *&initialData, &initialData }); }
	_&& InitialData(const IsNotRangeOrPointer auto& initialData) && { return std::move(InitialData(initialData)); }
	_&  InitialData(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCacheCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SpecializationMapEntry) {
	StructureClassHeader_NoSType(SpecializationMapEntry);
	DefineSetter_Copy(ConstantID, uint32_t, constantID);
	DefineSetter_Copy(Offset, uint32_t, offset);
	DefineSetter_Copy(Size, size_t, size);
};
VK_ENCAPSULATION_STRUCTURE_END(SpecializationMapEntry)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SpecializationInfo) {
	StructureClassHeader_NoSType(SpecializationInfo);
	DefineSetter_Copy(MapEntryCount, uint32_t, mapEntryCount);
	DefineSetter_ArrayRef(MapEntries, const VkSpecializationMapEntry, mapEntries, mapEntryCount);
	DefineSetter_Copy(DataSize, size_t, dataSize);
	DefineSetter_ArrayRef(Data, const void, data, dataSize);
	_&  Data(const IsNotRangeOrPointer auto& data) &  { return Data({ sizeof *&data, &data }); }
	_&& Data(const IsNotRangeOrPointer auto& data) && { return std::move(Data(data)); }
	_&  Data(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(SpecializationInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineShaderStageCreateInfo) {
	StructureClassHeader(PipelineShaderStageCreateInfo, .pName = "main");
	DefineSetter_Copy(Flags, VkPipelineShaderStageCreateFlags, flags);
	DefineSetter_Copy(Stage, VkShaderStageFlagBits, stage);
	DefineSetter_Copy(Module, VkShaderModule, module);
	DefineSetter_ArrayRefIgnoreC(Name, const char, name);
	DefineSetter_Ref(SpecializationInfo, const VkSpecializationInfo, specializationInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineShaderStageCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ComputePipelineCreateInfo) {
	StructureClassHeader(ComputePipelineCreateInfo, .basePipelineIndex = -1);
	DefineSetter_Copy(Flags, VkPipelineCreateFlags, flags);
	DefineSetter_Copy(Stage, VkPipelineShaderStageCreateInfo, stage);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(BasePipelineHandle, VkPipeline, basePipelineHandle);
	DefineSetter_Copy(BasePipelineIndex, int32_t, basePipelineIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(ComputePipelineCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VertexInputBindingDescription) {
	StructureClassHeader_NoSType(VertexInputBindingDescription);
	DefineSetter_Copy(Binding, uint32_t, binding);
	DefineSetter_Copy(Stride, uint32_t, stride);
	DefineSetter_Copy(InputRate, VkVertexInputRate, inputRate);
};
VK_ENCAPSULATION_STRUCTURE_END(VertexInputBindingDescription)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VertexInputAttributeDescription) {
	StructureClassHeader_NoSType(VertexInputAttributeDescription);
	DefineSetter_Copy(Location, uint32_t, location);
	DefineSetter_Copy(Binding, uint32_t, binding);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Offset, uint32_t, offset);
};
VK_ENCAPSULATION_STRUCTURE_END(VertexInputAttributeDescription)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineVertexInputStateCreateInfo) {
	StructureClassHeader(PipelineVertexInputStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineVertexInputStateCreateFlags, flags);
	DefineSetter_Copy(VertexBindingDescriptionCount, uint32_t, vertexBindingDescriptionCount);
	DefineSetter_ArrayRef(VertexBindingDescriptions, const VkVertexInputBindingDescription, vertexBindingDescriptions, vertexBindingDescriptionCount);
	DefineSetter_Copy(VertexAttributeDescriptionCount, uint32_t, vertexAttributeDescriptionCount);
	DefineSetter_ArrayRef(VertexAttributeDescriptions, const VkVertexInputAttributeDescription, vertexAttributeDescriptions, vertexAttributeDescriptionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineVertexInputStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineInputAssemblyStateCreateInfo) {
	StructureClassHeader(PipelineInputAssemblyStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineInputAssemblyStateCreateFlags, flags);
	DefineSetter_Copy(Topology, VkPrimitiveTopology, topology);
	DefineSetter_Copy(PrimitiveRestartEnable, VkBool32, primitiveRestartEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineInputAssemblyStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineTessellationStateCreateInfo) {
	StructureClassHeader(PipelineTessellationStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineTessellationStateCreateFlags, flags);
	DefineSetter_Copy(PatchControlPoints, uint32_t, patchControlPoints);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineTessellationStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(Viewport) {
	StructureClassHeader_NoSType(Viewport);
	DefineSetter_Copy(X, float, x);
	DefineSetter_Copy(Y, float, y);
	DefineSetter_Copy(Width, float, width);
	DefineSetter_Copy(Height, float, height);
	DefineSetter_Copy(MinDepth, float, minDepth);
	DefineSetter_Copy(MaxDepth, float, maxDepth);
};
VK_ENCAPSULATION_STRUCTURE_END(Viewport)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportStateCreateInfo) {
	StructureClassHeader(PipelineViewportStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineViewportStateCreateFlags, flags);
	DefineSetter_Copy(ViewportCount, uint32_t, viewportCount);
	DefineSetter_ArrayRef(Viewports, const VkViewport, viewports, viewportCount);
	DefineSetter_Copy(ScissorCount, uint32_t, scissorCount);
	DefineSetter_ArrayRef(Scissors, const VkRect2D, scissors, scissorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRasterizationStateCreateInfo) {
	StructureClassHeader(PipelineRasterizationStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineRasterizationStateCreateFlags, flags);
	DefineSetter_Copy(DepthClampEnable, VkBool32, depthClampEnable);
	DefineSetter_Copy(RasterizerDiscardEnable, VkBool32, rasterizerDiscardEnable);
	DefineSetter_Copy(PolygonMode, VkPolygonMode, polygonMode);
	DefineSetter_Copy(CullMode, VkCullModeFlags, cullMode);
	DefineSetter_Copy(FrontFace, VkFrontFace, frontFace);
	DefineSetter_Copy(DepthBiasEnable, VkBool32, depthBiasEnable);
	DefineSetter_CopyOptional(DepthBiasConstantFactor, float, depthBiasConstantFactor, depthBiasEnable, true);
	DefineSetter_Copy(DepthBiasClamp, float, depthBiasClamp);
	DefineSetter_CopyOptional(DepthBiasSlopeFactor, float, depthBiasSlopeFactor, depthBiasEnable, true);
	DefineSetter_Copy(LineWidth, float, lineWidth);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRasterizationStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineMultisampleStateCreateInfo) {
	StructureClassHeader(PipelineMultisampleStateCreateInfo, .rasterizationSamples = VK_SAMPLE_COUNT_1_BIT);
	DefineSetter_Copy(Flags, VkPipelineMultisampleStateCreateFlags, flags);
	DefineSetter_Copy(RasterizationSamples, VkSampleCountFlagBits, rasterizationSamples);
	DefineSetter_Copy(SampleShadingEnable, VkBool32, sampleShadingEnable);
	DefineSetter_CopyOptional(MinSampleShading, float, minSampleShading, sampleShadingEnable, true);
	DefineSetter_ArrayRefIgnoreC(SampleMask, const VkSampleMask, sampleMask);
	DefineSetter_Copy(AlphaToCoverageEnable, VkBool32, alphaToCoverageEnable);
	DefineSetter_Copy(AlphaToOneEnable, VkBool32, alphaToOneEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineMultisampleStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(StencilOpState) {
	StructureClassHeader_NoSType(StencilOpState);
	DefineSetter_Copy(FailOp, VkStencilOp, failOp);
	DefineSetter_Copy(PassOp, VkStencilOp, passOp);
	DefineSetter_Copy(DepthFailOp, VkStencilOp, depthFailOp);
	DefineSetter_Copy(CompareOp, VkCompareOp, compareOp);
	DefineSetter_Copy(CompareMask, uint32_t, compareMask);
	DefineSetter_Copy(WriteMask, uint32_t, writeMask);
	DefineSetter_Copy(Reference, uint32_t, reference);
};
VK_ENCAPSULATION_STRUCTURE_END(StencilOpState)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineDepthStencilStateCreateInfo) {
	StructureClassHeader(PipelineDepthStencilStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineDepthStencilStateCreateFlags, flags);
	DefineSetter_Copy(DepthTestEnable, VkBool32, depthTestEnable);
	DefineSetter_Copy(DepthWriteEnable, VkBool32, depthWriteEnable);
	DefineSetter_CopyOptional(DepthCompareOp, VkCompareOp, depthCompareOp, depthTestEnable, true);
	DefineSetter_Copy(DepthBoundsTestEnable, VkBool32, depthBoundsTestEnable);
	DefineSetter_Copy(StencilTestEnable, VkBool32, stencilTestEnable);
	DefineSetter_CopyOptional(Front, VkStencilOpState, front, stencilTestEnable, true);
	DefineSetter_CopyOptional(Back, VkStencilOpState, back, stencilTestEnable, true);
	DefineSetter_CopyOptional(MinDepthBounds, float, minDepthBounds, depthBoundsTestEnable, true);
	DefineSetter_CopyOptional(MaxDepthBounds, float, maxDepthBounds, depthBoundsTestEnable, true);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineDepthStencilStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PipelineColorBlendAttachmentState) {
	StructureClassHeader_NoSType(PipelineColorBlendAttachmentState, .colorWriteMask = 0b1111);
	DefineSetter_Copy(BlendEnable, VkBool32, blendEnable);
	DefineSetter_CopyOptional(SrcColorBlendFactor, VkBlendFactor, srcColorBlendFactor, blendEnable, true);
	DefineSetter_CopyOptional(DstColorBlendFactor, VkBlendFactor, dstColorBlendFactor, blendEnable, true);
	DefineSetter_Copy(ColorBlendOp, VkBlendOp, colorBlendOp);
	DefineSetter_CopyOptional(SrcAlphaBlendFactor, VkBlendFactor, srcAlphaBlendFactor, blendEnable, true);
	DefineSetter_CopyOptional(DstAlphaBlendFactor, VkBlendFactor, dstAlphaBlendFactor, blendEnable, true);
	DefineSetter_Copy(AlphaBlendOp, VkBlendOp, alphaBlendOp);
	DefineSetter_Copy(ColorWriteMask, VkColorComponentFlags, colorWriteMask);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineColorBlendAttachmentState)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineColorBlendStateCreateInfo) {
	StructureClassHeader(PipelineColorBlendStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineColorBlendStateCreateFlags, flags);
	DefineSetter_Copy(LogicOpEnable, VkBool32, logicOpEnable);
	DefineSetter_CopyOptional(LogicOp, VkLogicOp, logicOp, logicOpEnable, true);
	DefineSetter_Copy(AttachmentCount, uint32_t, attachmentCount);
	DefineSetter_ArrayRef(Attachments, const VkPipelineColorBlendAttachmentState, attachments, attachmentCount);
	// float blendConstants[4];
	DefineSetter_ArrayCopy(BlendConstants, float, blendConstants);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineColorBlendStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineDynamicStateCreateInfo) {
	StructureClassHeader(PipelineDynamicStateCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineDynamicStateCreateFlags, flags);
	DefineSetter_Copy(DynamicStateCount, uint32_t, dynamicStateCount);
	DefineSetter_ArrayRef(DynamicStates, const VkDynamicState, dynamicStates, dynamicStateCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineDynamicStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GraphicsPipelineCreateInfo) {
	StructureClassHeader(GraphicsPipelineCreateInfo, .basePipelineIndex = -1);
	DefineSetter_Copy(Flags, VkPipelineCreateFlags, flags);
	DefineSetter_Copy(StageCount, uint32_t, stageCount);
	DefineSetter_ArrayRef(Stages, const VkPipelineShaderStageCreateInfo, stages, stageCount);
	DefineSetter_Ref(VertexInputState, const VkPipelineVertexInputStateCreateInfo, vertexInputState);
	DefineSetter_Ref(InputAssemblyState, const VkPipelineInputAssemblyStateCreateInfo, inputAssemblyState);
	DefineSetter_Ref(TessellationState, const VkPipelineTessellationStateCreateInfo, tessellationState);
	DefineSetter_Ref(ViewportState, const VkPipelineViewportStateCreateInfo, viewportState);
	DefineSetter_Ref(RasterizationState, const VkPipelineRasterizationStateCreateInfo, rasterizationState);
	DefineSetter_Ref(MultisampleState, const VkPipelineMultisampleStateCreateInfo, multisampleState);
	DefineSetter_Ref(DepthStencilState, const VkPipelineDepthStencilStateCreateInfo, depthStencilState);
	DefineSetter_Ref(ColorBlendState, const VkPipelineColorBlendStateCreateInfo, colorBlendState);
	DefineSetter_Ref(DynamicState, const VkPipelineDynamicStateCreateInfo, dynamicState);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(RenderPass, VkRenderPass, renderPass);
	DefineSetter_Copy(Subpass, uint32_t, subpass);
	DefineSetter_Copy(BasePipelineHandle, VkPipeline, basePipelineHandle);
	DefineSetter_Copy(BasePipelineIndex, int32_t, basePipelineIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(GraphicsPipelineCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PushConstantRange) {
	StructureClassHeader_NoSType(PushConstantRange);
	DefineSetter_Copy(StageFlags, VkShaderStageFlags, stageFlags);
	DefineSetter_Copy(Offset, uint32_t, offset);
	DefineSetter_Copy(Size, uint32_t, size);
};
VK_ENCAPSULATION_STRUCTURE_END(PushConstantRange)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineLayoutCreateInfo) {
	StructureClassHeader(PipelineLayoutCreateInfo);
	DefineSetter_Copy(Flags, VkPipelineLayoutCreateFlags, flags);
	DefineSetter_Copy(SetLayoutCount, uint32_t, setLayoutCount);
	DefineSetter_ArrayRef(SetLayouts, const VkDescriptorSetLayout, setLayouts, setLayoutCount);
	DefineSetter_Copy(PushConstantRangeCount, uint32_t, pushConstantRangeCount);
	DefineSetter_ArrayRef(PushConstantRanges, const VkPushConstantRange, pushConstantRanges, pushConstantRangeCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineLayoutCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerCreateInfo) {
	StructureClassHeader(SamplerCreateInfo, .maxLod = VK_LOD_CLAMP_NONE);
	DefineSetter_Copy(Flags, VkSamplerCreateFlags, flags);
	DefineSetter_Copy(MagFilter, VkFilter, magFilter);
	DefineSetter_Copy(MinFilter, VkFilter, minFilter);
	DefineSetter_Copy(MipmapMode, VkSamplerMipmapMode, mipmapMode);
	DefineSetter_Copy(AddressModeU, VkSamplerAddressMode, addressModeU);
	DefineSetter_Copy(AddressModeV, VkSamplerAddressMode, addressModeV);
	DefineSetter_Copy(AddressModeW, VkSamplerAddressMode, addressModeW);
	DefineSetter_Copy(MipLodBias, float, mipLodBias);
	DefineSetter_Copy(AnisotropyEnable, VkBool32, anisotropyEnable);
	DefineSetter_CopyOptional(MaxAnisotropy, float, maxAnisotropy, anisotropyEnable, true);
	DefineSetter_Copy(CompareEnable, VkBool32, compareEnable);
	DefineSetter_CopyOptional(CompareOp, VkCompareOp, compareOp, compareEnable, true);
	DefineSetter_Copy(MinLod, float, minLod);
	DefineSetter_Copy(MaxLod, float, maxLod);
	DefineSetter_Copy(BorderColor, VkBorderColor, borderColor);
	DefineSetter_Copy(UnnormalizedCoordinates, VkBool32, unnormalizedCoordinates);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyDescriptorSet) {
	StructureClassHeader(CopyDescriptorSet);
	DefineSetter_Copy(SrcSet, VkDescriptorSet, srcSet);
	DefineSetter_Copy(SrcBinding, uint32_t, srcBinding);
	DefineSetter_Copy(SrcArrayElement, uint32_t, srcArrayElement);
	DefineSetter_Copy(DstSet, VkDescriptorSet, dstSet);
	DefineSetter_Copy(DstBinding, uint32_t, dstBinding);
	DefineSetter_Copy(DstArrayElement, uint32_t, dstArrayElement);
	DefineSetter_Copy(DescriptorCount, uint32_t, descriptorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyDescriptorSet)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DescriptorBufferInfo) {
	StructureClassHeader_NoSType(DescriptorBufferInfo, .range = VK_WHOLE_SIZE);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Range, VkDeviceSize, range);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorBufferInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DescriptorImageInfo) {
	StructureClassHeader_NoSType(DescriptorImageInfo);
	DefineSetter_Copy(Sampler, VkSampler, sampler);
	DefineSetter_Copy(ImageView, VkImageView, imageView);
	DefineSetter_Copy(ImageLayout, VkImageLayout, imageLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorImageInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DescriptorPoolSize) {
	StructureClassHeader_NoSType(DescriptorPoolSize);
	DefineSetter_Copy(Type, VkDescriptorType, type);
	DefineSetter_Copy(DescriptorCount, uint32_t, descriptorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorPoolSize)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorPoolCreateInfo) {
	StructureClassHeader(DescriptorPoolCreateInfo);
	DefineSetter_Copy(Flags, VkDescriptorPoolCreateFlags, flags);
	DefineSetter_Copy(MaxSets, uint32_t, maxSets);
	DefineSetter_Copy(PoolSizeCount, uint32_t, poolSizeCount);
	DefineSetter_ArrayRef(PoolSizes, const VkDescriptorPoolSize, poolSizes, poolSizeCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorPoolCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetAllocateInfo) {
	StructureClassHeader(DescriptorSetAllocateInfo);
	DefineSetter_Copy(DescriptorPool, VkDescriptorPool, descriptorPool);
	DefineSetter_Copy(DescriptorSetCount, uint32_t, descriptorSetCount);
	DefineSetter_ArrayRef(SetLayouts, const VkDescriptorSetLayout, setLayouts, descriptorSetCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetAllocateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DescriptorSetLayoutBinding) {
	StructureClassHeader_NoSType(DescriptorSetLayoutBinding);
	DefineSetter_Copy(Binding, uint32_t, binding);
	DefineSetter_Copy(DescriptorType, VkDescriptorType, descriptorType);
	DefineSetter_Copy(DescriptorCount, uint32_t, descriptorCount);
	DefineSetter_Copy(StageFlags, VkShaderStageFlags, stageFlags);
	DefineSetter_ArrayRef(ImmutableSamplers, const VkSampler, immutableSamplers, descriptorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetLayoutBinding)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetLayoutCreateInfo) {
	StructureClassHeader(DescriptorSetLayoutCreateInfo);
	DefineSetter_Copy(Flags, VkDescriptorSetLayoutCreateFlags, flags);
	DefineSetter_Copy(BindingCount, uint32_t, bindingCount);
	DefineSetter_ArrayRef(Bindings, const VkDescriptorSetLayoutBinding, bindings, bindingCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetLayoutCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteDescriptorSet) {
	StructureClassHeader(WriteDescriptorSet);
	DefineSetter_Copy(DstSet, VkDescriptorSet, dstSet);
	DefineSetter_Copy(DstBinding, uint32_t, dstBinding);
	DefineSetter_Copy(DstArrayElement, uint32_t, dstArrayElement);
	DefineSetter_Copy(DescriptorType, VkDescriptorType, descriptorType);
	DefineSetter_Copy(DescriptorCount, uint32_t, descriptorCount);
	DefineSetter_ArrayRef(ImageInfo, const VkDescriptorImageInfo, imageInfos, descriptorCount);
	DefineSetter_ArrayRef(BufferInfo, const VkDescriptorBufferInfo, bufferInfos, descriptorCount);
	DefineSetter_ArrayRef(TexelBufferView, const VkBufferView, texelBufferViews, descriptorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(WriteDescriptorSet)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AttachmentDescription) {
	StructureClassHeader_NoSType(AttachmentDescription, .samples = VK_SAMPLE_COUNT_1_BIT);
	DefineSetter_Copy(Flags, VkAttachmentDescriptionFlags, flags);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Samples, VkSampleCountFlagBits, samples);
	DefineSetter_Copy(LoadOp, VkAttachmentLoadOp, loadOp);
	DefineSetter_Copy(StoreOp, VkAttachmentStoreOp, storeOp);
	DefineSetter_Copy(StencilLoadOp, VkAttachmentLoadOp, stencilLoadOp);
	DefineSetter_Copy(StencilStoreOp, VkAttachmentStoreOp, stencilStoreOp);
	DefineSetter_Copy(InitialLayout, VkImageLayout, initialLayout);
	DefineSetter_Copy(FinalLayout, VkImageLayout, finalLayout);

};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentDescription)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AttachmentReference) {
	StructureClassHeader_NoSType(AttachmentReference);
	DefineSetter_Copy(Attachment, uint32_t, attachment);
	DefineSetter_Copy(Layout, VkImageLayout, layout);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentReference)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FramebufferCreateInfo) {
	StructureClassHeader(FramebufferCreateInfo);
	DefineSetter_Copy(Flags, VkFramebufferCreateFlags, flags);
	DefineSetter_Copy(RenderPass, VkRenderPass, renderPass);
	DefineSetter_Copy(AttachmentCount, uint32_t, attachmentCount);
	DefineSetter_ArrayRef(Attachments, const VkImageView, attachments, attachmentCount);
	DefineSetter_Copy(Width, uint32_t, width);
	DefineSetter_Copy(Height, uint32_t, height);
	DefineSetter_Copy(Layers, uint32_t, layers);
};
VK_ENCAPSULATION_STRUCTURE_END(FramebufferCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SubpassDescription) {
	StructureClassHeader_NoSType(SubpassDescription);
	DefineSetter_Copy(Flags, VkSubpassDescriptionFlags, flags);
	DefineSetter_Copy(PipelineBindPoint, VkPipelineBindPoint, pipelineBindPoint);
	DefineSetter_Copy(InputAttachmentCount, uint32_t, inputAttachmentCount);
	DefineSetter_ArrayRef(InputAttachments, const VkAttachmentReference, inputAttachments, inputAttachmentCount);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachments, const VkAttachmentReference, colorAttachments, colorAttachmentCount);
	DefineSetter_ArrayRefIgnoreC(ResolveAttachments, const VkAttachmentReference, resolveAttachments);
	DefineSetter_Ref(DepthStencilAttachment, const VkAttachmentReference, depthStencilAttachment);
	DefineSetter_Copy(PreserveAttachmentCount, uint32_t, preserveAttachmentCount);
	DefineSetter_ArrayRef(PreserveAttachments, const VkAttachmentReference2, preserveAttachments, preserveAttachmentCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassDescription)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SubpassDependency) {
	StructureClassHeader_NoSType(SubpassDependency);
	DefineSetter_Copy(SrcSubpass, uint32_t, srcSubpass);
	DefineSetter_Copy(DstSubpass, uint32_t, dstSubpass);
	DefineSetter_Copy(SrcStageMask, VkPipelineStageFlags, srcStageMask);
	DefineSetter_Copy(DstStageMask, VkPipelineStageFlags, dstStageMask);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags, srcAccessMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags, dstAccessMask);
	DefineSetter_Copy(DependencyFlags, VkDependencyFlags, dependencyFlags);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassDependency)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassCreateInfo) {
	StructureClassHeader(RenderPassCreateInfo);
	DefineSetter_Copy(Flags, VkRenderPassCreateFlags, flags);
	DefineSetter_Copy(AttachmentCount, uint32_t, attachmentCount);
	DefineSetter_ArrayRef(Attachments, const VkAttachmentDescription, attachments, attachmentCount);
	DefineSetter_Copy(SubpassCount, uint32_t, subpassCount);
	DefineSetter_ArrayRef(Subpasses, const VkSubpassDescription, subpasses, subpassCount);
	DefineSetter_Copy(DependencyCount, uint32_t, dependencyCount);
	DefineSetter_ArrayRef(Dependencies, const VkSubpassDependency, dependencies, dependencyCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandPoolCreateInfo) {
	StructureClassHeader(CommandPoolCreateInfo);
	DefineSetter_Copy(Flags, VkCommandPoolCreateFlags, flags);
	DefineSetter_Copy(QueueFamilyIndex, uint32_t, queueFamilyIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandPoolCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferAllocateInfo) {
	StructureClassHeader(CommandBufferAllocateInfo);
	DefineSetter_Copy(CommandPool, VkCommandPool, commandPool);
	DefineSetter_Copy(Level, VkCommandBufferLevel, level);
	DefineSetter_Copy(CommandBufferCount, uint32_t, commandBufferCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferAllocateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferInheritanceInfo) {
	StructureClassHeader(CommandBufferInheritanceInfo);
	DefineSetter_Copy(RenderPass, VkRenderPass, renderPass);
	DefineSetter_Copy(Subpass, uint32_t, subpass);
	DefineSetter_Copy(Framebuffer, VkFramebuffer, framebuffer);
	DefineSetter_Copy(OcclusionQueryEnable, VkBool32, occlusionQueryEnable);
	DefineSetter_CopyOptional(QueryFlags, VkQueryControlFlags, queryFlags, occlusionQueryEnable, true);
	DefineSetter_Copy(PipelineStatistics, VkQueryPipelineStatisticFlags, pipelineStatistics);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferInheritanceInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferBeginInfo) {
	StructureClassHeader(CommandBufferBeginInfo);
	DefineSetter_Copy(Flags, VkCommandBufferUsageFlags, flags);
	DefineSetter_Ref(InheritanceInfo, const VkCommandBufferInheritanceInfo, inheritanceInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferBeginInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BufferCopy) {
	StructureClassHeader_NoSType(BufferCopy);
	DefineSetter_Copy(SrcOffset, VkDeviceSize, srcOffset);
	DefineSetter_Copy(DstOffset, VkDeviceSize, dstOffset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferCopy)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ImageSubresourceLayers) {
	StructureClassHeader_NoSType(ImageSubresourceLayers, .layerCount = VK_REMAINING_ARRAY_LAYERS);
	DefineSetter_Copy(AspectMask, VkImageAspectFlags, aspectMask);
	DefineSetter_Copy(MipLevel, uint32_t, mipLevel);
	DefineSetter_Copy(BaseArrayLayer, uint32_t, baseArrayLayer);
	DefineSetter_Copy(LayerCount, uint32_t, layerCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageSubresourceLayers)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BufferImageCopy) {
	StructureClassHeader_NoSType(BufferImageCopy);
	DefineSetter_Copy(BufferOffset, VkDeviceSize, bufferOffset);
	DefineSetter_Copy(BufferRowLength, uint32_t, bufferRowLength);
	DefineSetter_Copy(BufferImageHeight, uint32_t, bufferImageHeight);
	DefineSetter_Copy(ImageSubresource, VkImageSubresourceLayers, imageSubresource);
	DefineSetter_Copy(ImageOffset, VkOffset3D, imageOffset);
	DefineSetter_Copy(ImageExtent, VkExtent3D, imageExtent);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferImageCopy)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(ClearColorValue) {
	StructureClassHeader_UnionWrapper(ClearColorValue);
	union {
		float    float32[4];
		int32_t  int32[4];
		uint32_t uint32[4];
	};
	constexpr Structure(float r, float g, float b, float a) : float32(r, g, b, a) {}
	constexpr Structure(int32_t r, int32_t g, int32_t b, int32_t a) : int32(r, g, b, a) {}
	constexpr Structure(uint32_t r, uint32_t g, uint32_t b, uint32_t a) : int32(r, g, b, a) {}
};
VK_ENCAPSULATION_STRUCTURE_END(ClearColorValue)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClearDepthStencilValue) {
	StructureClassHeader_NoSType(ClearDepthStencilValue);
	DefineSetter_Copy(Depth, float, depth);
	DefineSetter_Copy(Stencil, uint32_t, stencil);
};
VK_ENCAPSULATION_STRUCTURE_END(ClearDepthStencilValue)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(ClearValue) {
	StructureClassHeader_UnionWrapper(ClearValue);
	union {
		VkClearColorValue        color;
		VkClearDepthStencilValue depthStencil;
	};
	constexpr Structure(const VkClearColorValue& color) : color(color) {};
	constexpr Structure(const VkClearDepthStencilValue& depthStencil) : depthStencil(depthStencil) {};
	constexpr Structure(const ClearColorValue& color) : color(color) {};
	constexpr Structure(const ClearDepthStencilValue& depthStencil) : depthStencil(depthStencil) {};
	constexpr Structure(float r, float g, float b, float a) : color{ .float32 = { r, g, b, a } } {}
	constexpr Structure(int32_t r, int32_t g, int32_t b, int32_t a) : color{ .int32 = { r, g, b, a } } {}
	constexpr Structure(uint32_t r, uint32_t g, uint32_t b, uint32_t a) : color{ .uint32 = { r, g, b, a } } {}
	constexpr Structure(float depth, uint32_t stencil) : depthStencil(depth, stencil) {}
};
VK_ENCAPSULATION_STRUCTURE_END(ClearValue)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClearAttachment) {
	StructureClassHeader_NoSType(ClearAttachment);
	DefineSetter_Copy(AspectMask, VkImageAspectFlags, aspectMask);
	DefineSetter_Copy(ColorAttachment, uint32_t, colorAttachment);
	DefineSetter_Copy(ClearValue, VkClearValue, clearValue);
};
VK_ENCAPSULATION_STRUCTURE_END(ClearAttachment)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClearRect) {
	StructureClassHeader_NoSType(ClearRect, .layerCount = 1);
	DefineSetter_Copy(Rect, VkRect2D, rect);
	DefineSetter_Copy(BaseArrayLayer, uint32_t, baseArrayLayer);
	DefineSetter_Copy(LayerCount, uint32_t, layerCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ClearRect)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ImageBlit) {
	StructureClassHeader_NoSType(ImageBlit);
	DefineSetter_Copy(SrcSubresource, VkImageSubresourceLayers, srcSubresource);
	// VkOffset3D srcOffsets[2];
	DefineSetter_ArrayCopy(SrcOffsets, VkOffset3D, srcOffsets);
	DefineSetter_Copy(DstSubresource, VkImageSubresourceLayers, dstSubresource);
	// VkOffset3D dstOffsets[2];
	DefineSetter_ArrayCopy(DstOffsets, VkOffset3D, dstOffsets);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageBlit)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ImageCopy) {
	StructureClassHeader_NoSType(ImageCopy);
	DefineSetter_Copy(SrcSubresource, VkImageSubresourceLayers, srcSubresource);
	DefineSetter_Copy(SrcOffset, VkOffset3D, srcOffset);
	DefineSetter_Copy(DstSubresource, VkImageSubresourceLayers, dstSubresource);
	DefineSetter_Copy(DstOffset, VkOffset3D, dstOffset);
	DefineSetter_Copy(Extent, VkExtent3D, extent);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageCopy)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ImageResolve) {
	StructureClassHeader_NoSType(ImageResolve);
	DefineSetter_Copy(SrcSubresource, VkImageSubresourceLayers, srcSubresource);
	DefineSetter_Copy(SrcOffset, VkOffset3D, srcOffset);
	DefineSetter_Copy(DstSubresource, VkImageSubresourceLayers, dstSubresource);
	DefineSetter_Copy(DstOffset, VkOffset3D, dstOffset);
	DefineSetter_Copy(Extent, VkExtent3D, extent);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageResolve)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassBeginInfo) {
	StructureClassHeader(RenderPassBeginInfo);
	DefineSetter_Copy(RenderPass, VkRenderPass, renderPass);
	DefineSetter_Copy(Framebuffer, VkFramebuffer, framebuffer);
	DefineSetter_Copy(RenderArea, VkRect2D, renderArea);
	DefineSetter_Copy(ClearValueCount, uint32_t, clearValueCount);
	DefineSetter_ArrayRef(ClearValues, const VkClearValue, clearValues, clearValueCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassBeginInfo)

inline VkResult CreateInstance(const VkInstanceCreateInfo& createInfo, HandleRef<VkInstance> instance) {
	struct _ : InstanceContext {
		using InstanceContext::Instance;
	};
	if (_::Instance() != VK_NULL_HANDLE)
		std::abort();
	VkResult result = VK_ENCAPSULATION_DISPATCH vkCreateInstance(&createInfo, ThreadContext::PAllocator(), &instance);
	if (result == VK_SUCCESS)
		_::Instance(instance),
		volkLoadInstance(instance);
	return result;
}
DefineRaiiFunction_ResultL(VkResult, CreateInstance, InstanceCreateInfo, HandleRef<VkInstance>, instance);

inline void DestroyInstance(HandleRef<VkInstance> instance, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	struct _ : InstanceContext {
		using InstanceContext::Instance;
	};
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkDestroyInstance(instance, &allocator);
	if (_::Instance() == instance)
		_::Instance({});
	instance = VK_NULL_HANDLE;
}

inline VkResult EnumeratePhysicalDevices(uint32_t& physicalDeviceCount, HandleArrayRef<VkPhysicalDevice> physicalDevices = HandleArrayRef<VkPhysicalDevice>{}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkEnumeratePhysicalDevices(InstanceContext::Instance(), &physicalDeviceCount, physicalDevices);
}
inline VkResult EnumeratePhysicalDevices(IsDynamicArray<VkPhysicalDevice> auto& physicalDevices) {
	uint32_t count = 0;
	VkResult result = EnumeratePhysicalDevices(count);
	if (result == VK_SUCCESS)
		physicalDevices.resize(count),
		result = EnumeratePhysicalDevices(count, physicalDevices);
	return result;
}

inline void GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures& features) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceFeatures(physicalDevice, &features);
}
inline void GetPhysicalDeviceFeatures(VkPhysicalDeviceFeatures& features) {
	GetPhysicalDeviceFeatures(DeviceContext::PhysicalDevice(), features);
}

inline void GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties& formatProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &formatProperties);
}
inline void GetPhysicalDeviceFormatProperties(VkFormat format, VkFormatProperties& formatProperties) {
	GetPhysicalDeviceFormatProperties(DeviceContext::PhysicalDevice(), format, formatProperties);
}

inline VkResult GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties& imageFormatProperties) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, &imageFormatProperties);
}
inline VkResult GetPhysicalDeviceImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties& imageFormatProperties) {
	return GetPhysicalDeviceImageFormatProperties(DeviceContext::PhysicalDevice(), format, type, tiling, usage, flags, imageFormatProperties);
}

inline void GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties& properties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceProperties(physicalDevice, &properties);
}
inline void GetPhysicalDeviceProperties(VkPhysicalDeviceProperties& properties) {
	GetPhysicalDeviceProperties(DeviceContext::PhysicalDevice(), properties);
}

inline void GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t& queueFamilyPropertyCount, ArrayRef<VkQueueFamilyProperties> queueFamilyProperties = {}) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyPropertyCount, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, IsDynamicArray<VkQueueFamilyProperties> auto& queueFamilyProperties) {
	uint32_t count = 0;
	GetPhysicalDeviceQueueFamilyProperties(physicalDevice, count);
	queueFamilyProperties.resize(count);
	GetPhysicalDeviceQueueFamilyProperties(physicalDevice, count, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties(uint32_t& queueFamilyPropertyCount, ArrayRef<VkQueueFamilyProperties> queueFamilyProperties = {}) {
	GetPhysicalDeviceQueueFamilyProperties(DeviceContext::PhysicalDevice(), queueFamilyPropertyCount, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties(IsDynamicArray<VkQueueFamilyProperties> auto& queueFamilyProperties) {
	GetPhysicalDeviceQueueFamilyProperties(DeviceContext::PhysicalDevice(), queueFamilyProperties);
}

inline void GetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties& memoryProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memoryProperties);
}
inline void GetPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties& memoryProperties) {
	GetPhysicalDeviceMemoryProperties(DeviceContext::PhysicalDevice(), memoryProperties);
}

inline PFN_vkVoidFunction GetInstanceProcAddr(ArrayRef<const char> name) {
	return VK_ENCAPSULATION_DISPATCH vkGetInstanceProcAddr(InstanceContext::Instance(), name);
}

inline PFN_vkVoidFunction GetDeviceProcAddr(ArrayRef<const char> name) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetDeviceProcAddr(DeviceContext::Device(), name);
}

inline VkResult CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo& createInfo, HandleRef<VkDevice> device, VolkDeviceTable& functionTable) {
	struct _ : DeviceContext {
		using DeviceContext::PhysicalDevice;
		using DeviceContext::Device;
		using DeviceContext::FunctionTable;
	};
	if (_::Device() != VK_NULL_HANDLE)
		std::abort();
	VkResult result = VK_ENCAPSULATION_INSTANCE_DISPATCH vkCreateDevice(physicalDevice, &createInfo, ThreadContext::PAllocator(), &device);
	if (result == VK_SUCCESS)
		_::PhysicalDevice(physicalDevice),
		_::Device(device),
	#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
		volkLoadDeviceTable(&functionTable, device),
		_::FunctionTable(functionTable);
	#else
		volkLoadDevice(device);
	#endif
	return result;
}
#ifndef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
inline VkResult CreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo& createInfo, HandleRef<VkDevice> device) {
	VolkDeviceTable functionTable;
	return CreateDevice(physicalDevice, createInfo, device, functionTable);
}
#endif

inline void DestroyDevice(HandleRef<VkDevice> device, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	struct _ : DeviceContext {
		using DeviceContext::PhysicalDevice;
		using DeviceContext::Device;
		using DeviceContext::FunctionTable;
	};
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyDevice(device, &allocator);
	if (_::Device() == device)
		_::PhysicalDevice({}),
		_::Device({}),
		_::FunctionTable({});
	device = VK_NULL_HANDLE;
}

inline VkResult EnumerateInstanceExtensionProperties(ArrayRef<const char> layerName, uint32_t& propertyCount, ArrayRef<VkExtensionProperties> properties = {}) {
	return VK_ENCAPSULATION_DISPATCH vkEnumerateInstanceExtensionProperties(layerName, &propertyCount, properties);
}
inline VkResult EnumerateInstanceExtensionProperties(ArrayRef<const char> layerName, IsDynamicArray<VkExtensionProperties> auto& properties) {
	uint32_t count = 0;
	VkResult result = EnumerateInstanceExtensionProperties(layerName, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = EnumerateInstanceExtensionProperties(layerName, count, properties);
	return result;
}

inline VkResult EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, ArrayRef<const char> layerName, uint32_t& propertyCount, ArrayRef<VkExtensionProperties> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkEnumerateDeviceExtensionProperties(physicalDevice, layerName, &propertyCount, properties);
}
inline VkResult EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, ArrayRef<const char> layerName, IsDynamicArray<VkExtensionProperties> auto& properties) {
	uint32_t count = 0;
	VkResult result = EnumerateDeviceExtensionProperties(physicalDevice, layerName, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = EnumerateDeviceExtensionProperties(physicalDevice, layerName, count, properties);
	return result;
}
inline VkResult EnumerateDeviceExtensionProperties(ArrayRef<const char> layerName, uint32_t& propertyCount, ArrayRef<VkExtensionProperties> properties = {}) {
	return EnumerateDeviceExtensionProperties(DeviceContext::PhysicalDevice(), layerName, propertyCount, properties);
}
inline VkResult EnumerateDeviceExtensionProperties(ArrayRef<const char> layerName, IsDynamicArray<VkExtensionProperties> auto& properties) {
	return EnumerateDeviceExtensionProperties(DeviceContext::PhysicalDevice(), layerName, properties);
}

inline VkResult EnumerateInstanceLayerProperties(uint32_t& propertyCount, ArrayRef<VkLayerProperties> properties = {}) {
	return VK_ENCAPSULATION_DISPATCH vkEnumerateInstanceLayerProperties(&propertyCount, properties);
}
inline VkResult EnumerateInstanceLayerProperties(IsDynamicArray<VkLayerProperties> auto& properties) {
	uint32_t count = 0;
	VkResult result = EnumerateInstanceLayerProperties(count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = EnumerateInstanceLayerProperties(count, properties);
	return result;
}

inline void GetDeviceQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, HandleRef<VkQueue> queue) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceQueue(DeviceContext::Device(), queueFamilyIndex, queueIndex, &queue);
	if (ThreadContext::Queue() == VK_NULL_HANDLE)
		ThreadContext::Queue(queue);
}

inline VkResult QueueSubmit(VkQueue queue, ArrayRef<const VkSubmitInfo> submits, VkFence fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkQueueSubmit(queue, submits.size(), submits, fence);
}
inline VkResult QueueSubmit(ArrayRef<const VkSubmitInfo> submits, VkFence fence) {
	return QueueSubmit(ThreadContext::Queue(), submits, fence);
}
DefineRaiiFunction_ResultL(VkResult, QueueSubmit, SubmitInfo, VkFence, fence);

inline VkResult QueueWaitIdle(VkQueue queue = ThreadContext::Queue()) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkQueueWaitIdle(queue);
}

inline VkResult DeviceWaitIdle(VkDevice device = DeviceContext::Device()) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkDeviceWaitIdle(device);
}

inline VkResult AllocateMemory(const VkMemoryAllocateInfo& allocateInfo, HandleRef<VkDeviceMemory> memory) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkAllocateMemory(DeviceContext::Device(), &allocateInfo, ThreadContext::PAllocator(), &memory);
}
DefineRaiiFunction_ResultL(VkResult, AllocateMemory, MemoryAllocateInfo, HandleRef<VkDeviceMemory>, memory);

inline void FreeMemory(HandleRef<VkDeviceMemory> memory, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkFreeMemory(DeviceContext::Device(), memory, &allocator);
	memory = VK_NULL_HANDLE;
}

inline VkResult MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void*& pData) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkMapMemory(DeviceContext::Device(), memory, offset, size, flags, &pData);
}

inline void UnmapMemory(VkDeviceMemory memory) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkUnmapMemory(DeviceContext::Device(), memory);
}

inline VkResult FlushMappedMemoryRanges(ArrayRef<const VkMappedMemoryRange> memoryRanges) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkFlushMappedMemoryRanges(DeviceContext::Device(), memoryRanges.size(), memoryRanges);
}
DefineRaiiFunction_Result(VkResult, FlushMappedMemoryRanges, MappedMemoryRange);

inline VkResult InvalidateMappedMemoryRanges(ArrayRef<const VkMappedMemoryRange> memoryRanges) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkInvalidateMappedMemoryRanges(DeviceContext::Device(), memoryRanges.size(), memoryRanges);
}
DefineRaiiFunction_Result(VkResult, InvalidateMappedMemoryRanges, MappedMemoryRange);

inline void GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize& committedMemoryInBytes) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceMemoryCommitment(DeviceContext::Device(), memory, &committedMemoryInBytes);
}

inline VkResult BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindBufferMemory(DeviceContext::Device(), buffer, memory, memoryOffset);
}

inline VkResult BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindImageMemory(DeviceContext::Device(), image, memory, memoryOffset);
}

inline void GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferMemoryRequirements(DeviceContext::Device(), buffer, &memoryRequirements);
}

inline void GetImageMemoryRequirements(VkImage image, VkMemoryRequirements& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageMemoryRequirements(DeviceContext::Device(), image, &memoryRequirements);
}

inline void GetImageSparseMemoryRequirements(VkImage image, uint32_t& sparseMemoryRequirementCount, ArrayRef<VkSparseImageMemoryRequirements> sparseMemoryRequirements = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageSparseMemoryRequirements(DeviceContext::Device(), image, &sparseMemoryRequirementCount, sparseMemoryRequirements);
}
inline void GetImageSparseMemoryRequirements(VkImage image, IsDynamicArray<VkSparseImageMemoryRequirements> auto& sparseMemoryRequirements) {
	uint32_t count = 0;
	GetImageSparseMemoryRequirements(image, count);
	sparseMemoryRequirements.resize(count);
	GetImageSparseMemoryRequirements(image, count, sparseMemoryRequirements);
}

inline void GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t& propertyCount, ArrayRef<VkSparseImageFormatProperties> properties = {}) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, &propertyCount, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, IsDynamicArray<VkSparseImageFormatProperties> auto& properties) {
	uint32_t count = 0;
	GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, count);
	properties.resize(count);
	GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, count, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t& propertyCount, ArrayRef<VkSparseImageFormatProperties> properties = {}) {
	GetPhysicalDeviceSparseImageFormatProperties(DeviceContext::PhysicalDevice(), format, type, samples, usage, tiling, propertyCount, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, IsDynamicArray<VkSparseImageFormatProperties> auto& properties) {
	GetPhysicalDeviceSparseImageFormatProperties(DeviceContext::PhysicalDevice(), format, type, samples, usage, tiling, properties);
}

inline VkResult QueueBindSparse(VkQueue queue, ArrayRef<const VkBindSparseInfo> bindInfos, VkFence fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkQueueBindSparse(queue, bindInfos.size(), bindInfos, fence);
}
inline VkResult QueueBindSparse(ArrayRef<const VkBindSparseInfo> bindInfos, VkFence fence) {
	return QueueBindSparse(ThreadContext::Queue(), bindInfos, fence);
}
DefineRaiiFunction_ResultL(VkResult, QueueBindSparse, BindSparseInfo, VkFence, fence);

inline VkResult CreateFence(const VkFenceCreateInfo& createInfo, HandleRef<VkFence> fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateFence(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &fence);
}
DefineRaiiFunction_ResultL(VkResult, CreateFence, FenceCreateInfo, HandleRef<VkFence>, fence);

inline void DestroyFence(HandleRef<VkFence> fence, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyFence(DeviceContext::Device(), fence, &allocator);
	fence = VK_NULL_HANDLE;
}

inline VkResult ResetFences(ArrayRef<const VkFence> fences) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkResetFences(DeviceContext::Device(), fences.size(), fences);
}

inline VkResult GetFenceStatus(VkFence fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetFenceStatus(DeviceContext::Device(), fence);
}

inline VkResult WaitForFences(ArrayRef<const VkFence> fences, VkBool32 waitAll, uint64_t timeout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkWaitForFences(DeviceContext::Device(), fences.size(), fences, waitAll, timeout);
}

inline VkResult CreateSemaphore(const VkSemaphoreCreateInfo& createInfo, HandleRef<VkSemaphore> semaphore) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateSemaphore(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &semaphore);
}
DefineRaiiFunction_ResultL(VkResult, CreateSemaphore, SemaphoreCreateInfo, HandleRef<VkSemaphore>, semaphore);

inline void DestroySemaphore(HandleRef<VkSemaphore> semaphore, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroySemaphore(DeviceContext::Device(), semaphore, &allocator);
	semaphore = VK_NULL_HANDLE;
}

inline VkResult CreateEvent(const VkEventCreateInfo& createInfo, HandleRef<VkEvent> event) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateEvent(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &event);
}
DefineRaiiFunction_ResultL(VkResult, CreateEvent, EventCreateInfo, HandleRef<VkEvent>, event);

inline void DestroyEvent(HandleRef<VkEvent> event, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyEvent(DeviceContext::Device(), event, &allocator);
	event = VK_NULL_HANDLE;
}

inline VkResult GetEventStatus(VkEvent event) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetEventStatus(DeviceContext::Device(), event);
}

inline VkResult SetEvent(VkEvent event) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkSetEvent(DeviceContext::Device(), event);
}

inline VkResult ResetEvent(VkEvent event) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkResetEvent(DeviceContext::Device(), event);
}

inline VkResult CreateQueryPool(const VkQueryPoolCreateInfo& createInfo, HandleRef<VkQueryPool> queryPool) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateQueryPool(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &queryPool);
}
DefineRaiiFunction_ResultL(VkResult, CreateQueryPool, QueryPoolCreateInfo, HandleRef<VkQueryPool>, queryPool);

inline void DestroyQueryPool(HandleRef<VkQueryPool> queryPool, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyQueryPool(DeviceContext::Device(), queryPool, &allocator);
	queryPool = VK_NULL_HANDLE;
}

inline VkResult GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, ArrayRef<void> data, VkDeviceSize stride, VkQueryResultFlags flags) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetQueryPoolResults(DeviceContext::Device(), queryPool, firstQuery, queryCount, data.size(), data, stride, flags);
}
inline VkResult GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, IsNotRangeOrPointer auto& data, VkDeviceSize stride, VkQueryResultFlags flags) {
	return GetQueryPoolResults(queryPool, firstQuery, queryCount, { sizeof *&data, &data }, stride, flags);
}

inline VkResult CreateBuffer(const VkBufferCreateInfo& createInfo, HandleRef<VkBuffer> buffer) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateBuffer(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &buffer);
}
DefineRaiiFunction_ResultL(VkResult, CreateBuffer, BufferCreateInfo, HandleRef<VkBuffer>, buffer);

inline void DestroyBuffer(HandleRef<VkBuffer> buffer, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyBuffer(DeviceContext::Device(), buffer, &allocator);
	buffer = VK_NULL_HANDLE;
}

inline VkResult CreateBufferView(const VkBufferViewCreateInfo& createInfo, HandleRef<VkBufferView> view) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateBufferView(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &view);
}
DefineRaiiFunction_ResultL(VkResult, CreateBufferView, BufferViewCreateInfo, HandleRef<VkBufferView>, view);

inline void DestroyBufferView(HandleRef<VkBufferView> bufferView, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyBufferView(DeviceContext::Device(), bufferView, &allocator);
	bufferView = VK_NULL_HANDLE;
}

inline VkResult CreateImage(const VkImageCreateInfo& createInfo, HandleRef<VkImage> image) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateImage(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &image);
}
DefineRaiiFunction_ResultL(VkResult, CreateImage, ImageCreateInfo, HandleRef<VkImage>, image);

inline void DestroyImage(HandleRef<VkImage> image, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyImage(DeviceContext::Device(), image, &allocator);
	image = VK_NULL_HANDLE;
}

inline void GetImageSubresourceLayout(VkImage image, const VkImageSubresource& subresource, VkSubresourceLayout& layout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageSubresourceLayout(DeviceContext::Device(), image, &subresource, &layout);
}

inline VkResult CreateImageView(const VkImageViewCreateInfo& createInfo, HandleRef<VkImageView> view) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateImageView(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &view);
}
DefineRaiiFunction_ResultL(VkResult, CreateImageView, ImageViewCreateInfo, HandleRef<VkImageView>, view);

inline void DestroyImageView(HandleRef<VkImageView> imageView, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyImageView(DeviceContext::Device(), imageView, &allocator);
	imageView = VK_NULL_HANDLE;
}

inline VkResult CreateShaderModule(const VkShaderModuleCreateInfo& createInfo, HandleRef<VkShaderModule> shaderModule) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateShaderModule(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &shaderModule);
}
DefineRaiiFunction_ResultL(VkResult, CreateShaderModule, ShaderModuleCreateInfo, HandleRef<VkShaderModule>, shaderModule);

inline void DestroyShaderModule(HandleRef<VkShaderModule> shaderModule, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyShaderModule(DeviceContext::Device(), shaderModule, &allocator);
	shaderModule = VK_NULL_HANDLE;
}

inline VkResult CreatePipelineCache(const VkPipelineCacheCreateInfo& createInfo, HandleRef<VkPipelineCache> pipelineCache) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreatePipelineCache(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &pipelineCache);
}
DefineRaiiFunction_ResultL(VkResult, CreatePipelineCache, PipelineCacheCreateInfo, HandleRef<VkPipelineCache>, pipelineCache);

inline void DestroyPipelineCache(HandleRef<VkPipelineCache> pipelineCache, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyPipelineCache(DeviceContext::Device(), pipelineCache, &allocator);
	pipelineCache = VK_NULL_HANDLE;
}

inline VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, size_t& dataSize, ArrayRef<void> data = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineCacheData(DeviceContext::Device(), pipelineCache, &dataSize, data);
}
inline VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, size_t& dataSize, IsNotRangeOrPointer auto& data) {
	return GetPipelineCacheData(pipelineCache, dataSize, { 0, &data });
}
inline VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, IsDynamicByteArray auto& data) {
	size_t size = 0;
	VkResult result = GetPipelineCacheData(pipelineCache, size);
	if (result == VK_SUCCESS)
		data.resize(size),
		result = GetPipelineCacheData(pipelineCache, size, data);
	return result;
}

inline VkResult MergePipelineCaches(VkPipelineCache dstCache, ArrayRef<const VkPipelineCache> srcCaches) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkMergePipelineCaches(DeviceContext::Device(), dstCache, srcCaches.size(), srcCaches);
}

inline VkResult CreateGraphicsPipelines(VkPipelineCache pipelineCache, ArrayRef<const VkGraphicsPipelineCreateInfo> createInfos, HandleArrayRef<VkPipeline> pipelines) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateGraphicsPipelines(DeviceContext::Device(), pipelineCache, createInfos.size(), createInfos, ThreadContext::PAllocator(), pipelines);
}

inline VkResult CreateComputePipelines(VkPipelineCache pipelineCache, ArrayRef<const VkComputePipelineCreateInfo> createInfos, HandleArrayRef<VkPipeline> pipelines) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateComputePipelines(DeviceContext::Device(), pipelineCache, createInfos.size(), createInfos, ThreadContext::PAllocator(), pipelines);
}

inline void DestroyPipeline(HandleRef<VkPipeline> pipeline, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyPipeline(DeviceContext::Device(), pipeline, &allocator);
	pipeline = VK_NULL_HANDLE;
}

inline VkResult CreatePipelineLayout(const VkPipelineLayoutCreateInfo& createInfo, HandleRef<VkPipelineLayout> pipelineLayout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreatePipelineLayout(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &pipelineLayout);
}
DefineRaiiFunction_ResultL(VkResult, CreatePipelineLayout, PipelineLayoutCreateInfo, HandleRef<VkPipelineLayout>, pipelineLayout);

inline void DestroyPipelineLayout(HandleRef<VkPipelineLayout> pipelineLayout, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyPipelineLayout(DeviceContext::Device(), pipelineLayout, &allocator);
	pipelineLayout = VK_NULL_HANDLE;
}

inline VkResult CreateSampler(const VkSamplerCreateInfo& createInfo, HandleRef<VkSampler> sampler) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateSampler(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &sampler);
}
DefineRaiiFunction_ResultL(VkResult, CreateSampler, SamplerCreateInfo, HandleRef<VkSampler>, sampler);

inline void DestroySampler(HandleRef<VkSampler> sampler, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroySampler(DeviceContext::Device(), sampler, &allocator);
	sampler = VK_NULL_HANDLE;
}

inline VkResult CreateDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo& createInfo, HandleRef<VkDescriptorSetLayout> setLayout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateDescriptorSetLayout(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &setLayout);
}
DefineRaiiFunction_ResultL(VkResult, CreateDescriptorSetLayout, DescriptorSetLayoutCreateInfo, HandleRef<VkDescriptorSetLayout>, descriptorSetLayout);

inline void DestroyDescriptorSetLayout(HandleRef<VkDescriptorSetLayout> descriptorSetLayout, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyDescriptorSetLayout(DeviceContext::Device(), descriptorSetLayout, &allocator);
	descriptorSetLayout = VK_NULL_HANDLE;
}

inline VkResult CreateDescriptorPool(const VkDescriptorPoolCreateInfo& createInfo, HandleRef<VkDescriptorPool> descriptorPool) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateDescriptorPool(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &descriptorPool);
}
DefineRaiiFunction_ResultL(VkResult, CreateDescriptorPool, DescriptorPoolCreateInfo, HandleRef<VkDescriptorPool>, descriptorPool);

inline void DestroyDescriptorPool(HandleRef<VkDescriptorPool> descriptorPool, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyDescriptorPool(DeviceContext::Device(), descriptorPool, &allocator);
	descriptorPool = VK_NULL_HANDLE;
}

inline VkResult ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkResetDescriptorPool(DeviceContext::Device(), descriptorPool, flags);
}

inline VkResult AllocateDescriptorSets(const VkDescriptorSetAllocateInfo& allocateInfo, HandleArrayRef<VkDescriptorSet> descriptorSets) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkAllocateDescriptorSets(DeviceContext::Device(), &allocateInfo, descriptorSets);
}
DefineRaiiFunction_ResultL(VkResult, AllocateDescriptorSets, DescriptorSetAllocateInfo, TemplateTypeName(HandleArrayRef, VkDescriptorSet), descriptorSets);

inline VkResult FreeDescriptorSets(VkDescriptorPool descriptorPool, HandleArrayRef<VkDescriptorSet> descriptorSets) {
	VkResult result = VK_ENCAPSULATION_DEVICE_DISPATCH vkFreeDescriptorSets(DeviceContext::Device(), descriptorPool, descriptorSets.size(), descriptorSets);
	if (result == VK_SUCCESS)
		for (auto& i : descriptorSets)
			i = VK_NULL_HANDLE;
	return result;
}

inline void UpdateDescriptorSets(ArrayRef<const VkWriteDescriptorSet> descriptorWrites, ArrayRef<const VkCopyDescriptorSet> descriptorCopies = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkUpdateDescriptorSets(DeviceContext::Device(), descriptorWrites.size(), descriptorWrites, descriptorCopies.size(), descriptorCopies);
}

inline VkResult CreateFramebuffer(const VkFramebufferCreateInfo& createInfo, HandleRef<VkFramebuffer> framebuffer) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateFramebuffer(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &framebuffer);
}
DefineRaiiFunction_ResultL(VkResult, CreateFramebuffer, FramebufferCreateInfo, HandleRef<VkFramebuffer>, framebuffer);

inline void DestroyFramebuffer(HandleRef<VkFramebuffer> framebuffer, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyFramebuffer(DeviceContext::Device(), framebuffer, &allocator);
	framebuffer = VK_NULL_HANDLE;
}

inline VkResult CreateRenderPass(const VkRenderPassCreateInfo& createInfo, HandleRef<VkRenderPass> renderPass) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateRenderPass(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &renderPass);
}
DefineRaiiFunction_ResultL(VkResult, CreateRenderPass, RenderPassCreateInfo, HandleRef<VkRenderPass>, renderPasss);

inline void DestroyRenderPass(HandleRef<VkRenderPass> renderPass, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyRenderPass(DeviceContext::Device(), renderPass, &allocator);
	renderPass = VK_NULL_HANDLE;
}

inline void GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D& granularity) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRenderAreaGranularity(DeviceContext::Device(), renderPass, &granularity);
}

inline VkResult CreateCommandPool(const VkCommandPoolCreateInfo& createInfo, HandleRef<VkCommandPool> commandPool) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateCommandPool(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &commandPool);
}
DefineRaiiFunction_ResultL(VkResult, CreateCommandPool, CommandPoolCreateInfo, HandleRef<VkCommandPool>, commandPool);

inline void DestroyCommandPool(HandleRef<VkCommandPool> commandPool, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyCommandPool(DeviceContext::Device(), commandPool, &allocator);
	commandPool = VK_NULL_HANDLE;
}

inline VkResult ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkResetCommandPool(DeviceContext::Device(), commandPool, flags);
}

inline VkResult AllocateCommandBuffers(const VkCommandBufferAllocateInfo& allocateInfo, HandleArrayRef<VkCommandBuffer> commandBuffers) {
	if (allocateInfo.commandBufferCount != 0)
		return VK_ENCAPSULATION_DEVICE_DISPATCH vkAllocateCommandBuffers(DeviceContext::Device(), &allocateInfo, commandBuffers);
	VkCommandBufferAllocateInfo info = allocateInfo;
	info.commandBufferCount = commandBuffers.size();
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkAllocateCommandBuffers(DeviceContext::Device(), &info, commandBuffers);
}
DefineRaiiFunction_ResultL(VkResult, AllocateCommandBuffers, CommandBufferAllocateInfo, TemplateTypeName(HandleArrayRef, VkCommandBuffer), commandBuffers);

inline void FreeCommandBuffers(VkCommandPool commandPool, HandleArrayRef<VkCommandBuffer> commandBuffers) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkFreeCommandBuffers(DeviceContext::Device(), commandPool, commandBuffers.size(), commandBuffers);
	for (auto& i : commandBuffers)
		i = VK_NULL_HANDLE;
}

inline VkResult BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo& beginInfo) {
	struct _ : ThreadContext {
		using ThreadContext::CommandBuffer;
	};
	VkResult result = VK_ENCAPSULATION_DEVICE_DISPATCH vkBeginCommandBuffer(commandBuffer, &beginInfo);
	if (result == VK_SUCCESS)
		_::CommandBuffer(commandBuffer);
	return result;
}
DefineRaiiFunction_ResultR(VkResult, BeginCommandBuffer, VkCommandBuffer, commandBuffer, CommandBufferBeginInfo);

inline VkResult EndCommandBuffer() {
	struct _ : ThreadContext {
		using ThreadContext::CommandBuffer;
	};
	VkResult result = VK_ENCAPSULATION_DEVICE_DISPATCH vkEndCommandBuffer(ThreadContext::CommandBuffer());
	if (result == VK_SUCCESS)
		_::CommandBuffer(VK_NULL_HANDLE);
	return result;
}

inline VkResult ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkResetCommandBuffer(commandBuffer, flags);
}

inline void CmdBindPipeline(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindPipeline(ThreadContext::CommandBuffer(), pipelineBindPoint, pipeline);
}

inline void CmdSetViewport(uint32_t firstViewport, ArrayRef<const VkViewport> viewports) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetViewport(ThreadContext::CommandBuffer(), firstViewport, viewports.size(), viewports);
}

inline void CmdSetScissor(uint32_t firstScissor, ArrayRef<const VkRect2D> scissors) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetScissor(ThreadContext::CommandBuffer(), firstScissor, scissors.size(), scissors);
}

inline void CmdSetLineWidth(float lineWidth) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLineWidth(ThreadContext::CommandBuffer(), lineWidth);
}

inline void CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthBias(ThreadContext::CommandBuffer(), depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

inline void CmdSetBlendConstants(ArrayRef<const float> blendConstants) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetBlendConstants(ThreadContext::CommandBuffer(), blendConstants);
}

inline void CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthBounds(ThreadContext::CommandBuffer(), minDepthBounds, maxDepthBounds);
}

inline void CmdSetStencilCompareMask(VkStencilFaceFlags faceMask, uint32_t compareMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetStencilCompareMask(ThreadContext::CommandBuffer(), faceMask, compareMask);
}

inline void CmdSetStencilWriteMask(VkStencilFaceFlags faceMask, uint32_t writeMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetStencilWriteMask(ThreadContext::CommandBuffer(), faceMask, writeMask);
}

inline void CmdSetStencilReference(VkStencilFaceFlags faceMask, uint32_t reference) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetStencilReference(ThreadContext::CommandBuffer(), faceMask, reference);
}

inline void CmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, ArrayRef<const VkDescriptorSet> descriptorSets, ArrayRef<const uint32_t> dynamicOffsets) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindDescriptorSets(ThreadContext::CommandBuffer(), pipelineBindPoint, layout, firstSet, descriptorSets.size(), descriptorSets, dynamicOffsets.size(), dynamicOffsets);
}

inline void CmdBindIndexBuffer(VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindIndexBuffer(ThreadContext::CommandBuffer(), buffer, offset, indexType);
}

inline void CmdBindVertexBuffers(uint32_t firstBinding, ArrayRef<const VkBuffer> buffers, ArrayRef<const VkDeviceSize> offsets) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindVertexBuffers(ThreadContext::CommandBuffer(), firstBinding, buffers.size(), buffers, offsets);
}

inline void CmdDraw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDraw(ThreadContext::CommandBuffer(), vertexCount, instanceCount, firstVertex, firstInstance);
}

inline void CmdDrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndexed(ThreadContext::CommandBuffer(), indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

inline void CmdDrawIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndirect(ThreadContext::CommandBuffer(), buffer, offset, drawCount, stride);
}

inline void CmdDrawIndexedIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndexedIndirect(ThreadContext::CommandBuffer(), buffer, offset, drawCount, stride);
}

inline void CmdDispatch(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDispatch(ThreadContext::CommandBuffer(), groupCountX, groupCountY, groupCountZ);
}

inline void CmdDispatchIndirect(VkBuffer buffer, VkDeviceSize offset) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDispatchIndirect(ThreadContext::CommandBuffer(), buffer, offset);
}

inline void CmdCopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, ArrayRef<const VkBufferCopy> regions) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyBuffer(ThreadContext::CommandBuffer(), srcBuffer, dstBuffer, regions.size(), regions);
}

inline void CmdCopyImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, ArrayRef<const VkImageCopy> regions) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyImage(ThreadContext::CommandBuffer(), srcImage, srcImageLayout, dstImage, dstImageLayout, regions.size(), regions);
}

inline void CmdBlitImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, ArrayRef<const VkImageBlit> regions, VkFilter filter) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBlitImage(ThreadContext::CommandBuffer(), srcImage, srcImageLayout, dstImage, dstImageLayout, regions.size(), regions, filter);
}

inline void CmdCopyBufferToImage(VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, ArrayRef<const VkBufferImageCopy> regions) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyBufferToImage(ThreadContext::CommandBuffer(), srcBuffer, dstImage, dstImageLayout, regions.size(), regions);
}

inline void CmdCopyImageToBuffer(VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, ArrayRef<const VkBufferImageCopy> regions) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyImageToBuffer(ThreadContext::CommandBuffer(), srcImage, srcImageLayout, dstBuffer, regions.size(), regions);
}

inline void CmdUpdateBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, ArrayRef<const void> data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdUpdateBuffer(ThreadContext::CommandBuffer(), dstBuffer, dstOffset, data.size(), data);
}
inline void CmdUpdateBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, const IsNotRangeOrPointer auto& data) {
	CmdUpdateBuffer(dstBuffer, dstOffset, { sizeof *&data, &data });
}

inline void CmdFillBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdFillBuffer(ThreadContext::CommandBuffer(), dstBuffer, dstOffset, size, data);
}

inline void CmdClearColorImage(VkImage image, VkImageLayout imageLayout, const VkClearColorValue& color, ArrayRef<const VkImageSubresourceRange> ranges) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdClearColorImage(ThreadContext::CommandBuffer(), image, imageLayout, &color, ranges.size(), ranges);
}

inline void CmdClearDepthStencilImage(VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue& depthStencil, ArrayRef<const VkImageSubresourceRange> ranges) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdClearDepthStencilImage(ThreadContext::CommandBuffer(), image, imageLayout, &depthStencil, ranges.size(), ranges);
}

inline void CmdClearAttachments(ArrayRef<const VkClearAttachment> attachments, ArrayRef<const VkClearRect> rects) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdClearAttachments(ThreadContext::CommandBuffer(), attachments.size(), attachments, rects.size(), rects);
}

inline void CmdResolveImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, ArrayRef<const VkImageResolve> regions) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdResolveImage(ThreadContext::CommandBuffer(), srcImage, srcImageLayout, dstImage, dstImageLayout, regions.size(), regions);
}

inline void CmdSetEvent(VkEvent event, VkPipelineStageFlags stageMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetEvent(ThreadContext::CommandBuffer(), event, stageMask);
}

inline void CmdResetEvent(VkEvent event, VkPipelineStageFlags stageMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdResetEvent(ThreadContext::CommandBuffer(), event, stageMask);
}

inline void CmdWaitEvents(ArrayRef<const VkEvent> events, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, ArrayRef<const VkMemoryBarrier> memoryBarriers, ArrayRef<const VkBufferMemoryBarrier> bufferMemoryBarriers, ArrayRef<const VkImageMemoryBarrier> imageMemoryBarriers) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWaitEvents(ThreadContext::CommandBuffer(), events.size(), events, srcStageMask, dstStageMask, memoryBarriers.size(), memoryBarriers, bufferMemoryBarriers.size(), bufferMemoryBarriers, imageMemoryBarriers.size(), imageMemoryBarriers);
}

inline void CmdPipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, ArrayRef<const VkMemoryBarrier> memoryBarriers, ArrayRef<const VkBufferMemoryBarrier> bufferMemoryBarriers, ArrayRef<const VkImageMemoryBarrier> imageMemoryBarriers) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPipelineBarrier(ThreadContext::CommandBuffer(), srcStageMask, dstStageMask, dependencyFlags, memoryBarriers.size(), memoryBarriers, bufferMemoryBarriers.size(), bufferMemoryBarriers, imageMemoryBarriers.size(), imageMemoryBarriers);
}

inline void CmdBeginQuery(VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginQuery(ThreadContext::CommandBuffer(), queryPool, query, flags);
}

inline void CmdEndQuery(VkQueryPool queryPool, uint32_t query) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndQuery(ThreadContext::CommandBuffer(), queryPool, query);
}

inline void CmdResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdResetQueryPool(ThreadContext::CommandBuffer(), queryPool, firstQuery, queryCount);
}

inline void CmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteTimestamp(ThreadContext::CommandBuffer(), pipelineStage, queryPool, query);
}

inline void CmdCopyQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyQueryPoolResults(ThreadContext::CommandBuffer(), queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

inline void CmdPushConstants(VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, ArrayRef<const void> values) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushConstants(ThreadContext::CommandBuffer(), layout, stageFlags, offset, values.size(), values);
}
inline void CmdPushConstants(VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, const IsNotRangeOrPointer auto& values) {
	CmdPushConstants(layout, stageFlags, offset, { sizeof *&values, &values });
}

inline void CmdBeginRenderPass(const VkRenderPassBeginInfo& renderPassBegin, VkSubpassContents contents) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginRenderPass(ThreadContext::CommandBuffer(), &renderPassBegin, contents);
}
DefineRaiiFunction_L(CmdBeginRenderPass, RenderPassBeginInfo, VkSubpassContents, contents);

inline void CmdNextSubpass(VkSubpassContents contents) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdNextSubpass(ThreadContext::CommandBuffer(), contents);
}

inline void CmdEndRenderPass() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndRenderPass(ThreadContext::CommandBuffer());
}

inline void CmdExecuteCommands(ArrayRef<const VkCommandBuffer> commandBuffers) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdExecuteCommands(ThreadContext::CommandBuffer(), commandBuffers.size(), commandBuffers);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSubgroupProperties) {
	StructureClassHeader(PhysicalDeviceSubgroupProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSubgroupProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindBufferMemoryInfo) {
	StructureClassHeader(BindBufferMemoryInfo);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(BindBufferMemoryInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindImageMemoryInfo) {
	StructureClassHeader(BindImageMemoryInfo);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(BindImageMemoryInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevice16BitStorageFeatures) {
	StructureClassHeader(PhysicalDevice16BitStorageFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevice16BitStorageFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryDedicatedRequirements) {
	StructureClassHeader(MemoryDedicatedRequirements);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryDedicatedRequirements)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryDedicatedAllocateInfo) {
	StructureClassHeader(MemoryDedicatedAllocateInfo);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryDedicatedAllocateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryAllocateFlagsInfo) {
	StructureClassHeader(MemoryAllocateFlagsInfo);
	DefineSetter_Copy(Flags, VkMemoryAllocateFlags, flags);
	DefineSetter_Copy(DeviceMask, uint32_t, deviceMask);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryAllocateFlagsInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupRenderPassBeginInfo) {
	StructureClassHeader(DeviceGroupRenderPassBeginInfo);
	DefineSetter_Copy(DeviceMask, uint32_t, deviceMask);
	DefineSetter_Copy(DeviceRenderAreaCount, uint32_t, deviceRenderAreaCount);
	DefineSetter_ArrayRef(DeviceRenderAreas, const VkRect2D, deviceRenderAreas, deviceRenderAreaCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupRenderPassBeginInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupCommandBufferBeginInfo) {
	StructureClassHeader(DeviceGroupCommandBufferBeginInfo);
	DefineSetter_Copy(DeviceMask, uint32_t, deviceMask);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupCommandBufferBeginInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupSubmitInfo) {
	StructureClassHeader(DeviceGroupSubmitInfo);
	DefineSetter_Copy(WaitSemaphoreCount, uint32_t, waitSemaphoreCount);
	DefineSetter_ArrayRef(WaitSemaphoreDeviceIndices, const uint32_t, waitSemaphoreDeviceIndices, waitSemaphoreCount);
	DefineSetter_Copy(CommandBufferCount, uint32_t, commandBufferCount);
	DefineSetter_ArrayRef(CommandBufferDeviceMasks, const uint32_t, commandBufferDeviceMasks, commandBufferCount);
	DefineSetter_Copy(SignalSemaphoreCount, uint32_t, signalSemaphoreCount);
	DefineSetter_ArrayRef(SignalSemaphoreDeviceIndices, const uint32_t, signalSemaphoreDeviceIndices, signalSemaphoreCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupSubmitInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupBindSparseInfo) {
	StructureClassHeader(DeviceGroupBindSparseInfo);
	DefineSetter_Copy(ResourceDeviceIndex, uint32_t, resourceDeviceIndex);
	DefineSetter_Copy(MemoryDeviceIndex, uint32_t, memoryDeviceIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupBindSparseInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindBufferMemoryDeviceGroupInfo) {
	StructureClassHeader(BindBufferMemoryDeviceGroupInfo);
	DefineSetter_Copy(DeviceIndexCount, uint32_t, deviceIndexCount);
	DefineSetter_ArrayRef(DeviceIndices, const uint32_t, deviceIndices, deviceIndexCount);
};
VK_ENCAPSULATION_STRUCTURE_END(BindBufferMemoryDeviceGroupInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindImageMemoryDeviceGroupInfo) {
	StructureClassHeader(BindImageMemoryDeviceGroupInfo);
	DefineSetter_Copy(DeviceIndexCount, uint32_t, deviceIndexCount);
	DefineSetter_ArrayRef(DeviceIndices, const uint32_t, deviceIndices, deviceIndexCount);
	DefineSetter_Copy(SplitInstanceBindRegionCount, uint32_t, splitInstanceBindRegionCount);
	DefineSetter_ArrayRef(SplitInstanceBindRegions, const VkRect2D, splitInstanceBindRegions, splitInstanceBindRegionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(BindImageMemoryDeviceGroupInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceGroupProperties) {
	StructureClassHeader(PhysicalDeviceGroupProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceGroupProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupDeviceCreateInfo) {
	StructureClassHeader(DeviceGroupDeviceCreateInfo);
	DefineSetter_Copy(PhysicalDeviceCount, uint32_t, physicalDeviceCount);
	DefineSetter_ArrayRef(PhysicalDevices, const VkPhysicalDevice, physicalDevices, physicalDeviceCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupDeviceCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferMemoryRequirementsInfo2) {
	StructureClassHeader(BufferMemoryRequirementsInfo2);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferMemoryRequirementsInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageMemoryRequirementsInfo2) {
	StructureClassHeader(ImageMemoryRequirementsInfo2);
	DefineSetter_Copy(Image, VkImage, image);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageMemoryRequirementsInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageSparseMemoryRequirementsInfo2) {
	StructureClassHeader(ImageSparseMemoryRequirementsInfo2);
	DefineSetter_Copy(Image, VkImage, image);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageSparseMemoryRequirementsInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryRequirements2) {
	StructureClassHeader(MemoryRequirements2);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryRequirements2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SparseImageMemoryRequirements2) {
	StructureClassHeader(SparseImageMemoryRequirements2);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseImageMemoryRequirements2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFeatures2) {
	StructureClassHeader(PhysicalDeviceFeatures2);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFeatures2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceProperties2) {
	StructureClassHeader(PhysicalDeviceProperties2);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceProperties2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FormatProperties2) {
	StructureClassHeader(FormatProperties2);
};
VK_ENCAPSULATION_STRUCTURE_END(FormatProperties2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageFormatProperties2) {
	StructureClassHeader(ImageFormatProperties2);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageFormatProperties2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageFormatInfo2) {
	StructureClassHeader(PhysicalDeviceImageFormatInfo2);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Type, VkImageType, type);
	DefineSetter_Copy(Tiling, VkImageTiling, tiling);
	DefineSetter_Copy(Usage, VkImageUsageFlags, usage);
	DefineSetter_Copy(Flags, VkImageCreateFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageFormatInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyProperties2) {
	StructureClassHeader(QueueFamilyProperties2);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyProperties2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMemoryProperties2) {
	StructureClassHeader(PhysicalDeviceMemoryProperties2);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMemoryProperties2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SparseImageFormatProperties2) {
	StructureClassHeader(SparseImageFormatProperties2);
};
VK_ENCAPSULATION_STRUCTURE_END(SparseImageFormatProperties2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSparseImageFormatInfo2) {
	StructureClassHeader(PhysicalDeviceSparseImageFormatInfo2, .samples = VK_SAMPLE_COUNT_1_BIT);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Type, VkImageType, type);
	DefineSetter_Copy(Samples, VkSampleCountFlagBits, samples);
	DefineSetter_Copy(Usage, VkImageUsageFlags, usage);
	DefineSetter_Copy(Tiling, VkImageTiling, tiling);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSparseImageFormatInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePointClippingProperties) {
	StructureClassHeader(PhysicalDevicePointClippingProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePointClippingProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(InputAttachmentAspectReference) {
	StructureClassHeader_NoSType(InputAttachmentAspectReference);
	DefineSetter_Copy(Subpass, uint32_t, subpass);
	DefineSetter_Copy(InputAttachmentIndex, uint32_t, inputAttachmentIndex);
	DefineSetter_Copy(AspectMask, VkImageAspectFlags, aspectMask);
};
VK_ENCAPSULATION_STRUCTURE_END(InputAttachmentAspectReference)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassInputAttachmentAspectCreateInfo) {
	StructureClassHeader(RenderPassInputAttachmentAspectCreateInfo);
	DefineSetter_Copy(AspectReferenceCount, uint32_t, aspectReferenceCount);
	DefineSetter_ArrayRef(AspectReferences, const VkInputAttachmentAspectReference, aspectReferences, aspectReferenceCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassInputAttachmentAspectCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewUsageCreateInfo) {
	StructureClassHeader(ImageViewUsageCreateInfo);
	DefineSetter_Copy(Usage, VkImageUsageFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewUsageCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineTessellationDomainOriginStateCreateInfo) {
	StructureClassHeader(PipelineTessellationDomainOriginStateCreateInfo);
	DefineSetter_Copy(DomainOrigin, VkTessellationDomainOrigin, domainOrigin);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineTessellationDomainOriginStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassMultiviewCreateInfo) {
	StructureClassHeader(RenderPassMultiviewCreateInfo);
	DefineSetter_Copy(SubpassCount, uint32_t, subpassCount);
	DefineSetter_ArrayRef(ViewMasks, const uint32_t, viewMasks, subpassCount);
	DefineSetter_Copy(DependencyCount, uint32_t, dependencyCount);
	DefineSetter_ArrayRef(ViewOffsets, const int32_t, viewOffsets, dependencyCount);
	DefineSetter_Copy(CorrelationMaskCount, uint32_t, correlationMaskCount);
	DefineSetter_ArrayRef(CorrelationMasks, const uint32_t, correlationMasks, correlationMaskCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassMultiviewCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultiviewFeatures) {
	StructureClassHeader(PhysicalDeviceMultiviewFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultiviewFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultiviewProperties) {
	StructureClassHeader(PhysicalDeviceMultiviewProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultiviewProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVariablePointersFeatures) {
	StructureClassHeader(PhysicalDeviceVariablePointersFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVariablePointersFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceProtectedMemoryFeatures) {
	StructureClassHeader(PhysicalDeviceProtectedMemoryFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceProtectedMemoryFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceProtectedMemoryProperties) {
	StructureClassHeader(PhysicalDeviceProtectedMemoryProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceProtectedMemoryProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceQueueInfo2) {
	StructureClassHeader(DeviceQueueInfo2);
	DefineSetter_Copy(Flags, VkDeviceQueueCreateFlags, flags);
	DefineSetter_Copy(QueueFamilyIndex, uint32_t, queueFamilyIndex);
	DefineSetter_Copy(QueueIndex, uint32_t, queueIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceQueueInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ProtectedSubmitInfo) {
	StructureClassHeader(ProtectedSubmitInfo);
	DefineSetter_Copy(ProtectedSubmit, VkBool32, protectedSubmit);
};
VK_ENCAPSULATION_STRUCTURE_END(ProtectedSubmitInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerYcbcrConversionCreateInfo) {
	StructureClassHeader(SamplerYcbcrConversionCreateInfo);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(YcbcrModel, VkSamplerYcbcrModelConversion, ycbcrModel);
	DefineSetter_Copy(YcbcrRange, VkSamplerYcbcrRange, ycbcrRange);
	DefineSetter_Copy(Components, VkComponentMapping, components);
	DefineSetter_Copy(XChromaOffset, VkChromaLocation, xChromaOffset);
	DefineSetter_Copy(YChromaOffset, VkChromaLocation, yChromaOffset);
	DefineSetter_Copy(ChromaFilter, VkFilter, chromaFilter);
	DefineSetter_Copy(ForceExplicitReconstruction, VkBool32, forceExplicitReconstruction);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerYcbcrConversionCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerYcbcrConversionInfo) {
	StructureClassHeader(SamplerYcbcrConversionInfo);
	DefineSetter_Copy(Conversion, VkSamplerYcbcrConversion, conversion);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerYcbcrConversionInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindImagePlaneMemoryInfo) {
	StructureClassHeader(BindImagePlaneMemoryInfo);
	DefineSetter_Copy(PlaneAspect, VkImageAspectFlagBits, planeAspect);
};
VK_ENCAPSULATION_STRUCTURE_END(BindImagePlaneMemoryInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImagePlaneMemoryRequirementsInfo) {
	StructureClassHeader(ImagePlaneMemoryRequirementsInfo);
	DefineSetter_Copy(PlaneAspect, VkImageAspectFlagBits, planeAspect);
};
VK_ENCAPSULATION_STRUCTURE_END(ImagePlaneMemoryRequirementsInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSamplerYcbcrConversionFeatures) {
	StructureClassHeader(PhysicalDeviceSamplerYcbcrConversionFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSamplerYcbcrConversionFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerYcbcrConversionImageFormatProperties) {
	StructureClassHeader(SamplerYcbcrConversionImageFormatProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerYcbcrConversionImageFormatProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DescriptorUpdateTemplateEntry) {
	StructureClassHeader_NoSType(DescriptorUpdateTemplateEntry);
	DefineSetter_Copy(DstBinding, uint32_t, dstBinding);
	DefineSetter_Copy(DstArrayElement, uint32_t, dstArrayElement);
	DefineSetter_Copy(DescriptorCount, uint32_t, descriptorCount);
	DefineSetter_Copy(DescriptorType, VkDescriptorType, descriptorType);
	DefineSetter_Copy(Offset, size_t, offset);
	DefineSetter_Copy(Stride, size_t, stride);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorUpdateTemplateEntry)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorUpdateTemplateCreateInfo) {
	StructureClassHeader(DescriptorUpdateTemplateCreateInfo);
	DefineSetter_Copy(Flags, VkDescriptorUpdateTemplateCreateFlags, flags);
	DefineSetter_Copy(DescriptorUpdateEntryCount, uint32_t, descriptorUpdateEntryCount);
	DefineSetter_ArrayRef(DescriptorUpdateEntries, const VkDescriptorUpdateTemplateEntry, descriptorUpdateEntries, descriptorUpdateEntryCount);
	DefineSetter_Copy(TemplateType, VkDescriptorUpdateTemplateType, templateType);
	DefineSetter_Copy(DescriptorSetLayout, VkDescriptorSetLayout, descriptorSetLayout);
	DefineSetter_Copy(PipelineBindPoint, VkPipelineBindPoint, pipelineBindPoint);
	DefineSetter_Copy(PipelineLayout, VkPipelineLayout, pipelineLayout);
	DefineSetter_Copy(Set, uint32_t, set);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorUpdateTemplateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ExternalMemoryProperties) {
	StructureClassHeader_NoSType(ExternalMemoryProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalMemoryProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalImageFormatInfo) {
	StructureClassHeader(PhysicalDeviceExternalImageFormatInfo);
	DefineSetter_Copy(HandleType, VkExternalMemoryHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalImageFormatInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalImageFormatProperties) {
	StructureClassHeader(ExternalImageFormatProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalImageFormatProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalBufferInfo) {
	StructureClassHeader(PhysicalDeviceExternalBufferInfo);
	DefineSetter_Copy(Flags, VkBufferCreateFlags, flags);
	DefineSetter_Copy(Usage, VkBufferUsageFlags, usage);
	DefineSetter_Copy(HandleType, VkExternalMemoryHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalBufferInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalBufferProperties) {
	StructureClassHeader(ExternalBufferProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalBufferProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceIDProperties) {
	StructureClassHeader(PhysicalDeviceIDProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceIDProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalMemoryImageCreateInfo) {
	StructureClassHeader(ExternalMemoryImageCreateInfo);
	DefineSetter_Copy(HandleTypes, VkExternalMemoryHandleTypeFlags, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalMemoryImageCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalMemoryBufferCreateInfo) {
	StructureClassHeader(ExternalMemoryBufferCreateInfo);
	DefineSetter_Copy(HandleTypes, VkExternalMemoryHandleTypeFlags, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalMemoryBufferCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExportMemoryAllocateInfo) {
	StructureClassHeader(ExportMemoryAllocateInfo);
	DefineSetter_Copy(HandleTypes, VkExternalMemoryHandleTypeFlags, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExportMemoryAllocateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalFenceInfo) {
	StructureClassHeader(PhysicalDeviceExternalFenceInfo);
	DefineSetter_Copy(HandleType, VkExternalFenceHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalFenceInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalFenceProperties) {
	StructureClassHeader(ExternalFenceProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalFenceProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExportFenceCreateInfo) {
	StructureClassHeader(ExportFenceCreateInfo);
	DefineSetter_Copy(HandleTypes, VkExternalFenceHandleTypeFlags, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExportFenceCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExportSemaphoreCreateInfo) {
	StructureClassHeader(ExportSemaphoreCreateInfo);
	DefineSetter_Copy(HandleTypes, VkExternalSemaphoreHandleTypeFlags, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExportSemaphoreCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalSemaphoreInfo) {
	StructureClassHeader(PhysicalDeviceExternalSemaphoreInfo);
	DefineSetter_Copy(HandleType, VkExternalSemaphoreHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalSemaphoreInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalSemaphoreProperties) {
	StructureClassHeader(ExternalSemaphoreProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalSemaphoreProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance3Properties) {
	StructureClassHeader(PhysicalDeviceMaintenance3Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance3Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetLayoutSupport) {
	StructureClassHeader(DescriptorSetLayoutSupport);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetLayoutSupport)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderDrawParametersFeatures) {
	StructureClassHeader(PhysicalDeviceShaderDrawParametersFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderDrawParametersFeatures)

inline VkResult EnumerateInstanceVersion(uint32_t& apiVersion) {
	return VK_ENCAPSULATION_DISPATCH vkEnumerateInstanceVersion(&apiVersion);
}

inline VkResult BindBufferMemory2(ArrayRef<const VkBindBufferMemoryInfo> bindInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindBufferMemory2(DeviceContext::Device(), bindInfos.size(), bindInfos);
}
DefineRaiiFunction_Result(VkResult, BindBufferMemory2, BindBufferMemoryInfo);

inline VkResult BindImageMemory2(ArrayRef<const VkBindImageMemoryInfo> bindInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindImageMemory2(DeviceContext::Device(), bindInfos.size(), bindInfos);
}
DefineRaiiFunction_Result(VkResult, BindImageMemory2, BindImageMemoryInfo);

inline void GetDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags& peerMemoryFeatures) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceGroupPeerMemoryFeatures(DeviceContext::Device(), heapIndex, localDeviceIndex, remoteDeviceIndex, &peerMemoryFeatures);
}

inline void CmdSetDeviceMask(uint32_t deviceMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDeviceMask(ThreadContext::CommandBuffer(), deviceMask);
}

inline void CmdDispatchBase(uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDispatchBase(ThreadContext::CommandBuffer(), baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

inline VkResult EnumeratePhysicalDeviceGroups(uint32_t& physicalDeviceGroupCount, ArrayRef<VkPhysicalDeviceGroupProperties> physicalDeviceGroupProperties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkEnumeratePhysicalDeviceGroups(InstanceContext::Instance(), &physicalDeviceGroupCount, physicalDeviceGroupProperties);
}
inline VkResult EnumeratePhysicalDeviceGroups(IsDynamicArray<VkPhysicalDeviceGroupProperties> auto& physicalDeviceGroupProperties) {
	uint32_t count = 0;
	VkResult result = EnumeratePhysicalDeviceGroups(count);
	if (result == VK_SUCCESS)
		physicalDeviceGroupProperties.resize(count),
		result = EnumeratePhysicalDeviceGroups(count, physicalDeviceGroupProperties);
	return result;
}

inline void GetImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageMemoryRequirements2(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetImageMemoryRequirements2, ImageMemoryRequirementsInfo2, VkMemoryRequirements2&, memoryRequirements);

inline void GetBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferMemoryRequirements2(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetBufferMemoryRequirements2, BufferMemoryRequirementsInfo2, VkMemoryRequirements2&, memoryRequirements);

inline void GetImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2& info, uint32_t& sparseMemoryRequirementCount, ArrayRef<VkSparseImageMemoryRequirements2> sparseMemoryRequirements = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageSparseMemoryRequirements2(DeviceContext::Device(), &info, &sparseMemoryRequirementCount, sparseMemoryRequirements);
}
inline void GetImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2& info, IsDynamicArray<VkSparseImageMemoryRequirements2> auto& sparseMemoryRequirements) {
	uint32_t count = 0;
	GetImageSparseMemoryRequirements2(info, count);
	sparseMemoryRequirements.resize(count);
	GetImageSparseMemoryRequirements2(info, count, sparseMemoryRequirements);
}
DefineRaiiFunction_L(GetImageSparseMemoryRequirements2, ImageSparseMemoryRequirementsInfo2, IsDynamicArray<VkSparseImageMemoryRequirements2> auto&, sparseMemoryRequirements);

inline void GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2& features) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceFeatures2(physicalDevice, &features);
}
inline void GetPhysicalDeviceFeatures2(VkPhysicalDeviceFeatures2& features) {
	GetPhysicalDeviceFeatures2(DeviceContext::PhysicalDevice(), features);
}

inline void GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2& properties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceProperties2(physicalDevice, &properties);
}
inline void GetPhysicalDeviceProperties2(VkPhysicalDeviceProperties2& properties) {
	GetPhysicalDeviceProperties2(DeviceContext::PhysicalDevice(), properties);
}

inline void GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2& formatProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, &formatProperties);
}
inline void GetPhysicalDeviceFormatProperties2(VkFormat format, VkFormatProperties2& formatProperties) {
	GetPhysicalDeviceFormatProperties2(DeviceContext::PhysicalDevice(), format, formatProperties);
}

inline VkResult GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2& imageFormatInfo, VkImageFormatProperties2& imageFormatProperties) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, &imageFormatInfo, &imageFormatProperties);
}
inline VkResult GetPhysicalDeviceImageFormatProperties2(const VkPhysicalDeviceImageFormatInfo2& imageFormatInfo, VkImageFormatProperties2& imageFormatProperties) {
	return GetPhysicalDeviceImageFormatProperties2(DeviceContext::PhysicalDevice(), imageFormatInfo, imageFormatProperties);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceImageFormatProperties2, PhysicalDeviceImageFormatInfo2, VkImageFormatProperties2&, imageFormatProperties);

inline void GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t& queueFamilyPropertyCount, ArrayRef<VkQueueFamilyProperties2> queueFamilyProperties = {}) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &queueFamilyPropertyCount, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, IsDynamicArray<VkQueueFamilyProperties2> auto& queueFamilyProperties) {
	uint32_t count = 0;
	GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, count);
	queueFamilyProperties.resize(count);
	GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, count, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties2(uint32_t& queueFamilyPropertyCount, ArrayRef<VkQueueFamilyProperties2> queueFamilyProperties = {}) {
	GetPhysicalDeviceQueueFamilyProperties2(DeviceContext::PhysicalDevice(), queueFamilyPropertyCount, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties2(IsDynamicArray<VkQueueFamilyProperties2> auto& queueFamilyProperties) {
	GetPhysicalDeviceQueueFamilyProperties2(DeviceContext::PhysicalDevice(), queueFamilyProperties);
}

inline void GetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2& memoryProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceMemoryProperties2(physicalDevice, &memoryProperties);
}
inline void GetPhysicalDeviceMemoryProperties2(VkPhysicalDeviceMemoryProperties2& memoryProperties) {
	GetPhysicalDeviceMemoryProperties2(DeviceContext::PhysicalDevice(), memoryProperties);
}

inline void GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, uint32_t& propertyCount, ArrayRef<VkSparseImageFormatProperties2> properties = {}) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, &formatInfo, &propertyCount, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, IsDynamicArray<VkSparseImageFormatProperties2> auto& properties) {
	uint32_t count = 0;
	GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, formatInfo, count);
	properties.resize(count);
	GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, formatInfo, count, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties2(const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, uint32_t& propertyCount, ArrayRef<VkSparseImageFormatProperties2> properties = {}) {
	GetPhysicalDeviceSparseImageFormatProperties2(DeviceContext::PhysicalDevice(), formatInfo, propertyCount, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties2(const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, IsDynamicArray<VkSparseImageFormatProperties2> auto& properties) {
	GetPhysicalDeviceSparseImageFormatProperties2(DeviceContext::PhysicalDevice(), formatInfo, properties);
}
DefineRaiiFunction_L(GetPhysicalDeviceSparseImageFormatProperties2, PhysicalDeviceSparseImageFormatInfo2, IsDynamicArray<VkSparseImageFormatProperties2> auto&, properties);

inline void TrimCommandPool(VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkTrimCommandPool(DeviceContext::Device(), commandPool, flags);
}

inline void GetDeviceQueue2(const VkDeviceQueueInfo2& queueInfo, HandleRef<VkQueue> queue) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceQueue2(DeviceContext::Device(), &queueInfo, &queue);
	if (ThreadContext::Queue() == VK_NULL_HANDLE)
		ThreadContext::Queue(queue);
}
DefineRaiiFunction_L(GetDeviceQueue2, DeviceQueueInfo2, HandleRef<VkQueue>, queue);

inline VkResult CreateSamplerYcbcrConversion(const VkSamplerYcbcrConversionCreateInfo& createInfo, HandleRef<VkSamplerYcbcrConversion> ycbcrConversion) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateSamplerYcbcrConversion(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &ycbcrConversion);
}
DefineRaiiFunction_ResultL(VkResult, CreateSamplerYcbcrConversion, SamplerYcbcrConversionCreateInfo, HandleRef<VkSamplerYcbcrConversion>, ycbcrConversion);

inline void DestroySamplerYcbcrConversion(HandleRef<VkSamplerYcbcrConversion> ycbcrConversion, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroySamplerYcbcrConversion(DeviceContext::Device(), ycbcrConversion, &allocator);
	ycbcrConversion = VK_NULL_HANDLE;
}

inline VkResult CreateDescriptorUpdateTemplate(const VkDescriptorUpdateTemplateCreateInfo& createInfo, HandleRef<VkDescriptorUpdateTemplate> descriptorUpdateTemplate) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateDescriptorUpdateTemplate(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &descriptorUpdateTemplate);
}
DefineRaiiFunction_ResultL(VkResult, CreateDescriptorUpdateTemplate, DescriptorUpdateTemplateCreateInfo, HandleRef<VkDescriptorUpdateTemplate>, descriptorUpdateTemplate);

inline void DestroyDescriptorUpdateTemplate(HandleRef<VkDescriptorUpdateTemplate> descriptorUpdateTemplate, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyDescriptorUpdateTemplate(DeviceContext::Device(), descriptorUpdateTemplate, &allocator);
	descriptorUpdateTemplate = VK_NULL_HANDLE;
}

inline void UpdateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, ArrayRef<const void> data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkUpdateDescriptorSetWithTemplate(DeviceContext::Device(), descriptorSet, descriptorUpdateTemplate, data);
}
inline void UpdateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const IsNotRangeOrPointer auto& data) {
	UpdateDescriptorSetWithTemplate(DeviceContext::Device(), descriptorSet, descriptorUpdateTemplate, { 0, &data });
}

inline void GetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo& externalBufferInfo, VkExternalBufferProperties& externalBufferProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, &externalBufferInfo, &externalBufferProperties);
}
inline void GetPhysicalDeviceExternalBufferProperties(const VkPhysicalDeviceExternalBufferInfo& externalBufferInfo, VkExternalBufferProperties& externalBufferProperties) {
	GetPhysicalDeviceExternalBufferProperties(DeviceContext::PhysicalDevice(), externalBufferInfo, externalBufferProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceExternalBufferProperties, PhysicalDeviceExternalBufferInfo, VkExternalBufferProperties&, externalBufferProperties);

inline void GetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo& externalFenceInfo, VkExternalFenceProperties& externalFenceProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, &externalFenceInfo, &externalFenceProperties);
}
inline void GetPhysicalDeviceExternalFenceProperties(const VkPhysicalDeviceExternalFenceInfo& externalFenceInfo, VkExternalFenceProperties& externalFenceProperties) {
	GetPhysicalDeviceExternalFenceProperties(DeviceContext::PhysicalDevice(), externalFenceInfo, externalFenceProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceExternalFenceProperties, PhysicalDeviceExternalFenceInfo, VkExternalFenceProperties&, externalFenceProperties);

inline void GetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo& externalSemaphoreInfo, VkExternalSemaphoreProperties& externalSemaphoreProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, &externalSemaphoreInfo, &externalSemaphoreProperties);
}
inline void GetPhysicalDeviceExternalSemaphoreProperties(const VkPhysicalDeviceExternalSemaphoreInfo& externalSemaphoreInfo, VkExternalSemaphoreProperties& externalSemaphoreProperties) {
	GetPhysicalDeviceExternalSemaphoreProperties(DeviceContext::PhysicalDevice(), externalSemaphoreInfo, externalSemaphoreProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceExternalSemaphoreProperties, PhysicalDeviceExternalSemaphoreInfo, VkExternalSemaphoreProperties&, externalSemaphoreProperties);

inline void GetDescriptorSetLayoutSupport(const VkDescriptorSetLayoutCreateInfo& createInfo, VkDescriptorSetLayoutSupport& support) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDescriptorSetLayoutSupport(DeviceContext::Device(), &createInfo, &support);
}
DefineRaiiFunction_L(GetDescriptorSetLayoutSupport, DescriptorSetLayoutCreateInfo, VkDescriptorSetLayoutSupport&, support);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan11Features) {
	StructureClassHeader(PhysicalDeviceVulkan11Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan11Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan11Properties) {
	StructureClassHeader(PhysicalDeviceVulkan11Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan11Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan12Features) {
	StructureClassHeader(PhysicalDeviceVulkan12Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan12Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ConformanceVersion) {
	StructureClassHeader_NoSType(ConformanceVersion);
};
VK_ENCAPSULATION_STRUCTURE_END(ConformanceVersion)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan12Properties) {
	StructureClassHeader(PhysicalDeviceVulkan12Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan12Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageFormatListCreateInfo) {
	StructureClassHeader(ImageFormatListCreateInfo);
	DefineSetter_Copy(ViewFormatCount, uint32_t, viewFormatCount);
	DefineSetter_ArrayRef(ViewFormats, const VkFormat, viewFormats, viewFormatCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageFormatListCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AttachmentDescription2) {
	StructureClassHeader(AttachmentDescription2, .samples = VK_SAMPLE_COUNT_1_BIT);
	DefineSetter_Copy(Flags, VkAttachmentDescriptionFlags, flags);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Samples, VkSampleCountFlagBits, samples);
	DefineSetter_Copy(LoadOp, VkAttachmentLoadOp, loadOp);
	DefineSetter_Copy(StoreOp, VkAttachmentStoreOp, storeOp);
	DefineSetter_Copy(StencilLoadOp, VkAttachmentLoadOp, stencilLoadOp);
	DefineSetter_Copy(StencilStoreOp, VkAttachmentStoreOp, stencilStoreOp);
	DefineSetter_Copy(InitialLayout, VkImageLayout, initialLayout);
	DefineSetter_Copy(FinalLayout, VkImageLayout, finalLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentDescription2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AttachmentReference2) {
	StructureClassHeader(AttachmentReference2);
	DefineSetter_Copy(Attachment, uint32_t, attachment);
	DefineSetter_Copy(Layout, VkImageLayout, layout);
	DefineSetter_Copy(AspectMask, VkImageAspectFlags, aspectMask);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentReference2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubpassDescription2) {
	StructureClassHeader(SubpassDescription2);
	DefineSetter_Copy(Flags, VkSubpassDescriptionFlags, flags);
	DefineSetter_Copy(PipelineBindPoint, VkPipelineBindPoint, pipelineBindPoint);
	DefineSetter_Copy(ViewMask, uint32_t, viewMask);
	DefineSetter_Copy(InputAttachmentCount, uint32_t, inputAttachmentCount);
	DefineSetter_ArrayRef(InputAttachments, const VkAttachmentReference2, inputAttachments, inputAttachmentCount);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachments, const VkAttachmentReference2, colorAttachments, colorAttachmentCount);
	DefineSetter_ArrayRefIgnoreC(ResolveAttachments, const VkAttachmentReference2, resolveAttachments);
	DefineSetter_Ref(DepthStencilAttachment, const VkAttachmentReference2, depthStencilAttachment);
	DefineSetter_Copy(PreserveAttachmentCount, uint32_t, preserveAttachmentCount);
	DefineSetter_ArrayRef(PreserveAttachments, const VkAttachmentReference2, preserveAttachments, preserveAttachmentCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassDescription2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubpassDependency2) {
	StructureClassHeader(SubpassDependency2);
	DefineSetter_Copy(SrcSubpass, uint32_t, srcSubpass);
	DefineSetter_Copy(DstSubpass, uint32_t, dstSubpass);
	DefineSetter_Copy(SrcStageMask, VkPipelineStageFlags, srcStageMask);
	DefineSetter_Copy(DstStageMask, VkPipelineStageFlags, dstStageMask);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags, srcAccessMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags, dstAccessMask);
	DefineSetter_Copy(DependencyFlags, VkDependencyFlags, dependencyFlags);
	DefineSetter_Copy(ViewOffset, int32_t, viewOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassDependency2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassCreateInfo2) {
	StructureClassHeader(RenderPassCreateInfo2);
	DefineSetter_Copy(Flags, VkRenderPassCreateFlags, flags);
	DefineSetter_Copy(AttachmentCount, uint32_t, attachmentCount);
	DefineSetter_ArrayRef(Attachments, const VkAttachmentDescription2, attachments, attachmentCount);
	DefineSetter_Copy(SubpassCount, uint32_t, subpassCount);
	DefineSetter_ArrayRef(Subpasses, const VkSubpassDescription2, subpasses, subpassCount);
	DefineSetter_Copy(DependencyCount, uint32_t, dependencyCount);
	DefineSetter_ArrayRef(Dependencies, const VkSubpassDependency2, dependencies, dependencyCount);
	DefineSetter_Copy(CorrelatedViewMaskCount, uint32_t, correlatedViewMaskCount);
	DefineSetter_ArrayRef(CorrelatedViewMasks, const uint32_t, correlatedViewMasks, correlatedViewMaskCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassCreateInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubpassBeginInfo) {
	StructureClassHeader(SubpassBeginInfo);
	DefineSetter_Copy(Contents, VkSubpassContents, contents);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassBeginInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubpassEndInfo) {
	StructureClassHeader(SubpassEndInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassEndInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevice8BitStorageFeatures) {
	StructureClassHeader(PhysicalDevice8BitStorageFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevice8BitStorageFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDriverProperties) {
	StructureClassHeader(PhysicalDeviceDriverProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDriverProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderAtomicInt64Features) {
	StructureClassHeader(PhysicalDeviceShaderAtomicInt64Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderAtomicInt64Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderFloat16Int8Features) {
	StructureClassHeader(PhysicalDeviceShaderFloat16Int8Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderFloat16Int8Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFloatControlsProperties) {
	StructureClassHeader(PhysicalDeviceFloatControlsProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFloatControlsProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetLayoutBindingFlagsCreateInfo) {
	StructureClassHeader(DescriptorSetLayoutBindingFlagsCreateInfo);
	DefineSetter_Copy(BindingCount, uint32_t, bindingCount);
	DefineSetter_ArrayRef(BindingFlags, const VkDescriptorBindingFlags, bindingFlags, bindingCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetLayoutBindingFlagsCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorIndexingFeatures) {
	StructureClassHeader(PhysicalDeviceDescriptorIndexingFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorIndexingFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorIndexingProperties) {
	StructureClassHeader(PhysicalDeviceDescriptorIndexingProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorIndexingProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetVariableDescriptorCountAllocateInfo) {
	StructureClassHeader(DescriptorSetVariableDescriptorCountAllocateInfo);
	DefineSetter_Copy(DescriptorSetCount, uint32_t, descriptorSetCount);
	DefineSetter_ArrayRef(DescriptorCounts, const uint32_t, descriptorCounts, descriptorSetCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetVariableDescriptorCountAllocateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetVariableDescriptorCountLayoutSupport) {
	StructureClassHeader(DescriptorSetVariableDescriptorCountLayoutSupport);
	DefineSetter_Copy(MaxVariableDescriptorCount, uint32_t, maxVariableDescriptorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetVariableDescriptorCountLayoutSupport)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubpassDescriptionDepthStencilResolve) {
	StructureClassHeader(SubpassDescriptionDepthStencilResolve);
	DefineSetter_Copy(DepthResolveMode, VkResolveModeFlagBits, depthResolveMode);
	DefineSetter_Copy(StencilResolveMode, VkResolveModeFlagBits, stencilResolveMode);
	DefineSetter_Ref(DepthStencilResolveAttachment, const VkAttachmentReference2, depthStencilResolveAttachment);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassDescriptionDepthStencilResolve)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDepthStencilResolveProperties) {
	StructureClassHeader(PhysicalDeviceDepthStencilResolveProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDepthStencilResolveProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceScalarBlockLayoutFeatures) {
	StructureClassHeader(PhysicalDeviceScalarBlockLayoutFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceScalarBlockLayoutFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageStencilUsageCreateInfo) {
	StructureClassHeader(ImageStencilUsageCreateInfo);
	DefineSetter_Copy(StencilUsage, VkImageUsageFlags, stencilUsage);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageStencilUsageCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerReductionModeCreateInfo) {
	StructureClassHeader(SamplerReductionModeCreateInfo);
	DefineSetter_Copy(ReductionMode, VkSamplerReductionMode, reductionMode);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerReductionModeCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSamplerFilterMinmaxProperties) {
	StructureClassHeader(PhysicalDeviceSamplerFilterMinmaxProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSamplerFilterMinmaxProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkanMemoryModelFeatures) {
	StructureClassHeader(PhysicalDeviceVulkanMemoryModelFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkanMemoryModelFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImagelessFramebufferFeatures) {
	StructureClassHeader(PhysicalDeviceImagelessFramebufferFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImagelessFramebufferFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FramebufferAttachmentImageInfo) {
	StructureClassHeader(FramebufferAttachmentImageInfo, .layerCount = 1);
	DefineSetter_Copy(Flags, VkImageCreateFlags, flags);
	DefineSetter_Copy(Usage, VkImageUsageFlags, usage);
	DefineSetter_Copy(Width, uint32_t, width);
	DefineSetter_Copy(Height, uint32_t, height);
	DefineSetter_Copy(LayerCount, uint32_t, layerCount);
	DefineSetter_Copy(ViewFormatCount, uint32_t, viewFormatCount);
	DefineSetter_ArrayRef(ViewFormats, const VkFormat, viewFormats, viewFormatCount);
};
VK_ENCAPSULATION_STRUCTURE_END(FramebufferAttachmentImageInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FramebufferAttachmentsCreateInfo) {
	StructureClassHeader(FramebufferAttachmentsCreateInfo);
	DefineSetter_Copy(AttachmentImageInfoCount, uint32_t, attachmentImageInfoCount);
	DefineSetter_ArrayRef(AttachmentImageInfos, const VkFramebufferAttachmentImageInfo, attachmentImageInfos, attachmentImageInfoCount);
};
VK_ENCAPSULATION_STRUCTURE_END(FramebufferAttachmentsCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassAttachmentBeginInfo) {
	StructureClassHeader(RenderPassAttachmentBeginInfo);
	DefineSetter_Copy(AttachmentCount, uint32_t, attachmentCount);
	DefineSetter_ArrayRef(Attachments, const VkImageView, attachments, attachmentCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassAttachmentBeginInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceUniformBufferStandardLayoutFeatures) {
	StructureClassHeader(PhysicalDeviceUniformBufferStandardLayoutFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceUniformBufferStandardLayoutFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderSubgroupExtendedTypesFeatures) {
	StructureClassHeader(PhysicalDeviceShaderSubgroupExtendedTypesFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderSubgroupExtendedTypesFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSeparateDepthStencilLayoutsFeatures) {
	StructureClassHeader(PhysicalDeviceSeparateDepthStencilLayoutsFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSeparateDepthStencilLayoutsFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AttachmentReferenceStencilLayout) {
	StructureClassHeader(AttachmentReferenceStencilLayout);
	DefineSetter_Copy(StencilLayout, VkImageLayout, stencilLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentReferenceStencilLayout)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AttachmentDescriptionStencilLayout) {
	StructureClassHeader(AttachmentDescriptionStencilLayout);
	DefineSetter_Copy(StencilInitialLayout, VkImageLayout, stencilInitialLayout);
	DefineSetter_Copy(StencilFinalLayout, VkImageLayout, stencilFinalLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentDescriptionStencilLayout)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceHostQueryResetFeatures) {
	StructureClassHeader(PhysicalDeviceHostQueryResetFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceHostQueryResetFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTimelineSemaphoreFeatures) {
	StructureClassHeader(PhysicalDeviceTimelineSemaphoreFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTimelineSemaphoreFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTimelineSemaphoreProperties) {
	StructureClassHeader(PhysicalDeviceTimelineSemaphoreProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTimelineSemaphoreProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SemaphoreTypeCreateInfo) {
	StructureClassHeader(SemaphoreTypeCreateInfo);
	DefineSetter_Copy(SemaphoreType, VkSemaphoreType, semaphoreType);
	DefineSetter_Copy(InitialValue, uint64_t, initialValue);
};
VK_ENCAPSULATION_STRUCTURE_END(SemaphoreTypeCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TimelineSemaphoreSubmitInfo) {
	StructureClassHeader(TimelineSemaphoreSubmitInfo);
	DefineSetter_Copy(WaitSemaphoreValueCount, uint32_t, waitSemaphoreValueCount);
	DefineSetter_ArrayRef(WaitSemaphoreValues, const uint64_t, waitSemaphoreValues, waitSemaphoreValueCount);
	DefineSetter_Copy(SignalSemaphoreValueCount, uint32_t, signalSemaphoreValueCount);
	DefineSetter_ArrayRef(SignalSemaphoreValues, const uint64_t, signalSemaphoreValues, signalSemaphoreValueCount);
};
VK_ENCAPSULATION_STRUCTURE_END(TimelineSemaphoreSubmitInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SemaphoreWaitInfo) {
	StructureClassHeader(SemaphoreWaitInfo);
	DefineSetter_Copy(Flags, VkSemaphoreWaitFlags, flags);
	DefineSetter_Copy(SemaphoreCount, uint32_t, semaphoreCount);
	DefineSetter_ArrayRef(Semaphores, const VkSemaphore, semaphores, semaphoreCount);
	DefineSetter_ArrayRefIgnoreC(Values, const uint64_t, values);
};
VK_ENCAPSULATION_STRUCTURE_END(SemaphoreWaitInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SemaphoreSignalInfo) {
	StructureClassHeader(SemaphoreSignalInfo);
	DefineSetter_Copy(Semaphore, VkSemaphore, semaphore);
	DefineSetter_Copy(Value, uint64_t, value);
};
VK_ENCAPSULATION_STRUCTURE_END(SemaphoreSignalInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceBufferDeviceAddressFeatures) {
	StructureClassHeader(PhysicalDeviceBufferDeviceAddressFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceBufferDeviceAddressFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferDeviceAddressInfo) {
	StructureClassHeader(BufferDeviceAddressInfo);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferDeviceAddressInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferOpaqueCaptureAddressCreateInfo) {
	StructureClassHeader(BufferOpaqueCaptureAddressCreateInfo);
	DefineSetter_Copy(OpaqueCaptureAddress, uint64_t, opaqueCaptureAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferOpaqueCaptureAddressCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryOpaqueCaptureAddressAllocateInfo) {
	StructureClassHeader(MemoryOpaqueCaptureAddressAllocateInfo);
	DefineSetter_Copy(OpaqueCaptureAddress, uint64_t, opaqueCaptureAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryOpaqueCaptureAddressAllocateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceMemoryOpaqueCaptureAddressInfo) {
	StructureClassHeader(DeviceMemoryOpaqueCaptureAddressInfo);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceMemoryOpaqueCaptureAddressInfo)

inline void CmdDrawIndirectCount(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndirectCount(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

inline void CmdDrawIndexedIndirectCount(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndexedIndirectCount(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

inline VkResult CreateRenderPass2(const VkRenderPassCreateInfo2& createInfo, HandleRef<VkRenderPass> renderPass) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateRenderPass2(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &renderPass);
}
DefineRaiiFunction_ResultL(VkResult, CreateRenderPass2, RenderPassCreateInfo2, HandleRef<VkRenderPass>, renderPass);

inline void CmdBeginRenderPass2(const VkRenderPassBeginInfo& renderPassBegin, const VkSubpassBeginInfo& subpassBeginInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginRenderPass2(ThreadContext::CommandBuffer(), &renderPassBegin, &subpassBeginInfo);
}
DefineRaiiFunction_TwoStruct(CmdBeginRenderPass2, RenderPassBeginInfo, SubpassBeginInfo,
	DefineSetter_Copy(RenderPass, VkRenderPass, renderPass)
	DefineSetter_Copy(Framebuffer, VkFramebuffer, framebuffer)
	DefineSetter_Copy(RenderArea, VkRect2D, renderArea)
	DefineSetter_ArrayRef(ClearValues, const VkClearValue, clearValues, clearValueCount)
	DefineSetter_Copy(Contents, VkSubpassContents, contents));

inline void CmdNextSubpass2(const VkSubpassBeginInfo& subpassBeginInfo, const VkSubpassEndInfo& subpassEndInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdNextSubpass2(ThreadContext::CommandBuffer(), &subpassBeginInfo, &subpassEndInfo);
}
DefineRaiiFunction_TwoStruct(CmdNextSubpass2, SubpassBeginInfo, SubpassEndInfo,
	DefineSetter_Copy(Contents, VkSubpassContents, contents));

inline void CmdEndRenderPass2(const VkSubpassEndInfo& subpassEndInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndRenderPass2(ThreadContext::CommandBuffer(), &subpassEndInfo);
}
DefineRaiiFunction(CmdEndRenderPass2, SubpassEndInfo);

inline void ResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkResetQueryPool(DeviceContext::Device(), queryPool, firstQuery, queryCount);
}

inline VkResult GetSemaphoreCounterValue(VkSemaphore semaphore, uint64_t& value) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetSemaphoreCounterValue(DeviceContext::Device(), semaphore, &value);
}

inline VkResult WaitSemaphores(const VkSemaphoreWaitInfo& waitInfo, uint64_t timeout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkWaitSemaphores(DeviceContext::Device(), &waitInfo, timeout);
}
DefineRaiiFunction_ResultL(VkResult, WaitSemaphores, SemaphoreWaitInfo, uint64_t, timeout);

inline VkResult SignalSemaphore(const VkSemaphoreSignalInfo& signalInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkSignalSemaphore(DeviceContext::Device(), &signalInfo);
}
DefineRaiiFunction_Result(VkResult, SignalSemaphore, SemaphoreSignalInfo);

inline VkDeviceAddress GetBufferDeviceAddress(const VkBufferDeviceAddressInfo& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferDeviceAddress(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkDeviceAddress, GetBufferDeviceAddress, BufferDeviceAddressInfo);

inline uint64_t GetBufferOpaqueCaptureAddress(const VkBufferDeviceAddressInfo& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferOpaqueCaptureAddress(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(uint64_t, GetBufferOpaqueCaptureAddress, BufferDeviceAddressInfo);

inline uint64_t GetDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceMemoryOpaqueCaptureAddress(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(uint64_t, GetDeviceMemoryOpaqueCaptureAddress, DeviceMemoryOpaqueCaptureAddressInfo);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan13Features) {
	StructureClassHeader(PhysicalDeviceVulkan13Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan13Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan13Properties) {
	StructureClassHeader(PhysicalDeviceVulkan13Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan13Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PipelineCreationFeedback) {
	StructureClassHeader_NoSType(PipelineCreationFeedback);
	DefineSetter_Copy(Flags, VkPipelineCreationFeedbackFlags, flags);
	DefineSetter_Copy(Duration, uint64_t, duration);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCreationFeedback)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCreationFeedbackCreateInfo) {
	StructureClassHeader(PipelineCreationFeedbackCreateInfo);
	DefineSetter_Ref(PipelineCreationFeedback, VkPipelineCreationFeedback, pipelineCreationFeedback);
	DefineSetter_Copy(PipelineStageCreationFeedbackCount, uint32_t, pipelineStageCreationFeedbackCount);
	DefineSetter_ArrayRef(PipelineStageCreationFeedbacks, VkPipelineCreationFeedback, pipelineStageCreationFeedbacks, pipelineStageCreationFeedbackCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCreationFeedbackCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderTerminateInvocationFeatures) {
	StructureClassHeader(PhysicalDeviceShaderTerminateInvocationFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderTerminateInvocationFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceToolProperties) {
	StructureClassHeader(PhysicalDeviceToolProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceToolProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderDemoteToHelperInvocationFeatures) {
	StructureClassHeader(PhysicalDeviceShaderDemoteToHelperInvocationFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderDemoteToHelperInvocationFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePrivateDataFeatures) {
	StructureClassHeader(PhysicalDevicePrivateDataFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePrivateDataFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DevicePrivateDataCreateInfo) {
	StructureClassHeader(DevicePrivateDataCreateInfo);
	DefineSetter_Copy(PrivateDataSlotRequestCount, uint32_t, privateDataSlotRequestCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DevicePrivateDataCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PrivateDataSlotCreateInfo) {
	StructureClassHeader(PrivateDataSlotCreateInfo);
	DefineSetter_Copy(Flags, VkPrivateDataSlotCreateFlags, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(PrivateDataSlotCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineCreationCacheControlFeatures) {
	StructureClassHeader(PhysicalDevicePipelineCreationCacheControlFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineCreationCacheControlFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryBarrier2) {
	StructureClassHeader(MemoryBarrier2);
	DefineSetter_Copy(SrcStageMask, VkPipelineStageFlags2, srcStageMask);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags2, srcAccessMask);
	DefineSetter_Copy(DstStageMask, VkPipelineStageFlags2, dstStageMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags2, dstAccessMask);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryBarrier2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferMemoryBarrier2) {
	StructureClassHeader(BufferMemoryBarrier2, .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED, .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED, .size = VK_WHOLE_SIZE);
	DefineSetter_Copy(SrcStageMask, VkPipelineStageFlags2, srcStageMask);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags2, srcAccessMask);
	DefineSetter_Copy(DstStageMask, VkPipelineStageFlags2, dstStageMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags2, dstAccessMask);
	DefineSetter_Copy(SrcQueueFamilyIndex, uint32_t, srcQueueFamilyIndex);
	DefineSetter_Copy(DstQueueFamilyIndex, uint32_t, dstQueueFamilyIndex);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferMemoryBarrier2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageMemoryBarrier2) {
	StructureClassHeader(ImageMemoryBarrier2, .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED, .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED);
	DefineSetter_Copy(SrcStageMask, VkPipelineStageFlags2, srcStageMask);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags2, srcAccessMask);
	DefineSetter_Copy(DstStageMask, VkPipelineStageFlags2, dstStageMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags2, dstAccessMask);
	DefineSetter_Copy(OldLayout, VkImageLayout, oldLayout);
	DefineSetter_Copy(NewLayout, VkImageLayout, newLayout);
	DefineSetter_Copy(SrcQueueFamilyIndex, uint32_t, srcQueueFamilyIndex);
	DefineSetter_Copy(DstQueueFamilyIndex, uint32_t, dstQueueFamilyIndex);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(SubresourceRange, VkImageSubresourceRange, subresourceRange);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageMemoryBarrier2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DependencyInfo) {
	StructureClassHeader(DependencyInfo);
	DefineSetter_Copy(DependencyFlags, VkDependencyFlags, dependencyFlags);
	DefineSetter_Copy(MemoryBarrierCount, uint32_t, memoryBarrierCount);
	DefineSetter_ArrayRef(MemoryBarriers, const VkMemoryBarrier2, memoryBarriers, memoryBarrierCount);
	DefineSetter_Copy(BufferMemoryBarrierCount, uint32_t, bufferMemoryBarrierCount);
	DefineSetter_ArrayRef(BufferMemoryBarriers, const VkBufferMemoryBarrier2, bufferMemoryBarriers, bufferMemoryBarrierCount);
	DefineSetter_Copy(ImageMemoryBarrierCount, uint32_t, imageMemoryBarrierCount);
	DefineSetter_ArrayRef(ImageMemoryBarriers, const VkImageMemoryBarrier2, imageMemoryBarriers, imageMemoryBarrierCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DependencyInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SemaphoreSubmitInfo) {
	StructureClassHeader(SemaphoreSubmitInfo);
	DefineSetter_Copy(Semaphore, VkSemaphore, semaphore);
	DefineSetter_Copy(Value, uint64_t, value);
	DefineSetter_Copy(StageMask, VkPipelineStageFlags2, stageMask);
	DefineSetter_Copy(DeviceIndex, uint32_t, deviceIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(SemaphoreSubmitInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferSubmitInfo) {
	StructureClassHeader(CommandBufferSubmitInfo);
	DefineSetter_Copy(CommandBuffer, VkCommandBuffer, commandBuffer);
	DefineSetter_Copy(DeviceMask, uint32_t, deviceMask);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferSubmitInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubmitInfo2) {
	StructureClassHeader(SubmitInfo2);
	DefineSetter_Copy(Flags, VkSubmitFlags, flags);
	DefineSetter_Copy(WaitSemaphoreInfoCount, uint32_t, waitSemaphoreInfoCount);
	DefineSetter_ArrayRef(WaitSemaphoreInfos, const VkSemaphoreSubmitInfo, waitSemaphoreInfos, waitSemaphoreInfoCount);
	DefineSetter_Copy(CommandBufferInfoCount, uint32_t, commandBufferInfoCount);
	DefineSetter_ArrayRef(CommandBufferInfos, const VkCommandBufferSubmitInfo, commandBufferInfos, commandBufferInfoCount);
	DefineSetter_Copy(SignalSemaphoreInfoCount, uint32_t, signalSemaphoreInfoCount);
	DefineSetter_ArrayRef(SignalSemaphoreInfos, const VkSemaphoreSubmitInfo, signalSemaphoreInfos, signalSemaphoreInfoCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SubmitInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSynchronization2Features) {
	StructureClassHeader(PhysicalDeviceSynchronization2Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSynchronization2Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures) {
	StructureClassHeader(PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageRobustnessFeatures) {
	StructureClassHeader(PhysicalDeviceImageRobustnessFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageRobustnessFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferCopy2) {
	StructureClassHeader(BufferCopy2);
	DefineSetter_Copy(SrcOffset, VkDeviceSize, srcOffset);
	DefineSetter_Copy(DstOffset, VkDeviceSize, dstOffset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferCopy2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyBufferInfo2) {
	StructureClassHeader(CopyBufferInfo2);
	DefineSetter_Copy(SrcBuffer, VkBuffer, srcBuffer);
	DefineSetter_Copy(DstBuffer, VkBuffer, dstBuffer);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkBufferCopy2, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyBufferInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageCopy2) {
	StructureClassHeader(ImageCopy2);
	DefineSetter_Copy(SrcSubresource, VkImageSubresourceLayers, srcSubresource);
	DefineSetter_Copy(SrcOffset, VkOffset3D, srcOffset);
	DefineSetter_Copy(DstSubresource, VkImageSubresourceLayers, dstSubresource);
	DefineSetter_Copy(DstOffset, VkOffset3D, dstOffset);
	DefineSetter_Copy(Extent, VkExtent3D, extent);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageCopy2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyImageInfo2) {
	StructureClassHeader(CopyImageInfo2);
	DefineSetter_Copy(SrcImage, VkImage, srcImage);
	DefineSetter_Copy(SrcImageLayout, VkImageLayout, srcImageLayout);
	DefineSetter_Copy(DstImage, VkImage, dstImage);
	DefineSetter_Copy(DstImageLayout, VkImageLayout, dstImageLayout);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkImageCopy2, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyImageInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferImageCopy2) {
	StructureClassHeader(BufferImageCopy2);
	DefineSetter_Copy(BufferOffset, VkDeviceSize, bufferOffset);
	DefineSetter_Copy(BufferRowLength, uint32_t, bufferRowLength);
	DefineSetter_Copy(BufferImageHeight, uint32_t, bufferImageHeight);
	DefineSetter_Copy(ImageSubresource, VkImageSubresourceLayers, imageSubresource);
	DefineSetter_Copy(ImageOffset, VkOffset3D, imageOffset);
	DefineSetter_Copy(ImageExtent, VkExtent3D, imageExtent);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferImageCopy2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyBufferToImageInfo2) {
	StructureClassHeader(CopyBufferToImageInfo2);
	DefineSetter_Copy(SrcBuffer, VkBuffer, srcBuffer);
	DefineSetter_Copy(DstImage, VkImage, dstImage);
	DefineSetter_Copy(DstImageLayout, VkImageLayout, dstImageLayout);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkBufferImageCopy2, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyBufferToImageInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyImageToBufferInfo2) {
	StructureClassHeader(CopyImageToBufferInfo2);
	DefineSetter_Copy(SrcImage, VkImage, srcImage);
	DefineSetter_Copy(SrcImageLayout, VkImageLayout, srcImageLayout);
	DefineSetter_Copy(DstBuffer, VkBuffer, dstBuffer);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkBufferImageCopy2, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyImageToBufferInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageBlit2) {
	StructureClassHeader(ImageBlit2);
	DefineSetter_Copy(SrcSubresource, VkImageSubresourceLayers, srcSubresource);
	// VkOffset3D srcOffsets[2];
	DefineSetter_ArrayCopy(SrcOffsets, VkOffset3D, srcOffsets);
	DefineSetter_Copy(DstSubresource, VkImageSubresourceLayers, dstSubresource);
	// VkOffset3D dstOffsets[2];
	DefineSetter_ArrayCopy(DstOffsets, VkOffset3D, dstOffsets);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageBlit2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BlitImageInfo2) {
	StructureClassHeader(BlitImageInfo2);
	DefineSetter_Copy(SrcImage, VkImage, srcImage);
	DefineSetter_Copy(SrcImageLayout, VkImageLayout, srcImageLayout);
	DefineSetter_Copy(DstImage, VkImage, dstImage);
	DefineSetter_Copy(DstImageLayout, VkImageLayout, dstImageLayout);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkImageBlit2, regions, regionCount);
	DefineSetter_Copy(Filter, VkFilter, filter);
};
VK_ENCAPSULATION_STRUCTURE_END(BlitImageInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageResolve2) {
	StructureClassHeader(ImageResolve2);
	DefineSetter_Copy(SrcSubresource, VkImageSubresourceLayers, srcSubresource);
	DefineSetter_Copy(SrcOffset, VkOffset3D, srcOffset);
	DefineSetter_Copy(DstSubresource, VkImageSubresourceLayers, dstSubresource);
	DefineSetter_Copy(DstOffset, VkOffset3D, dstOffset);
	DefineSetter_Copy(Extent, VkExtent3D, extent);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageResolve2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ResolveImageInfo2) {
	StructureClassHeader(ResolveImageInfo2);
	DefineSetter_Copy(SrcImage, VkImage, srcImage);
	DefineSetter_Copy(SrcImageLayout, VkImageLayout, srcImageLayout);
	DefineSetter_Copy(DstImage, VkImage, dstImage);
	DefineSetter_Copy(DstImageLayout, VkImageLayout, dstImageLayout);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkImageResolve2, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ResolveImageInfo2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSubgroupSizeControlFeatures) {
	StructureClassHeader(PhysicalDeviceSubgroupSizeControlFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSubgroupSizeControlFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSubgroupSizeControlProperties) {
	StructureClassHeader(PhysicalDeviceSubgroupSizeControlProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSubgroupSizeControlProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineShaderStageRequiredSubgroupSizeCreateInfo) {
	StructureClassHeader(PipelineShaderStageRequiredSubgroupSizeCreateInfo);
	DefineSetter_Copy(RequiredSubgroupSize, uint32_t, requiredSubgroupSize);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineShaderStageRequiredSubgroupSizeCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceInlineUniformBlockFeatures) {
	StructureClassHeader(PhysicalDeviceInlineUniformBlockFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceInlineUniformBlockFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceInlineUniformBlockProperties) {
	StructureClassHeader(PhysicalDeviceInlineUniformBlockProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceInlineUniformBlockProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteDescriptorSetInlineUniformBlock) {
	StructureClassHeader(WriteDescriptorSetInlineUniformBlock);
	DefineSetter_Copy(DataSize, uint32_t, dataSize);
	DefineSetter_ArrayRef(Data, const void, data, dataSize);
	_&  Data(const IsNotRangeOrPointer auto& data) &  { return Data({ sizeof *&data, &data }); }
	_&& Data(const IsNotRangeOrPointer auto& data) && { return std::move(Data(data)); }
	_&  Data(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(WriteDescriptorSetInlineUniformBlock)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorPoolInlineUniformBlockCreateInfo) {
	StructureClassHeader(DescriptorPoolInlineUniformBlockCreateInfo);
	DefineSetter_Copy(MaxInlineUniformBlockBindings, uint32_t, maxInlineUniformBlockBindings);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorPoolInlineUniformBlockCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTextureCompressionASTCHDRFeatures) {
	StructureClassHeader(PhysicalDeviceTextureCompressionASTCHDRFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTextureCompressionASTCHDRFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingAttachmentInfo) {
	StructureClassHeader(RenderingAttachmentInfo);
	DefineSetter_Copy(ImageView, VkImageView, imageView);
	DefineSetter_Copy(ImageLayout, VkImageLayout, imageLayout);
	DefineSetter_Copy(ResolveMode, VkResolveModeFlagBits, resolveMode);
	DefineSetter_Copy(ResolveImageView, VkImageView, resolveImageView);
	DefineSetter_Copy(ResolveImageLayout, VkImageLayout, resolveImageLayout);
	DefineSetter_Copy(LoadOp, VkAttachmentLoadOp, loadOp);
	DefineSetter_Copy(StoreOp, VkAttachmentStoreOp, storeOp);
	DefineSetter_CopyOptional(ClearValue, VkClearValue, clearValue, loadOp, VK_ATTACHMENT_LOAD_OP_CLEAR);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingAttachmentInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingInfo) {
	StructureClassHeader(RenderingInfo, .layerCount = 1);
	DefineSetter_Copy(Flags, VkRenderingFlags, flags);
	DefineSetter_Copy(RenderArea, VkRect2D, renderArea);
	DefineSetter_Copy(LayerCount, uint32_t, layerCount);
	DefineSetter_Copy(ViewMask, uint32_t, viewMask);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachments, const VkRenderingAttachmentInfo, colorAttachments, colorAttachmentCount);
	DefineSetter_Ref(DepthAttachment, const VkRenderingAttachmentInfo, depthAttachment);
	DefineSetter_Ref(StencilAttachment, const VkRenderingAttachmentInfo, stencilAttachment);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRenderingCreateInfo) {
	StructureClassHeader(PipelineRenderingCreateInfo);
	DefineSetter_Copy(ViewMask, uint32_t, viewMask);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachmentFormats, const VkFormat, colorAttachmentFormats, colorAttachmentCount);
	DefineSetter_Copy(DepthAttachmentFormat, VkFormat, depthAttachmentFormat);
	DefineSetter_Copy(StencilAttachmentFormat, VkFormat, stencilAttachmentFormat);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRenderingCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDynamicRenderingFeatures) {
	StructureClassHeader(PhysicalDeviceDynamicRenderingFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDynamicRenderingFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferInheritanceRenderingInfo) {
	StructureClassHeader(CommandBufferInheritanceRenderingInfo, .rasterizationSamples = VK_SAMPLE_COUNT_1_BIT);
	DefineSetter_Copy(Flags, VkRenderingFlags, flags);
	DefineSetter_Copy(ViewMask, uint32_t, viewMask);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachmentFormats, const VkFormat, colorAttachmentFormats, colorAttachmentCount);
	DefineSetter_Copy(DepthAttachmentFormat, VkFormat, depthAttachmentFormat);
	DefineSetter_Copy(StencilAttachmentFormat, VkFormat, stencilAttachmentFormat);
	DefineSetter_Copy(RasterizationSamples, VkSampleCountFlagBits, rasterizationSamples);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferInheritanceRenderingInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderIntegerDotProductFeatures) {
	StructureClassHeader(PhysicalDeviceShaderIntegerDotProductFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderIntegerDotProductFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderIntegerDotProductProperties) {
	StructureClassHeader(PhysicalDeviceShaderIntegerDotProductProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderIntegerDotProductProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTexelBufferAlignmentProperties) {
	StructureClassHeader(PhysicalDeviceTexelBufferAlignmentProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTexelBufferAlignmentProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FormatProperties3) {
	StructureClassHeader(FormatProperties3);
};
VK_ENCAPSULATION_STRUCTURE_END(FormatProperties3)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance4Features) {
	StructureClassHeader(PhysicalDeviceMaintenance4Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance4Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance4Properties) {
	StructureClassHeader(PhysicalDeviceMaintenance4Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance4Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceBufferMemoryRequirements) {
	StructureClassHeader(DeviceBufferMemoryRequirements);
	DefineSetter_Ref(CreateInfo, const VkBufferCreateInfo, createInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceBufferMemoryRequirements)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceImageMemoryRequirements) {
	StructureClassHeader(DeviceImageMemoryRequirements);
	DefineSetter_Ref(CreateInfo, const VkImageCreateInfo, createInfo);
	DefineSetter_Copy(PlaneAspect, VkImageAspectFlagBits, planeAspect);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceImageMemoryRequirements)

inline VkResult GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t& toolCount, ArrayRef<VkPhysicalDeviceToolProperties> toolProperties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceToolProperties(physicalDevice, &toolCount, toolProperties);
}
inline VkResult GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, IsDynamicArray<VkPhysicalDeviceToolProperties> auto& toolProperties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceToolProperties(physicalDevice, count);
	if (result == VK_SUCCESS)
		toolProperties.resize(count),
		result = GetPhysicalDeviceToolProperties(physicalDevice, count, toolProperties);
	return result;
}
inline VkResult GetPhysicalDeviceToolProperties(uint32_t& toolCount, ArrayRef<VkPhysicalDeviceToolProperties> toolProperties = {}) {
	return GetPhysicalDeviceToolProperties(DeviceContext::PhysicalDevice(), toolCount, toolProperties);
}
inline VkResult GetPhysicalDeviceToolProperties(IsDynamicArray<VkPhysicalDeviceToolProperties> auto& toolProperties) {
	return GetPhysicalDeviceToolProperties(DeviceContext::PhysicalDevice(), toolProperties);
}

inline VkResult CreatePrivateDataSlot(const VkPrivateDataSlotCreateInfo& createInfo, HandleRef<VkPrivateDataSlot> privateDataSlot) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreatePrivateDataSlot(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &privateDataSlot);
}
DefineRaiiFunction_ResultL(VkResult, CreatePrivateDataSlot, PrivateDataSlotCreateInfo, HandleRef<VkPrivateDataSlot>, privateDataSlot);

inline void DestroyPrivateDataSlot(HandleRef<VkPrivateDataSlot> privateDataSlot, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyPrivateDataSlot(DeviceContext::Device(), privateDataSlot, &allocator);
	privateDataSlot = VK_NULL_HANDLE;
}

inline VkResult SetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkSetPrivateData(DeviceContext::Device(), objectType, objectHandle, privateDataSlot, data);
}

inline void GetPrivateData(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t& data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPrivateData(DeviceContext::Device(), objectType, objectHandle, privateDataSlot, &data);
}

inline void CmdSetEvent2(VkEvent event, const VkDependencyInfo& dependencyInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetEvent2(ThreadContext::CommandBuffer(), event, &dependencyInfo);
}
DefineRaiiFunction_R(CmdSetEvent2, VkEvent, event, DependencyInfo);

inline void CmdResetEvent2(VkEvent event, VkPipelineStageFlags2 stageMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdResetEvent2(ThreadContext::CommandBuffer(), event, stageMask);
}

inline void CmdWaitEvents2(ArrayRef<const VkEvent> events, ArrayRef<const VkDependencyInfo> dependencyInfos) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWaitEvents2(ThreadContext::CommandBuffer(), events.size(), events, dependencyInfos);
}
DefineRaiiFunction_R(CmdWaitEvents2, VkEvent, event, DependencyInfo);

inline void CmdPipelineBarrier2(const VkDependencyInfo& dependencyInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPipelineBarrier2(ThreadContext::CommandBuffer(), &dependencyInfo);
}
DefineRaiiFunction(CmdPipelineBarrier2, DependencyInfo);

inline void CmdWriteTimestamp2(VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteTimestamp2(ThreadContext::CommandBuffer(), stage, queryPool, query);
}

inline VkResult QueueSubmit2(VkQueue queue, ArrayRef<const VkSubmitInfo2> submits, VkFence fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkQueueSubmit2(queue, submits.size(), submits, fence);
}
inline VkResult QueueSubmit2(ArrayRef<const VkSubmitInfo2> submits, VkFence fence) {
	return QueueSubmit2(ThreadContext::Queue(), submits, fence);
}
DefineRaiiFunction_ResultL(VkResult, QueueSubmit2, SubmitInfo2, VkFence, fence);

inline void CmdCopyBuffer2(const VkCopyBufferInfo2& copyBufferInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyBuffer2(ThreadContext::CommandBuffer(), &copyBufferInfo);
}
DefineRaiiFunction(CmdCopyBuffer2, CopyBufferInfo2);

inline void CmdCopyImage2(const VkCopyImageInfo2& copyImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyImage2(ThreadContext::CommandBuffer(), &copyImageInfo);
}
DefineRaiiFunction(CmdCopyImage2, CopyImageInfo2);

inline void CmdCopyBufferToImage2(const VkCopyBufferToImageInfo2& copyBufferToImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyBufferToImage2(ThreadContext::CommandBuffer(), &copyBufferToImageInfo);
}
DefineRaiiFunction(CmdCopyBufferToImage2, CopyBufferToImageInfo2);

inline void CmdCopyImageToBuffer2(const VkCopyImageToBufferInfo2& copyImageToBufferInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyImageToBuffer2(ThreadContext::CommandBuffer(), &copyImageToBufferInfo);
}
DefineRaiiFunction(CmdCopyImageToBuffer2, CopyImageToBufferInfo2);

inline void CmdBlitImage2(const VkBlitImageInfo2& blitImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBlitImage2(ThreadContext::CommandBuffer(), &blitImageInfo);
}
DefineRaiiFunction(CmdBlitImage2, BlitImageInfo2);

inline void CmdResolveImage2(const VkResolveImageInfo2& resolveImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdResolveImage2(ThreadContext::CommandBuffer(), &resolveImageInfo);
}
DefineRaiiFunction(CmdResolveImage2, ResolveImageInfo2);

inline void CmdBeginRendering(const VkRenderingInfo& renderingInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginRendering(ThreadContext::CommandBuffer(), &renderingInfo);
}
DefineRaiiFunction(CmdBeginRendering, RenderingInfo);

inline void CmdEndRendering() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndRendering(ThreadContext::CommandBuffer());
}

inline void CmdSetCullMode(VkCullModeFlags cullMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCullMode(ThreadContext::CommandBuffer(), cullMode);
}

inline void CmdSetFrontFace(VkFrontFace frontFace) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetFrontFace(ThreadContext::CommandBuffer(), frontFace);
}

inline void CmdSetPrimitiveTopology(VkPrimitiveTopology primitiveTopology) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPrimitiveTopology(ThreadContext::CommandBuffer(), primitiveTopology);
}

inline void CmdSetViewportWithCount(ArrayRef<const VkViewport> viewports) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetViewportWithCount(ThreadContext::CommandBuffer(), viewports.size(), viewports);
}

inline void CmdSetScissorWithCount(ArrayRef<const VkRect2D> scissors) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetScissorWithCount(ThreadContext::CommandBuffer(), scissors.size(), scissors);
}

inline void CmdBindVertexBuffers2(uint32_t firstBinding, ArrayRef<const VkBuffer> buffers, ArrayRef<const VkDeviceSize> offsets, ArrayRef<const VkDeviceSize> sizes, ArrayRef<const VkDeviceSize> strides) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindVertexBuffers2(ThreadContext::CommandBuffer(), firstBinding, buffers.size(), buffers, offsets, sizes, strides);
}

inline void CmdSetDepthTestEnable(VkBool32 depthTestEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthTestEnable(ThreadContext::CommandBuffer(), depthTestEnable);
}

inline void CmdSetDepthWriteEnable(VkBool32 depthWriteEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthWriteEnable(ThreadContext::CommandBuffer(), depthWriteEnable);
}

inline void CmdSetDepthCompareOp(VkCompareOp depthCompareOp) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthCompareOp(ThreadContext::CommandBuffer(), depthCompareOp);
}

inline void CmdSetDepthBoundsTestEnable(VkBool32 depthBoundsTestEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthBoundsTestEnable(ThreadContext::CommandBuffer(), depthBoundsTestEnable);
}

inline void CmdSetStencilTestEnable(VkBool32 stencilTestEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetStencilTestEnable(ThreadContext::CommandBuffer(), stencilTestEnable);
}

inline void CmdSetStencilOp(VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetStencilOp(ThreadContext::CommandBuffer(), faceMask, failOp, passOp, depthFailOp, compareOp);
}

inline void CmdSetRasterizerDiscardEnable(VkBool32 rasterizerDiscardEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRasterizerDiscardEnable(ThreadContext::CommandBuffer(), rasterizerDiscardEnable);
}

inline void CmdSetDepthBiasEnable(VkBool32 depthBiasEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthBiasEnable(ThreadContext::CommandBuffer(), depthBiasEnable);
}

inline void CmdSetPrimitiveRestartEnable(VkBool32 primitiveRestartEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPrimitiveRestartEnable(ThreadContext::CommandBuffer(), primitiveRestartEnable);
}

inline void GetDeviceBufferMemoryRequirements(const VkDeviceBufferMemoryRequirements& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceBufferMemoryRequirements(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetDeviceBufferMemoryRequirements, DeviceBufferMemoryRequirements, VkMemoryRequirements2&, memoryRequirements);

inline void GetDeviceImageMemoryRequirements(const VkDeviceImageMemoryRequirements& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceImageMemoryRequirements(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetDeviceImageMemoryRequirements, DeviceImageMemoryRequirements, VkMemoryRequirements2&, memoryRequirements);

inline void GetDeviceImageSparseMemoryRequirements(const VkDeviceImageMemoryRequirements& info, uint32_t& sparseMemoryRequirementCount, ArrayRef<VkSparseImageMemoryRequirements2> sparseMemoryRequirements = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceImageSparseMemoryRequirements(DeviceContext::Device(), &info, &sparseMemoryRequirementCount, sparseMemoryRequirements);
}
inline void GetDeviceImageSparseMemoryRequirements(const VkDeviceImageMemoryRequirements& info, IsDynamicArray<VkSparseImageMemoryRequirements2> auto& sparseMemoryRequirements) {
	uint32_t count = 0;
	GetDeviceImageSparseMemoryRequirements(info, count);
	sparseMemoryRequirements.resize(count);
	GetDeviceImageSparseMemoryRequirements(info, count, sparseMemoryRequirements);
}
DefineRaiiFunction_L(GetDeviceImageSparseMemoryRequirements, DeviceImageMemoryRequirements, IsDynamicArray<VkSparseImageMemoryRequirements2> auto&, sparseMemoryRequirements);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan14Features) {
	StructureClassHeader(PhysicalDeviceVulkan14Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan14Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVulkan14Properties) {
	StructureClassHeader(PhysicalDeviceVulkan14Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVulkan14Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceQueueGlobalPriorityCreateInfo) {
	StructureClassHeader(DeviceQueueGlobalPriorityCreateInfo);
	DefineSetter_Copy(GlobalPriority, VkQueueGlobalPriority, globalPriority);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceQueueGlobalPriorityCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceGlobalPriorityQueryFeatures) {
	StructureClassHeader(PhysicalDeviceGlobalPriorityQueryFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceGlobalPriorityQueryFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyGlobalPriorityProperties) {
	StructureClassHeader(QueueFamilyGlobalPriorityProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyGlobalPriorityProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderSubgroupRotateFeatures) {
	StructureClassHeader(PhysicalDeviceShaderSubgroupRotateFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderSubgroupRotateFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderFloatControls2Features) {
	StructureClassHeader(PhysicalDeviceShaderFloatControls2Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderFloatControls2Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderExpectAssumeFeatures) {
	StructureClassHeader(PhysicalDeviceShaderExpectAssumeFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderExpectAssumeFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLineRasterizationFeatures) {
	StructureClassHeader(PhysicalDeviceLineRasterizationFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLineRasterizationFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLineRasterizationProperties) {
	StructureClassHeader(PhysicalDeviceLineRasterizationProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLineRasterizationProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRasterizationLineStateCreateInfo) {
	StructureClassHeader(PipelineRasterizationLineStateCreateInfo);
	DefineSetter_Copy(LineRasterizationMode, VkLineRasterizationMode, lineRasterizationMode);
	DefineSetter_Copy(StippledLineEnable, VkBool32, stippledLineEnable);
	DefineSetter_CopyOptional(LineStippleFactor, uint32_t, lineStippleFactor, stippledLineEnable, true);
	DefineSetter_Copy(LineStipplePattern, uint16_t, lineStipplePattern);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRasterizationLineStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVertexAttributeDivisorProperties) {
	StructureClassHeader(PhysicalDeviceVertexAttributeDivisorProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVertexAttributeDivisorProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VertexInputBindingDivisorDescription) {
	StructureClassHeader_NoSType(VertexInputBindingDivisorDescription);
	DefineSetter_Copy(Binding, uint32_t, binding);
	DefineSetter_Copy(Divisor, uint32_t, divisor);
};
VK_ENCAPSULATION_STRUCTURE_END(VertexInputBindingDivisorDescription)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineVertexInputDivisorStateCreateInfo) {
	StructureClassHeader(PipelineVertexInputDivisorStateCreateInfo);
	DefineSetter_Copy(VertexBindingDivisorCount, uint32_t, vertexBindingDivisorCount);
	DefineSetter_ArrayRef(VertexBindingDivisors, const VkVertexInputBindingDivisorDescription, vertexBindingDivisors, vertexBindingDivisorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineVertexInputDivisorStateCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVertexAttributeDivisorFeatures) {
	StructureClassHeader(PhysicalDeviceVertexAttributeDivisorFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVertexAttributeDivisorFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceIndexTypeUint8Features) {
	StructureClassHeader(PhysicalDeviceIndexTypeUint8Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceIndexTypeUint8Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryMapInfo) {
	StructureClassHeader(MemoryMapInfo, .size = VK_WHOLE_SIZE);
	DefineSetter_Copy(Flags, VkMemoryMapFlags, flags);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryMapInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryUnmapInfo) {
	StructureClassHeader(MemoryUnmapInfo);
	DefineSetter_Copy(Flags, VkMemoryUnmapFlags, flags);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryUnmapInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance5Features) {
	StructureClassHeader(PhysicalDeviceMaintenance5Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance5Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance5Properties) {
	StructureClassHeader(PhysicalDeviceMaintenance5Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance5Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingAreaInfo) {
	StructureClassHeader(RenderingAreaInfo);
	DefineSetter_Copy(ViewMask, uint32_t, viewMask);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachmentFormats, const VkFormat, colorAttachmentFormats, colorAttachmentCount);
	DefineSetter_Copy(DepthAttachmentFormat, VkFormat, depthAttachmentFormat);
	DefineSetter_Copy(StencilAttachmentFormat, VkFormat, stencilAttachmentFormat);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingAreaInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageSubresource2) {
	StructureClassHeader(ImageSubresource2);
	DefineSetter_Copy(ImageSubresource, VkImageSubresource, imageSubresource);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageSubresource2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceImageSubresourceInfo) {
	StructureClassHeader(DeviceImageSubresourceInfo);
	DefineSetter_Ref(CreateInfo, const VkImageCreateInfo, createInfo);
	DefineSetter_Ref(Subresource, const VkImageSubresource2, subresource);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceImageSubresourceInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubresourceLayout2) {
	StructureClassHeader(SubresourceLayout2);
	DefineSetter_Copy(SubresourceLayout, VkSubresourceLayout, subresourceLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(SubresourceLayout2)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCreateFlags2CreateInfo) {
	StructureClassHeader(PipelineCreateFlags2CreateInfo);
	DefineSetter_Copy(Flags, VkPipelineCreateFlags2, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCreateFlags2CreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferUsageFlags2CreateInfo) {
	StructureClassHeader(BufferUsageFlags2CreateInfo);
	DefineSetter_Copy(Usage, VkBufferUsageFlags2, usage);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferUsageFlags2CreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePushDescriptorProperties) {
	StructureClassHeader(PhysicalDevicePushDescriptorProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePushDescriptorProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDynamicRenderingLocalReadFeatures) {
	StructureClassHeader(PhysicalDeviceDynamicRenderingLocalReadFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDynamicRenderingLocalReadFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingAttachmentLocationInfo) {
	StructureClassHeader(RenderingAttachmentLocationInfo);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachmentLocations, const uint32_t, colorAttachmentLocations, colorAttachmentCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingAttachmentLocationInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingInputAttachmentIndexInfo) {
	StructureClassHeader(RenderingInputAttachmentIndexInfo);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachmentInputIndices, const uint32_t, colorAttachmentInputIndices, colorAttachmentCount);
	DefineSetter_Ref(DepthInputAttachmentIndex, const uint32_t, depthInputAttachmentIndex);
	DefineSetter_Ref(StencilInputAttachmentIndex, const uint32_t, stencilInputAttachmentIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingInputAttachmentIndexInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance6Features) {
	StructureClassHeader(PhysicalDeviceMaintenance6Features);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance6Features)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance6Properties) {
	StructureClassHeader(PhysicalDeviceMaintenance6Properties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance6Properties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindMemoryStatus) {
	StructureClassHeader(BindMemoryStatus);
	DefineSetter_Ref(Result, VkResult, result);
#if defined VK_ENCAPSULATION_RESULT_THROW || defined VK_ENCAPSULATION_RESULT_NODISCARD
	_&  Result(OptionalRef<RESULT> result) &  { pResult = reinterpret_cast<VkResult*>(&result); return *this; }
	_&& Result(OptionalRef<RESULT> result) && { return std::move(Result(result)); }
	_&  Result(EmptyList) &  { pResult = nullptr; return *this; }
	_&& Result(EmptyList) && { return std::move(Result({})); }
#endif
};
VK_ENCAPSULATION_STRUCTURE_END(BindMemoryStatus)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindDescriptorSetsInfo) {
	StructureClassHeader(BindDescriptorSetsInfo);
	DefineSetter_Copy(StageFlags, VkShaderStageFlags, stageFlags);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(FirstSet, uint32_t, firstSet);
	DefineSetter_Copy(DescriptorSetCount, uint32_t, descriptorSetCount);
	DefineSetter_ArrayRef(DescriptorSets, const VkDescriptorSet, descriptorSets, descriptorSetCount);
	DefineSetter_Copy(DynamicOffsetCount, uint32_t, dynamicOffsetCount);
	DefineSetter_ArrayRef(DynamicOffsets, const uint32_t, dynamicOffsets, dynamicOffsetCount);
};
VK_ENCAPSULATION_STRUCTURE_END(BindDescriptorSetsInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PushConstantsInfo) {
	StructureClassHeader(PushConstantsInfo);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(StageFlags, VkShaderStageFlags, stageFlags);
	DefineSetter_Copy(Offset, uint32_t, offset);
	DefineSetter_Copy(Size, uint32_t, size);
	DefineSetter_ArrayRef(Values, const void, values, size);
	_&  Values(const IsNotRangeOrPointer auto& values) &  { return Values({ sizeof * &values, &values }); }
	_&& Values(const IsNotRangeOrPointer auto& values) && { return std::move(Values(values)); }
	_&  Values(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(PushConstantsInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PushDescriptorSetInfo) {
	StructureClassHeader(PushDescriptorSetInfo);
	DefineSetter_Copy(StageFlags, VkShaderStageFlags, stageFlags);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(Set, uint32_t, set);
	DefineSetter_Copy(DescriptorWriteCount, uint32_t, descriptorWriteCount);
	DefineSetter_ArrayRef(DescriptorWrites, const VkWriteDescriptorSet, descriptorWrites, descriptorWriteCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PushDescriptorSetInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PushDescriptorSetWithTemplateInfo) {
	StructureClassHeader(PushDescriptorSetWithTemplateInfo);
	DefineSetter_Copy(DescriptorUpdateTemplate, VkDescriptorUpdateTemplate, descriptorUpdateTemplate);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(Set, uint32_t, set);
	DefineSetter_ArrayRefIgnoreC(Data, const void, data);
	_&  Data(const IsNotRangeOrPointer auto& data) &  { pData = &data; return *this; }
	_&& Data(const IsNotRangeOrPointer auto& data) && { return std::move(Data(data)); }
	_&  Data(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(PushDescriptorSetWithTemplateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineProtectedAccessFeatures) {
	StructureClassHeader(PhysicalDevicePipelineProtectedAccessFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineProtectedAccessFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineRobustnessFeatures) {
	StructureClassHeader(PhysicalDevicePipelineRobustnessFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineRobustnessFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineRobustnessProperties) {
	StructureClassHeader(PhysicalDevicePipelineRobustnessProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineRobustnessProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRobustnessCreateInfo) {
	StructureClassHeader(PipelineRobustnessCreateInfo);
	DefineSetter_Copy(StorageBuffers, VkPipelineRobustnessBufferBehavior, storageBuffers);
	DefineSetter_Copy(UniformBuffers, VkPipelineRobustnessBufferBehavior, uniformBuffers);
	DefineSetter_Copy(VertexInputs, VkPipelineRobustnessBufferBehavior, vertexInputs);
	DefineSetter_Copy(Images, VkPipelineRobustnessImageBehavior, images);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRobustnessCreateInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceHostImageCopyFeatures) {
	StructureClassHeader(PhysicalDeviceHostImageCopyFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceHostImageCopyFeatures)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceHostImageCopyProperties) {
	StructureClassHeader(PhysicalDeviceHostImageCopyProperties);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceHostImageCopyProperties)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryToImageCopy) {
	StructureClassHeader(MemoryToImageCopy);
	DefineSetter_Copy(PHostPointer, const void*, pHostPointer);
	DefineSetter_Copy(MemoryRowLength, uint32_t, memoryRowLength);
	DefineSetter_Copy(MemoryImageHeight, uint32_t, memoryImageHeight);
	DefineSetter_Copy(ImageSubresource, VkImageSubresourceLayers, imageSubresource);
	DefineSetter_Copy(ImageOffset, VkOffset3D, imageOffset);
	DefineSetter_Copy(ImageExtent, VkExtent3D, imageExtent);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryToImageCopy)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageToMemoryCopy) {
	StructureClassHeader(ImageToMemoryCopy);
	DefineSetter_Copy(PHostPointer, void*, pHostPointer);
	DefineSetter_Copy(MemoryRowLength, uint32_t, memoryRowLength);
	DefineSetter_Copy(MemoryImageHeight, uint32_t, memoryImageHeight);
	DefineSetter_Copy(ImageSubresource, VkImageSubresourceLayers, imageSubresource);
	DefineSetter_Copy(ImageOffset, VkOffset3D, imageOffset);
	DefineSetter_Copy(ImageExtent, VkExtent3D, imageExtent);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageToMemoryCopy)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyMemoryToImageInfo) {
	StructureClassHeader(CopyMemoryToImageInfo);
	DefineSetter_Copy(Flags, VkHostImageCopyFlags, flags);
	DefineSetter_Copy(DstImage, VkImage, dstImage);
	DefineSetter_Copy(DstImageLayout, VkImageLayout, dstImageLayout);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkMemoryToImageCopy, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMemoryToImageInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyImageToMemoryInfo) {
	StructureClassHeader(CopyImageToMemoryInfo);
	DefineSetter_Copy(Flags, VkHostImageCopyFlags, flags);
	DefineSetter_Copy(SrcImage, VkImage, srcImage);
	DefineSetter_Copy(SrcImageLayout, VkImageLayout, srcImageLayout);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkImageToMemoryCopy, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyImageToMemoryInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyImageToImageInfo) {
	StructureClassHeader(CopyImageToImageInfo);
	DefineSetter_Copy(Flags, VkHostImageCopyFlags, flags);
	DefineSetter_Copy(SrcImage, VkImage, srcImage);
	DefineSetter_Copy(SrcImageLayout, VkImageLayout, srcImageLayout);
	DefineSetter_Copy(DstImage, VkImage, dstImage);
	DefineSetter_Copy(DstImageLayout, VkImageLayout, dstImageLayout);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkImageCopy2, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyImageToImageInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(HostImageLayoutTransitionInfo) {
	StructureClassHeader(HostImageLayoutTransitionInfo);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(OldLayout, VkImageLayout, oldLayout);
	DefineSetter_Copy(NewLayout, VkImageLayout, newLayout);
	DefineSetter_Copy(SubresourceRange, VkImageSubresourceRange, subresourceRange);
};
VK_ENCAPSULATION_STRUCTURE_END(HostImageLayoutTransitionInfo)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubresourceHostMemcpySize) {
	StructureClassHeader(SubresourceHostMemcpySize);
};
VK_ENCAPSULATION_STRUCTURE_END(SubresourceHostMemcpySize)

VK_ENCAPSULATION_STRUCTURE_BEGIN(HostImageCopyDevicePerformanceQuery) {
	StructureClassHeader(HostImageCopyDevicePerformanceQuery);
};
VK_ENCAPSULATION_STRUCTURE_END(HostImageCopyDevicePerformanceQuery)

inline void CmdSetLineStipple(uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLineStipple(ThreadContext::CommandBuffer(), lineStippleFactor, lineStipplePattern);
}

inline VkResult MapMemory2(const VkMemoryMapInfo& memoryMapInfo, void*& pData) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkMapMemory2(DeviceContext::Device(), &memoryMapInfo, &pData);
}
DefineRaiiFunction_ResultL(VkResult, MapMemory2, MemoryMapInfo, void*&, pData);

inline VkResult UnmapMemory2(const VkMemoryUnmapInfo& memoryUnmapInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkUnmapMemory2(DeviceContext::Device(), &memoryUnmapInfo);
}
DefineRaiiFunction_Result(VkResult, UnmapMemory2, MemoryUnmapInfo);

inline void CmdBindIndexBuffer2(VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindIndexBuffer2(ThreadContext::CommandBuffer(), buffer, offset, size, indexType);
}

inline void GetRenderingAreaGranularity(const VkRenderingAreaInfo& renderingAreaInfo, VkExtent2D& granularity) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRenderingAreaGranularity(DeviceContext::Device(), &renderingAreaInfo, &granularity);
}
DefineRaiiFunction_L(GetRenderingAreaGranularity, RenderingAreaInfo, VkExtent2D&, granularity);

inline void GetDeviceImageSubresourceLayout(const VkDeviceImageSubresourceInfo& info, VkSubresourceLayout2& layout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceImageSubresourceLayout(DeviceContext::Device(), &info, &layout);
}
DefineRaiiFunction_L(GetDeviceImageSubresourceLayout, DeviceImageSubresourceInfo, VkSubresourceLayout2&, layout);

inline void GetImageSubresourceLayout2(VkImage image, const VkImageSubresource2& subresource, VkSubresourceLayout2& layout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageSubresourceLayout2(DeviceContext::Device(), image, &subresource, &layout);
}

inline void CmdPushDescriptorSet(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, ArrayRef<const VkWriteDescriptorSet> descriptorWrites) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSet(ThreadContext::CommandBuffer(), pipelineBindPoint, layout, set, descriptorWrites.size(), descriptorWrites);
}

inline void CmdPushDescriptorSetWithTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, ArrayRef<const void> data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSetWithTemplate(ThreadContext::CommandBuffer(), descriptorUpdateTemplate, layout, set, data);
}
inline void CmdPushDescriptorSetWithTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const IsNotRangeOrPointer auto& data) {
	CmdPushDescriptorSetWithTemplate(descriptorUpdateTemplate, layout, set, { 0, &data });
}

inline void CmdSetRenderingAttachmentLocations(const VkRenderingAttachmentLocationInfo& locationInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRenderingAttachmentLocations(ThreadContext::CommandBuffer(), &locationInfo);
}
DefineRaiiFunction(CmdSetRenderingAttachmentLocations, RenderingAttachmentLocationInfo);

inline void CmdSetRenderingInputAttachmentIndices(const VkRenderingInputAttachmentIndexInfo& inputAttachmentIndexInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRenderingInputAttachmentIndices(ThreadContext::CommandBuffer(), &inputAttachmentIndexInfo);
}
DefineRaiiFunction(CmdSetRenderingInputAttachmentIndices, RenderingInputAttachmentIndexInfo);

inline void CmdBindDescriptorSets2(const VkBindDescriptorSetsInfo& bindDescriptorSetsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindDescriptorSets2(ThreadContext::CommandBuffer(), &bindDescriptorSetsInfo);
}
DefineRaiiFunction(CmdBindDescriptorSets2, BindDescriptorSetsInfo);

inline void CmdPushConstants2(const VkPushConstantsInfo& pushConstantsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushConstants2(ThreadContext::CommandBuffer(), &pushConstantsInfo);
}
DefineRaiiFunction(CmdPushConstants2, PushConstantsInfo);

inline void CmdPushDescriptorSet2(const VkPushDescriptorSetInfo& pushDescriptorSetInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSet2(ThreadContext::CommandBuffer(), &pushDescriptorSetInfo);
}
DefineRaiiFunction(CmdPushDescriptorSet2, PushDescriptorSetInfo);

inline void CmdPushDescriptorSetWithTemplate2(const VkPushDescriptorSetWithTemplateInfo& pushDescriptorSetWithTemplateInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSetWithTemplate2(ThreadContext::CommandBuffer(), &pushDescriptorSetWithTemplateInfo);
}
DefineRaiiFunction(CmdPushDescriptorSetWithTemplate2, PushDescriptorSetWithTemplateInfo);

inline VkResult CopyMemoryToImage(const VkCopyMemoryToImageInfo& copyMemoryToImageInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyMemoryToImage(DeviceContext::Device(), &copyMemoryToImageInfo);
}
DefineRaiiFunction_Result(VkResult, CopyMemoryToImage, CopyMemoryToImageInfo);

inline VkResult CopyImageToMemory(const VkCopyImageToMemoryInfo& copyImageToMemoryInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyImageToMemory(DeviceContext::Device(), &copyImageToMemoryInfo);
}
DefineRaiiFunction_Result(VkResult, CopyImageToMemory, CopyImageToMemoryInfo);

inline VkResult CopyImageToImage(const VkCopyImageToImageInfo& copyImageToImageInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyImageToImage(DeviceContext::Device(), &copyImageToImageInfo);
}
DefineRaiiFunction_Result(VkResult, CopyImageToImage, CopyImageToImageInfo);

inline VkResult TransitionImageLayout(ArrayRef<const VkHostImageLayoutTransitionInfo> transitions) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkTransitionImageLayout(DeviceContext::Device(), transitions.size(), transitions);
}
DefineRaiiFunction_Result(VkResult, TransitionImageLayout, HostImageLayoutTransitionInfo);

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SurfaceCapabilitiesKHR) {
	StructureClassHeader_NoSType(SurfaceCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SurfaceFormatKHR) {
	StructureClassHeader_NoSType(SurfaceFormatKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceFormatKHR)

inline void DestroySurfaceKHR(HandleRef<VkSurfaceKHR> surface, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkDestroySurfaceKHR(InstanceContext::Instance(), surface, &allocator);
	surface = VK_NULL_HANDLE;
}

inline VkResult GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32& supported) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, &supported);
}
inline VkResult GetPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32& supported) {
	return GetPhysicalDeviceSurfaceSupportKHR(DeviceContext::PhysicalDevice(), queueFamilyIndex, surface, supported);
}

inline VkResult GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR& surfaceCapabilities) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, &surfaceCapabilities);
}
inline VkResult GetPhysicalDeviceSurfaceCapabilitiesKHR(VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR& surfaceCapabilities) {
	return GetPhysicalDeviceSurfaceCapabilitiesKHR(DeviceContext::PhysicalDevice(), surface, surfaceCapabilities);
}

inline VkResult GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t& surfaceFormatCount, ArrayRef<VkSurfaceFormatKHR> surfaceFormats = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &surfaceFormatCount, surfaceFormats);
}
inline VkResult GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, IsDynamicArray<VkSurfaceFormatKHR> auto& surfaceFormats) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, count);
	if (result == VK_SUCCESS)
		surfaceFormats.resize(count),
		result = GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, count, surfaceFormats);
	return result;
}
inline VkResult GetPhysicalDeviceSurfaceFormatsKHR(VkSurfaceKHR surface, uint32_t& surfaceFormatCount, ArrayRef<VkSurfaceFormatKHR> surfaceFormats = {}) {
	return GetPhysicalDeviceSurfaceFormatsKHR(DeviceContext::PhysicalDevice(), surface, surfaceFormatCount, surfaceFormats);
}
inline VkResult GetPhysicalDeviceSurfaceFormatsKHR(VkSurfaceKHR surface, IsDynamicArray<VkSurfaceFormatKHR> auto& surfaceFormats) {
	return GetPhysicalDeviceSurfaceFormatsKHR(DeviceContext::PhysicalDevice(), surface, surfaceFormats);
}

inline VkResult GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t& presentModeCount, ArrayRef<VkPresentModeKHR> presentModes = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, presentModes);
}
inline VkResult GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, IsDynamicArray<VkPresentModeKHR> auto& presentModes) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, count);
	if (result == VK_SUCCESS)
		presentModes.resize(count),
		result = GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, count, presentModes);
	return result;
}
inline VkResult GetPhysicalDeviceSurfacePresentModesKHR(VkSurfaceKHR surface, uint32_t& presentModeCount, ArrayRef<VkPresentModeKHR> presentModes = {}) {
	return GetPhysicalDeviceSurfacePresentModesKHR(DeviceContext::PhysicalDevice(), surface, presentModeCount, presentModes);
}
inline VkResult GetPhysicalDeviceSurfacePresentModesKHR(VkSurfaceKHR surface, IsDynamicArray<VkPresentModeKHR> auto& presentModes) {
	return GetPhysicalDeviceSurfacePresentModesKHR(DeviceContext::PhysicalDevice(), surface, presentModes);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainCreateInfoKHR) {
	StructureClassHeader(SwapchainCreateInfoKHR, .imageArrayLayers = 1);
	DefineSetter_Copy(Flags, VkSwapchainCreateFlagsKHR, flags);
	DefineSetter_Copy(Surface, VkSurfaceKHR, surface);
	DefineSetter_Copy(MinImageCount, uint32_t, minImageCount);
	DefineSetter_Copy(ImageFormat, VkFormat, imageFormat);
	DefineSetter_Copy(ImageColorSpace, VkColorSpaceKHR, imageColorSpace);
	DefineSetter_Copy(ImageExtent, VkExtent2D, imageExtent);
	DefineSetter_Copy(ImageArrayLayers, uint32_t, imageArrayLayers);
	DefineSetter_Copy(ImageUsage, VkImageUsageFlags, imageUsage);
	DefineSetter_Copy(ImageSharingMode, VkSharingMode, imageSharingMode);
	DefineSetter_ArrayRef(QueueFamilyIndices, const uint32_t, queueFamilyIndices, queueFamilyIndexCount, imageSharingMode = VkSharingMode(bool(queueFamilyIndices)));
	DefineSetter_Copy(PreTransform, VkSurfaceTransformFlagBitsKHR, preTransform);
	DefineSetter_Copy(CompositeAlpha, VkCompositeAlphaFlagBitsKHR, compositeAlpha);
	DefineSetter_Copy(PresentMode, VkPresentModeKHR, presentMode);
	DefineSetter_Copy(Clipped, VkBool32, clipped);
	DefineSetter_Copy(OldSwapchain, VkSwapchainKHR, oldSwapchain);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PresentInfoKHR) {
	StructureClassHeader(PresentInfoKHR);
	DefineSetter_Copy(WaitSemaphoreCount, uint32_t, waitSemaphoreCount);
	DefineSetter_ArrayRef(WaitSemaphores, const VkSemaphore, waitSemaphores, waitSemaphoreCount);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(Swapchains, const VkSwapchainKHR, swapchains, swapchainCount);
	DefineSetter_ArrayRefIgnoreC(ImageIndices, const uint32_t, imageIndices);
	DefineSetter_ArrayRefIgnoreC(Results, VkResult, results);
#if defined VK_ENCAPSULATION_RESULT_THROW || defined VK_ENCAPSULATION_RESULT_NODISCARD
	_&  Results(ArrayRef<RESULT> results) &  { pResults = reinterpret_cast<VkResult*>(results.data()); return *this; }
	_&& Results(ArrayRef<RESULT> results) && { return std::move(Results(results)); }
	_&  Results(EmptyList) &  { pResults = nullptr; return *this; }
	_&& Results(EmptyList) && { return std::move(Results({})); }
#endif
};
VK_ENCAPSULATION_STRUCTURE_END(PresentInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageSwapchainCreateInfoKHR) {
	StructureClassHeader(ImageSwapchainCreateInfoKHR);
	DefineSetter_Copy(Swapchain, VkSwapchainKHR, swapchain);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageSwapchainCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindImageMemorySwapchainInfoKHR) {
	StructureClassHeader(BindImageMemorySwapchainInfoKHR);
	DefineSetter_Copy(Swapchain, VkSwapchainKHR, swapchain);
	DefineSetter_Copy(ImageIndex, uint32_t, imageIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(BindImageMemorySwapchainInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AcquireNextImageInfoKHR) {
	StructureClassHeader(AcquireNextImageInfoKHR);
	DefineSetter_Copy(Swapchain, VkSwapchainKHR, swapchain);
	DefineSetter_Copy(Timeout, uint64_t, timeout);
	DefineSetter_Copy(Semaphore, VkSemaphore, semaphore);
	DefineSetter_Copy(Fence, VkFence, fence);
	DefineSetter_Copy(DeviceMask, uint32_t, deviceMask);
};
VK_ENCAPSULATION_STRUCTURE_END(AcquireNextImageInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupPresentCapabilitiesKHR) {
	StructureClassHeader(DeviceGroupPresentCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupPresentCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupPresentInfoKHR) {
	StructureClassHeader(DeviceGroupPresentInfoKHR);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(DeviceMasks, const uint32_t, deviceMasks, swapchainCount);
	DefineSetter_Copy(Mode, VkDeviceGroupPresentModeFlagBitsKHR, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupPresentInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceGroupSwapchainCreateInfoKHR) {
	StructureClassHeader(DeviceGroupSwapchainCreateInfoKHR);
	DefineSetter_Copy(Modes, VkDeviceGroupPresentModeFlagsKHR, modes);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceGroupSwapchainCreateInfoKHR)

inline VkResult CreateSwapchainKHR(const VkSwapchainCreateInfoKHR& createInfo, HandleRef<VkSwapchainKHR> swapchain) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateSwapchainKHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &swapchain);
}
DefineRaiiFunction_ResultL(VkResult, CreateSwapchainKHR, SwapchainCreateInfoKHR, HandleRef<VkSwapchainKHR>, swapchain);

inline void DestroySwapchainKHR(HandleRef<VkSwapchainKHR> swapchain, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroySwapchainKHR(DeviceContext::Device(), swapchain, &allocator);
	swapchain = VK_NULL_HANDLE;
}

inline VkResult GetSwapchainImagesKHR(VkSwapchainKHR swapchain, uint32_t& swapchainImageCount, ArrayRef<VkImage> swapchainImages = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetSwapchainImagesKHR(DeviceContext::Device(), swapchain, &swapchainImageCount, swapchainImages);
}
inline VkResult GetSwapchainImagesKHR(VkSwapchainKHR swapchain, IsDynamicArray<VkImage> auto& swapchainImages) {
	uint32_t count = 0;
	VkResult result = GetSwapchainImagesKHR(swapchain, count);
	if (result == VK_SUCCESS)
		swapchainImages.resize(count),
		result = GetSwapchainImagesKHR(swapchain, count, swapchainImages);
	return result;
}

inline VkResult AcquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t& imageIndex) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkAcquireNextImageKHR(DeviceContext::Device(), swapchain, timeout, semaphore, fence, &imageIndex);
}

inline VkResult QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR& presentInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkQueuePresentKHR(queue, &presentInfo);
}
DefineRaiiFunction_ResultR(VkResult, QueuePresentKHR, VkQueue, queue, PresentInfoKHR);
inline VkResult QueuePresentKHR(const VkPresentInfoKHR& presentInfo) {
	return QueuePresentKHR(ThreadContext::Queue(), presentInfo);
}
DefineRaiiFunction_Result(VkResult, QueuePresentKHR, PresentInfoKHR);

inline VkResult GetDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentCapabilitiesKHR& deviceGroupPresentCapabilities) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceGroupPresentCapabilitiesKHR(DeviceContext::Device(), &deviceGroupPresentCapabilities);
}

inline VkResult GetDeviceGroupSurfacePresentModesKHR(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR& modes) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceGroupSurfacePresentModesKHR(DeviceContext::Device(), surface, &modes);
}

inline VkResult GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t& rectCount, ArrayRef<VkRect2D> rects = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, &rectCount, rects);
}
inline VkResult GetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, IsDynamicArray<VkRect2D> auto& rects) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, count);
	if (result == VK_SUCCESS)
		rects.resize(count),
		result = GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, count, rects);
	return result;
}
inline VkResult GetPhysicalDevicePresentRectanglesKHR(VkSurfaceKHR surface, uint32_t& rectCount, ArrayRef<VkRect2D> rects = {}) {
	return GetPhysicalDevicePresentRectanglesKHR(DeviceContext::PhysicalDevice(), surface, rectCount, rects);
}
inline VkResult GetPhysicalDevicePresentRectanglesKHR(VkSurfaceKHR surface, IsDynamicArray<VkRect2D> auto& rects) {
	return GetPhysicalDevicePresentRectanglesKHR(DeviceContext::PhysicalDevice(), surface, rects);
}

inline VkResult AcquireNextImage2KHR(const VkAcquireNextImageInfoKHR& acquireInfo, uint32_t& imageIndex) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkAcquireNextImage2KHR(DeviceContext::Device(), &acquireInfo, &imageIndex);
}
DefineRaiiFunction_ResultL(VkResult, AcquireNextImage2KHR, AcquireNextImageInfoKHR, uint32_t&, imageIndex);

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DisplayModeParametersKHR) {
	StructureClassHeader_NoSType(DisplayModeParametersKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayModeParametersKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayModeCreateInfoKHR) {
	StructureClassHeader(DisplayModeCreateInfoKHR);
	DefineSetter_Copy(Flags, VkDisplayModeCreateFlagsKHR, flags);
	DefineSetter_Copy(Parameters, VkDisplayModeParametersKHR, parameters);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayModeCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DisplayModePropertiesKHR) {
	StructureClassHeader_NoSType(DisplayModePropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayModePropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DisplayPlaneCapabilitiesKHR) {
	StructureClassHeader_NoSType(DisplayPlaneCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPlaneCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DisplayPlanePropertiesKHR) {
	StructureClassHeader_NoSType(DisplayPlanePropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPlanePropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DisplayPropertiesKHR) {
	StructureClassHeader_NoSType(DisplayPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplaySurfaceCreateInfoKHR) {
	StructureClassHeader(DisplaySurfaceCreateInfoKHR);
	DefineSetter_Copy(Flags, VkDisplaySurfaceCreateFlagsKHR, flags);
	DefineSetter_Copy(DisplayMode, VkDisplayModeKHR, displayMode);
	DefineSetter_Copy(PlaneIndex, uint32_t, planeIndex);
	DefineSetter_Copy(PlaneStackIndex, uint32_t, planeStackIndex);
	DefineSetter_Copy(Transform, VkSurfaceTransformFlagBitsKHR, transform);
	DefineSetter_Copy(GlobalAlpha, float, globalAlpha);
	DefineSetter_Copy(AlphaMode, VkDisplayPlaneAlphaFlagBitsKHR, alphaMode);
	DefineSetter_Copy(ImageExtent, VkExtent2D, imageExtent);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplaySurfaceCreateInfoKHR)

inline VkResult GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkDisplayPropertiesKHR> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkDisplayPropertiesKHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceDisplayPropertiesKHR(uint32_t& propertyCount, ArrayRef<VkDisplayPropertiesKHR> properties = {}) {
	return GetPhysicalDeviceDisplayPropertiesKHR(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayPropertiesKHR(IsDynamicArray<VkDisplayPropertiesKHR> auto& properties) {
	return GetPhysicalDeviceDisplayPropertiesKHR(DeviceContext::PhysicalDevice(), properties);
}

inline VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkDisplayPlanePropertiesKHR> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkDisplayPlanePropertiesKHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR(uint32_t& propertyCount, ArrayRef<VkDisplayPlanePropertiesKHR> properties = {}) {
	return GetPhysicalDeviceDisplayPlanePropertiesKHR(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR(IsDynamicArray<VkDisplayPlanePropertiesKHR> auto& properties) {
	return GetPhysicalDeviceDisplayPlanePropertiesKHR(DeviceContext::PhysicalDevice(), properties);
}

inline VkResult GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t& displayCount, HandleArrayRef<VkDisplayKHR> displays = HandleArrayRef<VkDisplayKHR>{}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, &displayCount, displays);
}
inline VkResult GetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, IsDynamicArray<VkDisplayKHR> auto& displays) {
	uint32_t count = 0;
	VkResult result = GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, count);
	if (result == VK_SUCCESS)
		displays.resize(count),
		result = GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, count, displays);
	return result;
}
inline VkResult GetDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex, uint32_t& displayCount, HandleArrayRef<VkDisplayKHR> displays = HandleArrayRef<VkDisplayKHR>{}) {
	return GetDisplayPlaneSupportedDisplaysKHR(DeviceContext::PhysicalDevice(), planeIndex, displayCount, displays);
}
inline VkResult GetDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex, IsDynamicArray<VkDisplayKHR> auto& displays) {
	return GetDisplayPlaneSupportedDisplaysKHR(DeviceContext::PhysicalDevice(), planeIndex, displays);
}

inline VkResult GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t& propertyCount, ArrayRef<VkDisplayModePropertiesKHR> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetDisplayModePropertiesKHR(physicalDevice, display, &propertyCount, properties);
}
inline VkResult GetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, IsDynamicArray<VkDisplayModePropertiesKHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetDisplayModePropertiesKHR(physicalDevice, display, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetDisplayModePropertiesKHR(physicalDevice, display, count, properties);
	return result;
}
inline VkResult GetDisplayModePropertiesKHR(VkDisplayKHR display, uint32_t& propertyCount, ArrayRef<VkDisplayModePropertiesKHR> properties = {}) {
	return GetDisplayModePropertiesKHR(DeviceContext::PhysicalDevice(), display, propertyCount, properties);
}
inline VkResult GetDisplayModePropertiesKHR(VkDisplayKHR display, IsDynamicArray<VkDisplayModePropertiesKHR> auto& properties) {
	return GetDisplayModePropertiesKHR(DeviceContext::PhysicalDevice(), display, properties);
}

inline VkResult CreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR& createInfo, HandleRef<VkDisplayModeKHR> mode) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkCreateDisplayModeKHR(physicalDevice, display, &createInfo, ThreadContext::PAllocator(), &mode);
}
inline VkResult CreateDisplayModeKHR(VkDisplayKHR display, const VkDisplayModeCreateInfoKHR& createInfo, HandleRef<VkDisplayModeKHR> mode) {
	return CreateDisplayModeKHR(DeviceContext::PhysicalDevice(), display, createInfo, mode);
}

inline VkResult GetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR& capabilities) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, &capabilities);
}
inline VkResult GetDisplayPlaneCapabilitiesKHR(VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR& capabilities) {
	return GetDisplayPlaneCapabilitiesKHR(DeviceContext::PhysicalDevice(), mode, planeIndex, capabilities);
}

inline VkResult CreateDisplayPlaneSurfaceKHR(const VkDisplaySurfaceCreateInfoKHR& createInfo, HandleRef<VkSurfaceKHR> surface) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkCreateDisplayPlaneSurfaceKHR(InstanceContext::Instance(), &createInfo, ThreadContext::PAllocator(), &surface);
}
DefineRaiiFunction_ResultL(VkResult, CreateDisplayPlaneSurfaceKHR, DisplaySurfaceCreateInfoKHR, HandleRef<VkSurfaceKHR>, surface);

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayPresentInfoKHR) {
	StructureClassHeader(DisplayPresentInfoKHR);
	DefineSetter_Copy(SrcRect, VkRect2D, srcRect);
	DefineSetter_Copy(DstRect, VkRect2D, dstRect);
	DefineSetter_Copy(Persistent, VkBool32, persistent);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPresentInfoKHR)

inline VkResult CreateSharedSwapchainsKHR(ArrayRef<const VkSwapchainCreateInfoKHR> createInfos, HandleArrayRef<VkSwapchainKHR> swapchains) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateSharedSwapchainsKHR(DeviceContext::Device(), createInfos.size(), createInfos, ThreadContext::PAllocator(), swapchains);
}
DefineRaiiFunction_ResultL(VkResult, CreateSharedSwapchainsKHR, SwapchainCreateInfoKHR, HandleRef<VkSwapchainKHR>, swapchain);

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyQueryResultStatusPropertiesKHR) {
	StructureClassHeader(QueueFamilyQueryResultStatusPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyQueryResultStatusPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyVideoPropertiesKHR) {
	StructureClassHeader(QueueFamilyVideoPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyVideoPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoProfileInfoKHR) {
	StructureClassHeader(VideoProfileInfoKHR);
	DefineSetter_Copy(VideoCodecOperation, VkVideoCodecOperationFlagBitsKHR, videoCodecOperation);
	DefineSetter_Copy(ChromaSubsampling, VkVideoChromaSubsamplingFlagsKHR, chromaSubsampling);
	DefineSetter_Copy(LumaBitDepth, VkVideoComponentBitDepthFlagsKHR, lumaBitDepth);
	DefineSetter_Copy(ChromaBitDepth, VkVideoComponentBitDepthFlagsKHR, chromaBitDepth);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoProfileListInfoKHR) {
	StructureClassHeader(VideoProfileListInfoKHR);
	DefineSetter_Copy(ProfileCount, uint32_t, profileCount);
	DefineSetter_ArrayRef(Profiles, const VkVideoProfileInfoKHR, profiles, profileCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoProfileListInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoCapabilitiesKHR) {
	StructureClassHeader(VideoCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoFormatInfoKHR) {
	StructureClassHeader(PhysicalDeviceVideoFormatInfoKHR);
	DefineSetter_Copy(ImageUsage, VkImageUsageFlags, imageUsage);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoFormatInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoFormatPropertiesKHR) {
	StructureClassHeader(VideoFormatPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoFormatPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoPictureResourceInfoKHR) {
	StructureClassHeader(VideoPictureResourceInfoKHR);
	DefineSetter_Copy(CodedOffset, VkOffset2D, codedOffset);
	DefineSetter_Copy(CodedExtent, VkExtent2D, codedExtent);
	DefineSetter_Copy(BaseArrayLayer, uint32_t, baseArrayLayer);
	DefineSetter_Copy(ImageViewBinding, VkImageView, imageViewBinding);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoPictureResourceInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoReferenceSlotInfoKHR) {
	StructureClassHeader(VideoReferenceSlotInfoKHR);
	DefineSetter_Copy(SlotIndex, int32_t, slotIndex);
	DefineSetter_Ref(PictureResource, const VkVideoPictureResourceInfoKHR, pictureResource);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoReferenceSlotInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoSessionMemoryRequirementsKHR) {
	StructureClassHeader(VideoSessionMemoryRequirementsKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoSessionMemoryRequirementsKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindVideoSessionMemoryInfoKHR) {
	StructureClassHeader(BindVideoSessionMemoryInfoKHR);
	DefineSetter_Copy(MemoryBindIndex, uint32_t, memoryBindIndex);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
	DefineSetter_Copy(MemorySize, VkDeviceSize, memorySize);
};
VK_ENCAPSULATION_STRUCTURE_END(BindVideoSessionMemoryInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoSessionCreateInfoKHR) {
	StructureClassHeader(VideoSessionCreateInfoKHR);
	DefineSetter_Copy(QueueFamilyIndex, uint32_t, queueFamilyIndex);
	DefineSetter_Copy(Flags, VkVideoSessionCreateFlagsKHR, flags);
	DefineSetter_Ref(VideoProfile, const VkVideoProfileInfoKHR, videoProfile);
	DefineSetter_Copy(PictureFormat, VkFormat, pictureFormat);
	DefineSetter_Copy(MaxCodedExtent, VkExtent2D, maxCodedExtent);
	DefineSetter_Copy(ReferencePictureFormat, VkFormat, referencePictureFormat);
	DefineSetter_Copy(MaxDpbSlots, uint32_t, maxDpbSlots);
	DefineSetter_Copy(MaxActiveReferencePictures, uint32_t, maxActiveReferencePictures);
	DefineSetter_Ref(StdHeaderVersion, const VkExtensionProperties, stdHeaderVersion);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoSessionCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoSessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoSessionParametersCreateInfoKHR);
	DefineSetter_Copy(Flags, VkVideoSessionParametersCreateFlagsKHR, flags);
	DefineSetter_Copy(VideoSessionParametersTemplate, VkVideoSessionParametersKHR, videoSessionParametersTemplate);
	DefineSetter_Copy(VideoSession, VkVideoSessionKHR, videoSession);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoSessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoSessionParametersUpdateInfoKHR) {
	StructureClassHeader(VideoSessionParametersUpdateInfoKHR);
	DefineSetter_Copy(UpdateSequenceCount, uint32_t, updateSequenceCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoSessionParametersUpdateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoBeginCodingInfoKHR) {
	StructureClassHeader(VideoBeginCodingInfoKHR);
	DefineSetter_Copy(Flags, VkVideoBeginCodingFlagsKHR, flags);
	DefineSetter_Copy(VideoSession, VkVideoSessionKHR, videoSession);
	DefineSetter_Copy(VideoSessionParameters, VkVideoSessionParametersKHR, videoSessionParameters);
	DefineSetter_Copy(ReferenceSlotCount, uint32_t, referenceSlotCount);
	DefineSetter_ArrayRef(ReferenceSlots, const VkVideoReferenceSlotInfoKHR, referenceSlots, referenceSlotCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoBeginCodingInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEndCodingInfoKHR) {
	StructureClassHeader(VideoEndCodingInfoKHR);
	DefineSetter_Copy(Flags, VkVideoEndCodingFlagsKHR, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEndCodingInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoCodingControlInfoKHR) {
	StructureClassHeader(VideoCodingControlInfoKHR);
	DefineSetter_Copy(Flags, VkVideoCodingControlFlagsKHR, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoCodingControlInfoKHR)

inline VkResult GetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR& videoProfile, VkVideoCapabilitiesKHR& capabilities) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, &videoProfile, &capabilities);
}
inline VkResult GetPhysicalDeviceVideoCapabilitiesKHR(const VkVideoProfileInfoKHR& videoProfile, VkVideoCapabilitiesKHR& capabilities) {
	return GetPhysicalDeviceVideoCapabilitiesKHR(DeviceContext::PhysicalDevice(), videoProfile, capabilities);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceVideoCapabilitiesKHR, VideoProfileInfoKHR, VkVideoCapabilitiesKHR&, capabilities);

inline VkResult GetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR& videoFormatInfo, uint32_t& videoFormatPropertyCount, ArrayRef<VkVideoFormatPropertiesKHR> videoFormatProperties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, &videoFormatInfo, &videoFormatPropertyCount, videoFormatProperties);
}
inline VkResult GetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR& videoFormatInfo, IsDynamicArray<VkVideoFormatPropertiesKHR> auto& videoFormatProperties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, videoFormatInfo, count);
	if (result == VK_SUCCESS)
		videoFormatProperties.resize(count),
		result = GetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, videoFormatInfo, count, videoFormatProperties);
	return result;
}
inline VkResult GetPhysicalDeviceVideoFormatPropertiesKHR(const VkPhysicalDeviceVideoFormatInfoKHR& videoFormatInfo, uint32_t& videoFormatPropertyCount, ArrayRef<VkVideoFormatPropertiesKHR> videoFormatProperties = {}) {
	return GetPhysicalDeviceVideoFormatPropertiesKHR(DeviceContext::PhysicalDevice(), videoFormatInfo, videoFormatPropertyCount, videoFormatProperties);
}
inline VkResult GetPhysicalDeviceVideoFormatPropertiesKHR(const VkPhysicalDeviceVideoFormatInfoKHR& videoFormatInfo, IsDynamicArray<VkVideoFormatPropertiesKHR> auto& videoFormatProperties) {
	return GetPhysicalDeviceVideoFormatPropertiesKHR(DeviceContext::PhysicalDevice(), videoFormatInfo, videoFormatProperties);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceVideoFormatPropertiesKHR, PhysicalDeviceVideoFormatInfoKHR, IsDynamicArray<VkVideoFormatPropertiesKHR> auto&, videoFormatProperties);

inline VkResult CreateVideoSessionKHR(const VkVideoSessionCreateInfoKHR& createInfo, HandleRef<VkVideoSessionKHR> videoSession) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateVideoSessionKHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &videoSession);
}
DefineRaiiFunction_ResultL(VkResult, CreateVideoSessionKHR, VideoSessionCreateInfoKHR, HandleRef<VkVideoSessionKHR>, videoSession);

inline void DestroyVideoSessionKHR(HandleRef<VkVideoSessionKHR> videoSession, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyVideoSessionKHR(DeviceContext::Device(), videoSession, &allocator);
	videoSession = VK_NULL_HANDLE;
}

inline VkResult GetVideoSessionMemoryRequirementsKHR(VkVideoSessionKHR videoSession, uint32_t& memoryRequirementsCount, ArrayRef<VkVideoSessionMemoryRequirementsKHR> memoryRequirements = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetVideoSessionMemoryRequirementsKHR(DeviceContext::Device(), videoSession, &memoryRequirementsCount, memoryRequirements);
}
inline VkResult GetVideoSessionMemoryRequirementsKHR(VkVideoSessionKHR videoSession, IsDynamicArray<VkVideoSessionMemoryRequirementsKHR> auto& memoryRequirements) {
	uint32_t count = 0;
	VkResult result = GetVideoSessionMemoryRequirementsKHR(videoSession, count);
	if (result == VK_SUCCESS)
		memoryRequirements.resize(count),
		result = GetVideoSessionMemoryRequirementsKHR(videoSession, count, memoryRequirements);
	return result;
}

inline VkResult BindVideoSessionMemoryKHR(VkVideoSessionKHR videoSession, ArrayRef<const VkBindVideoSessionMemoryInfoKHR> bindSessionMemoryInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindVideoSessionMemoryKHR(DeviceContext::Device(), videoSession, bindSessionMemoryInfos.size(), bindSessionMemoryInfos);
}
DefineRaiiFunction_ResultR(VkResult, BindVideoSessionMemoryKHR, VkVideoSessionKHR, videoSession, BindVideoSessionMemoryInfoKHR);

inline VkResult CreateVideoSessionParametersKHR(const VkVideoSessionParametersCreateInfoKHR& createInfo, HandleRef<VkVideoSessionParametersKHR> videoSessionParameters) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateVideoSessionParametersKHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &videoSessionParameters);
}
DefineRaiiFunction_ResultL(VkResult, CreateVideoSessionParametersKHR, VideoSessionParametersCreateInfoKHR, HandleRef<VkVideoSessionParametersKHR>, videoSessionParameters);

inline VkResult UpdateVideoSessionParametersKHR(VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR& updateInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkUpdateVideoSessionParametersKHR(DeviceContext::Device(), videoSessionParameters, &updateInfo);
}
DefineRaiiFunction_ResultR(VkResult, UpdateVideoSessionParametersKHR, VkVideoSessionParametersKHR, videoSessionParameters, VideoSessionParametersUpdateInfoKHR);

inline void DestroyVideoSessionParametersKHR(HandleRef<VkVideoSessionParametersKHR> videoSessionParameters, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyVideoSessionParametersKHR(DeviceContext::Device(), videoSessionParameters, &allocator);
	videoSessionParameters = VK_NULL_HANDLE;
}

inline void CmdBeginVideoCodingKHR(const VkVideoBeginCodingInfoKHR& beginInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginVideoCodingKHR(ThreadContext::CommandBuffer(), &beginInfo);
}
DefineRaiiFunction(CmdBeginVideoCodingKHR, VideoBeginCodingInfoKHR);

inline void CmdEndVideoCodingKHR(const VkVideoEndCodingInfoKHR& endCodingInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndVideoCodingKHR(ThreadContext::CommandBuffer(), &endCodingInfo);
}
DefineRaiiFunction(CmdEndVideoCodingKHR, VideoEndCodingInfoKHR);

inline void CmdControlVideoCodingKHR(const VkVideoCodingControlInfoKHR& codingControlInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdControlVideoCodingKHR(ThreadContext::CommandBuffer(), &codingControlInfo);
}
DefineRaiiFunction(CmdControlVideoCodingKHR, VideoCodingControlInfoKHR);

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeCapabilitiesKHR) {
	StructureClassHeader(VideoDecodeCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeUsageInfoKHR) {
	StructureClassHeader(VideoDecodeUsageInfoKHR);
	DefineSetter_Copy(VideoUsageHints, VkVideoDecodeUsageFlagsKHR, videoUsageHints);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeUsageInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeInfoKHR) {
	StructureClassHeader(VideoDecodeInfoKHR);
	DefineSetter_Copy(Flags, VkVideoDecodeFlagsKHR, flags);
	DefineSetter_Copy(SrcBuffer, VkBuffer, srcBuffer);
	DefineSetter_Copy(SrcBufferOffset, VkDeviceSize, srcBufferOffset);
	DefineSetter_Copy(SrcBufferRange, VkDeviceSize, srcBufferRange);
	DefineSetter_Copy(DstPictureResource, VkVideoPictureResourceInfoKHR, dstPictureResource);
	DefineSetter_Ref(SetupReferenceSlot, const VkVideoReferenceSlotInfoKHR, setupReferenceSlot);
	DefineSetter_Copy(ReferenceSlotCount, uint32_t, referenceSlotCount);
	DefineSetter_ArrayRef(ReferenceSlots, const VkVideoReferenceSlotInfoKHR, referenceSlots, referenceSlotCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeInfoKHR)

inline void CmdDecodeVideoKHR(const VkVideoDecodeInfoKHR& decodeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDecodeVideoKHR(ThreadContext::CommandBuffer(), &decodeInfo);
}
DefineRaiiFunction(CmdDecodeVideoKHR, VideoDecodeInfoKHR);

//#include "vk_video/vulkan_video_codec_h264std.h"
//#include "vk_video/vulkan_video_codec_h264std_encode.h"

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264CapabilitiesKHR) {
	StructureClassHeader(VideoEncodeH264CapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264CapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VideoEncodeH264QpKHR) {
	StructureClassHeader_NoSType(VideoEncodeH264QpKHR);
	DefineSetter_Copy(QpI, int32_t, qpI);
	DefineSetter_Copy(QpP, int32_t, qpP);
	DefineSetter_Copy(QpB, int32_t, qpB);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264QpKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264QualityLevelPropertiesKHR) {
	StructureClassHeader(VideoEncodeH264QualityLevelPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264QualityLevelPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264SessionCreateInfoKHR) {
	StructureClassHeader(VideoEncodeH264SessionCreateInfoKHR);
	DefineSetter_Copy(UseMaxLevelIdc, VkBool32, useMaxLevelIdc);
	DefineSetter_CopyOptional(MaxLevelIdc, StdVideoH264LevelIdc, maxLevelIdc, useMaxLevelIdc, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264SessionCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264SessionParametersAddInfoKHR) {
	StructureClassHeader(VideoEncodeH264SessionParametersAddInfoKHR);
	DefineSetter_Copy(StdSPSCount, uint32_t, stdSPSCount);
	DefineSetter_ArrayRef(StdSPSs, const StdVideoH264SequenceParameterSet, stdSPSs, stdSPSCount);
	DefineSetter_Copy(StdPPSCount, uint32_t, stdPPSCount);
	DefineSetter_ArrayRef(StdPPSs, const StdVideoH264PictureParameterSet, stdPPSs, stdPPSCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264SessionParametersAddInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264SessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoEncodeH264SessionParametersCreateInfoKHR);
	DefineSetter_Copy(MaxStdSPSCount, uint32_t, maxStdSPSCount);
	DefineSetter_Copy(MaxStdPPSCount, uint32_t, maxStdPPSCount);
	DefineSetter_Ref(ParametersAddInfo, const VkVideoEncodeH264SessionParametersAddInfoKHR, parametersAddInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264SessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264SessionParametersGetInfoKHR) {
	StructureClassHeader(VideoEncodeH264SessionParametersGetInfoKHR);
	DefineSetter_Copy(WriteStdSPS, VkBool32, writeStdSPS);
	DefineSetter_Copy(WriteStdPPS, VkBool32, writeStdPPS);
	DefineSetter_CopyOptional(StdSPSId, uint32_t, stdSPSId, writeStdSPS, true);
	DefineSetter_CopyOptional(StdPPSId, uint32_t, stdPPSId, writeStdPPS, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264SessionParametersGetInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264SessionParametersFeedbackInfoKHR) {
	StructureClassHeader(VideoEncodeH264SessionParametersFeedbackInfoKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264SessionParametersFeedbackInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264NaluSliceInfoKHR) {
	StructureClassHeader(VideoEncodeH264NaluSliceInfoKHR);
	DefineSetter_Copy(ConstantQp, int32_t, constantQp);
	DefineSetter_Ref(StdSliceHeader, const StdVideoEncodeH264SliceHeader, stdSliceHeader);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264NaluSliceInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264PictureInfoKHR) {
	StructureClassHeader(VideoEncodeH264PictureInfoKHR);
	DefineSetter_Copy(NaluSliceEntryCount, uint32_t, naluSliceEntryCount);
	DefineSetter_ArrayRef(NaluSliceEntries, const VkVideoEncodeH264NaluSliceInfoKHR, naluSliceEntries, naluSliceEntryCount);
	DefineSetter_Ref(StdPictureInfo, const StdVideoEncodeH264PictureInfo, stdPictureInfo);
	DefineSetter_Copy(GeneratePrefixNalu, VkBool32, generatePrefixNalu);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264PictureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264DpbSlotInfoKHR) {
	StructureClassHeader(VideoEncodeH264DpbSlotInfoKHR);
	DefineSetter_Ref(StdReferenceInfo, const StdVideoEncodeH264ReferenceInfo, stdReferenceInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264DpbSlotInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264ProfileInfoKHR) {
	StructureClassHeader(VideoEncodeH264ProfileInfoKHR);
	DefineSetter_Copy(StdProfileIdc, StdVideoH264ProfileIdc, stdProfileIdc);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264ProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264RateControlInfoKHR) {
	StructureClassHeader(VideoEncodeH264RateControlInfoKHR);
	DefineSetter_Copy(Flags, VkVideoEncodeH264RateControlFlagsKHR, flags);
	DefineSetter_Copy(GopFrameCount, uint32_t, gopFrameCount);
	DefineSetter_Copy(IdrPeriod, uint32_t, idrPeriod);
	DefineSetter_Copy(ConsecutiveBFrameCount, uint32_t, consecutiveBFrameCount);
	DefineSetter_Copy(TemporalLayerCount, uint32_t, temporalLayerCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264RateControlInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VideoEncodeH264FrameSizeKHR) {
	StructureClassHeader_NoSType(VideoEncodeH264FrameSizeKHR);
	DefineSetter_Copy(FrameISize, uint32_t, frameISize);
	DefineSetter_Copy(FramePSize, uint32_t, framePSize);
	DefineSetter_Copy(FrameBSize, uint32_t, frameBSize);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264FrameSizeKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264RateControlLayerInfoKHR) {
	StructureClassHeader(VideoEncodeH264RateControlLayerInfoKHR);
	DefineSetter_Copy(UseMinQp, VkBool32, useMinQp);
	DefineSetter_CopyOptional(MinQp, VkVideoEncodeH264QpKHR, minQp, useMinQp, true);
	DefineSetter_Copy(UseMaxQp, VkBool32, useMaxQp);
	DefineSetter_CopyOptional(MaxQp, VkVideoEncodeH264QpKHR, maxQp, useMaxQp, true);
	DefineSetter_Copy(UseMaxFrameSize, VkBool32, useMaxFrameSize);
	DefineSetter_CopyOptional(MaxFrameSize, VkVideoEncodeH264FrameSizeKHR, maxFrameSize, useMaxFrameSize, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264RateControlLayerInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264GopRemainingFrameInfoKHR) {
	StructureClassHeader(VideoEncodeH264GopRemainingFrameInfoKHR);
	DefineSetter_Copy(UseGopRemainingFrames, VkBool32, useGopRemainingFrames);
	DefineSetter_CopyOptional(GopRemainingI, uint32_t, gopRemainingI, useGopRemainingFrames, true);
	DefineSetter_CopyOptional(GopRemainingP, uint32_t, gopRemainingP, useGopRemainingFrames, true);
	DefineSetter_CopyOptional(GopRemainingB, uint32_t, gopRemainingB, useGopRemainingFrames, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264GopRemainingFrameInfoKHR)

//#include "vk_video/vulkan_video_codec_h265std.h"
//#include "vk_video/vulkan_video_codec_h265std_encode.h"

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265CapabilitiesKHR) {
	StructureClassHeader(VideoEncodeH265CapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265CapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265SessionCreateInfoKHR) {
	StructureClassHeader(VideoEncodeH265SessionCreateInfoKHR);
	DefineSetter_Copy(UseMaxLevelIdc, VkBool32, useMaxLevelIdc);
	DefineSetter_CopyOptional(MaxLevelIdc, StdVideoH265LevelIdc, maxLevelIdc, useMaxLevelIdc, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265SessionCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VideoEncodeH265QpKHR) {
	StructureClassHeader_NoSType(VideoEncodeH265QpKHR);
	DefineSetter_Copy(QpI, int32_t, qpI);
	DefineSetter_Copy(QpP, int32_t, qpP);
	DefineSetter_Copy(QpB, int32_t, qpB);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265QpKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265QualityLevelPropertiesKHR) {
	StructureClassHeader(VideoEncodeH265QualityLevelPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265QualityLevelPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265SessionParametersAddInfoKHR) {
	StructureClassHeader(VideoEncodeH265SessionParametersAddInfoKHR);
	DefineSetter_Copy(StdVPSCount, uint32_t, stdVPSCount);
	DefineSetter_ArrayRef(StdVPSs, const StdVideoH265VideoParameterSet, stdVPSs, stdVPSCount);
	DefineSetter_Copy(StdSPSCount, uint32_t, stdSPSCount);
	DefineSetter_ArrayRef(StdSPSs, const StdVideoH265SequenceParameterSet, stdSPSs, stdSPSCount);
	DefineSetter_Copy(StdPPSCount, uint32_t, stdPPSCount);
	DefineSetter_ArrayRef(StdPPSs, const StdVideoH265PictureParameterSet, stdPPSs, stdPPSCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265SessionParametersAddInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265SessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoEncodeH265SessionParametersCreateInfoKHR);
	DefineSetter_Copy(MaxStdVPSCount, uint32_t, maxStdVPSCount);
	DefineSetter_Copy(MaxStdSPSCount, uint32_t, maxStdSPSCount);
	DefineSetter_Copy(MaxStdPPSCount, uint32_t, maxStdPPSCount);
	DefineSetter_Ref(ParametersAddInfo, const VkVideoEncodeH265SessionParametersAddInfoKHR, parametersAddInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265SessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265SessionParametersGetInfoKHR) {
	StructureClassHeader(VideoEncodeH265SessionParametersGetInfoKHR);
	DefineSetter_Copy(WriteStdVPS, VkBool32, writeStdVPS);
	DefineSetter_Copy(WriteStdSPS, VkBool32, writeStdSPS);
	DefineSetter_Copy(WriteStdPPS, VkBool32, writeStdPPS);
	DefineSetter_CopyOptional(StdVPSId, uint32_t, stdVPSId, writeStdVPS, true);
	DefineSetter_CopyOptional(StdSPSId, uint32_t, stdSPSId, writeStdSPS, true);
	DefineSetter_CopyOptional(StdPPSId, uint32_t, stdPPSId, writeStdPPS, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265SessionParametersGetInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265SessionParametersFeedbackInfoKHR) {
	StructureClassHeader(VideoEncodeH265SessionParametersFeedbackInfoKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265SessionParametersFeedbackInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265NaluSliceSegmentInfoKHR) {
	StructureClassHeader(VideoEncodeH265NaluSliceSegmentInfoKHR);
	DefineSetter_Copy(ConstantQp, int32_t, constantQp);
	DefineSetter_Ref(StdSliceSegmentHeader, const StdVideoEncodeH265SliceSegmentHeader, stdSliceSegmentHeader);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265NaluSliceSegmentInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265PictureInfoKHR) {
	StructureClassHeader(VideoEncodeH265PictureInfoKHR);
	DefineSetter_Copy(NaluSliceSegmentEntryCount, uint32_t, naluSliceSegmentEntryCount);
	DefineSetter_ArrayRef(NaluSliceSegmentEntries, const VkVideoEncodeH265NaluSliceSegmentInfoKHR, naluSliceSegmentEntries, naluSliceSegmentEntryCount);
	DefineSetter_Ref(StdPictureInfo, const StdVideoEncodeH265PictureInfo, stdPictureInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265PictureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265DpbSlotInfoKHR) {
	StructureClassHeader(VideoEncodeH265DpbSlotInfoKHR);
	DefineSetter_Ref(StdReferenceInfo, const StdVideoEncodeH265ReferenceInfo, stdReferenceInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265DpbSlotInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265ProfileInfoKHR) {
	StructureClassHeader(VideoEncodeH265ProfileInfoKHR);
	DefineSetter_Copy(StdProfileIdc, StdVideoH265ProfileIdc, stdProfileIdc);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265ProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265RateControlInfoKHR) {
	StructureClassHeader(VideoEncodeH265RateControlInfoKHR);
	DefineSetter_Copy(Flags, VkVideoEncodeH265RateControlFlagsKHR, flags);
	DefineSetter_Copy(GopFrameCount, uint32_t, gopFrameCount);
	DefineSetter_Copy(IdrPeriod, uint32_t, idrPeriod);
	DefineSetter_Copy(ConsecutiveBFrameCount, uint32_t, consecutiveBFrameCount);
	DefineSetter_Copy(SubLayerCount, uint32_t, subLayerCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265RateControlInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VideoEncodeH265FrameSizeKHR) {
	StructureClassHeader_NoSType(VideoEncodeH265FrameSizeKHR);
	DefineSetter_Copy(FrameISize, uint32_t, frameISize);
	DefineSetter_Copy(FramePSize, uint32_t, framePSize);
	DefineSetter_Copy(FrameBSize, uint32_t, frameBSize);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265FrameSizeKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265RateControlLayerInfoKHR) {
	StructureClassHeader(VideoEncodeH265RateControlLayerInfoKHR);
	DefineSetter_Copy(UseMinQp, VkBool32, useMinQp);
	DefineSetter_CopyOptional(MinQp, VkVideoEncodeH265QpKHR, minQp, useMinQp, true);
	DefineSetter_Copy(UseMaxQp, VkBool32, useMaxQp);
	DefineSetter_CopyOptional(MaxQp, VkVideoEncodeH265QpKHR, maxQp, useMaxQp, true);
	DefineSetter_Copy(UseMaxFrameSize, VkBool32, useMaxFrameSize);
	DefineSetter_CopyOptional(MaxFrameSize, VkVideoEncodeH265FrameSizeKHR, maxFrameSize, useMaxFrameSize, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265RateControlLayerInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265GopRemainingFrameInfoKHR) {
	StructureClassHeader(VideoEncodeH265GopRemainingFrameInfoKHR);
	DefineSetter_Copy(UseGopRemainingFrames, VkBool32, useGopRemainingFrames);
	DefineSetter_CopyOptional(GopRemainingI, uint32_t, gopRemainingI, useGopRemainingFrames, true);
	DefineSetter_CopyOptional(GopRemainingP, uint32_t, gopRemainingP, useGopRemainingFrames, true);
	DefineSetter_CopyOptional(GopRemainingB, uint32_t, gopRemainingB, useGopRemainingFrames, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265GopRemainingFrameInfoKHR)

//#include "vk_video/vulkan_video_codec_h264std_decode.h"

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH264ProfileInfoKHR) {
	StructureClassHeader(VideoDecodeH264ProfileInfoKHR);
	DefineSetter_Copy(StdProfileIdc, StdVideoH264ProfileIdc, stdProfileIdc);
	DefineSetter_Copy(PictureLayout, VkVideoDecodeH264PictureLayoutFlagBitsKHR, pictureLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH264ProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH264CapabilitiesKHR) {
	StructureClassHeader(VideoDecodeH264CapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH264CapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH264SessionParametersAddInfoKHR) {
	StructureClassHeader(VideoDecodeH264SessionParametersAddInfoKHR);
	DefineSetter_Copy(StdSPSCount, uint32_t, stdSPSCount);
	DefineSetter_ArrayRef(StdSPSs, const StdVideoH264SequenceParameterSet, stdSPSs, stdSPSCount);
	DefineSetter_Copy(StdPPSCount, uint32_t, stdPPSCount);
	DefineSetter_ArrayRef(StdPPSs, const StdVideoH264PictureParameterSet, stdPPSs, stdPPSCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH264SessionParametersAddInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH264SessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoDecodeH264SessionParametersCreateInfoKHR);
	DefineSetter_Copy(MaxStdSPSCount, uint32_t, maxStdSPSCount);
	DefineSetter_Copy(MaxStdPPSCount, uint32_t, maxStdPPSCount);
	DefineSetter_Ref(ParametersAddInfo, const VkVideoDecodeH264SessionParametersAddInfoKHR, parametersAddInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH264SessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH264PictureInfoKHR) {
	StructureClassHeader(VideoDecodeH264PictureInfoKHR);
	DefineSetter_Ref(StdPictureInfo, const StdVideoDecodeH264PictureInfo, stdPictureInfo);
	DefineSetter_Copy(SliceCount, uint32_t, sliceCount);
	DefineSetter_ArrayRef(SliceOffsets, const uint32_t, sliceOffsets, sliceCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH264PictureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH264DpbSlotInfoKHR) {
	StructureClassHeader(VideoDecodeH264DpbSlotInfoKHR);
	DefineSetter_Ref(StdReferenceInfo, const StdVideoDecodeH264ReferenceInfo, stdReferenceInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH264DpbSlotInfoKHR)

inline void CmdBeginRenderingKHR(const VkRenderingInfo& renderingInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginRenderingKHR(ThreadContext::CommandBuffer(), &renderingInfo);
}
DefineRaiiFunction(CmdBeginRenderingKHR, RenderingInfo);

inline void CmdEndRenderingKHR() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndRenderingKHR(ThreadContext::CommandBuffer());
}

inline void GetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2& features) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceFeatures2KHR(physicalDevice, &features);
}
inline void GetPhysicalDeviceFeatures2KHR(VkPhysicalDeviceFeatures2& features) {
	GetPhysicalDeviceFeatures2KHR(DeviceContext::PhysicalDevice(), features);
}

inline void GetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2& properties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceProperties2KHR(physicalDevice, &properties);
}
inline void GetPhysicalDeviceProperties2KHR(VkPhysicalDeviceProperties2& properties) {
	GetPhysicalDeviceProperties2KHR(DeviceContext::PhysicalDevice(), properties);
}

inline void GetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2& formatProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, &formatProperties);
}
inline void GetPhysicalDeviceFormatProperties2KHR(VkFormat format, VkFormatProperties2& formatProperties) {
	GetPhysicalDeviceFormatProperties2KHR(DeviceContext::PhysicalDevice(), format, formatProperties);
}

inline VkResult GetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2& imageFormatInfo, VkImageFormatProperties2& imageFormatProperties) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, &imageFormatInfo, &imageFormatProperties);
}
inline VkResult GetPhysicalDeviceImageFormatProperties2KHR(const VkPhysicalDeviceImageFormatInfo2& imageFormatInfo, VkImageFormatProperties2& imageFormatProperties) {
	return GetPhysicalDeviceImageFormatProperties2KHR(DeviceContext::PhysicalDevice(), imageFormatInfo, imageFormatProperties);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceImageFormatProperties2KHR, PhysicalDeviceImageFormatInfo2, VkImageFormatProperties2&, imageFormatProperties);

inline void GetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t& queueFamilyPropertyCount, ArrayRef<VkQueueFamilyProperties2> queueFamilyProperties = {}) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, &queueFamilyPropertyCount, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkQueueFamilyProperties2> auto& queueFamilyProperties) {
	uint32_t count = 0;
	GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, count);
	queueFamilyProperties.resize(count);
	GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, count, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties2KHR(uint32_t& queueFamilyPropertyCount, ArrayRef<VkQueueFamilyProperties2> queueFamilyProperties = {}) {
	GetPhysicalDeviceQueueFamilyProperties2KHR(DeviceContext::PhysicalDevice(), queueFamilyPropertyCount, queueFamilyProperties);
}
inline void GetPhysicalDeviceQueueFamilyProperties2KHR(IsDynamicArray<VkQueueFamilyProperties2> auto& queueFamilyProperties) {
	GetPhysicalDeviceQueueFamilyProperties2KHR(DeviceContext::PhysicalDevice(), queueFamilyProperties);
}

inline void GetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2& memoryProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, &memoryProperties);
}
inline void GetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDeviceMemoryProperties2& memoryProperties) {
	GetPhysicalDeviceMemoryProperties2KHR(DeviceContext::PhysicalDevice(), memoryProperties);
}

inline void GetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, uint32_t& propertyCount, ArrayRef<VkSparseImageFormatProperties2> properties = {}) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, &formatInfo, &propertyCount, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, IsDynamicArray<VkSparseImageFormatProperties2> auto& properties) {
	uint32_t count = 0;
	GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, formatInfo, count);
	properties.resize(count);
	GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, formatInfo, count, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties2KHR(const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, uint32_t& propertyCount, ArrayRef<VkSparseImageFormatProperties2> properties = {}) {
	GetPhysicalDeviceSparseImageFormatProperties2KHR(DeviceContext::PhysicalDevice(), formatInfo, propertyCount, properties);
}
inline void GetPhysicalDeviceSparseImageFormatProperties2KHR(const VkPhysicalDeviceSparseImageFormatInfo2& formatInfo, IsDynamicArray<VkSparseImageFormatProperties2> auto& properties) {
	GetPhysicalDeviceSparseImageFormatProperties2KHR(DeviceContext::PhysicalDevice(), formatInfo, properties);
}
DefineRaiiFunction_L(GetPhysicalDeviceSparseImageFormatProperties2KHR, PhysicalDeviceSparseImageFormatInfo2, IsDynamicArray<VkSparseImageFormatProperties2> auto&, properties);

inline void GetDeviceGroupPeerMemoryFeaturesKHR(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags& peerMemoryFeatures) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceGroupPeerMemoryFeaturesKHR(DeviceContext::Device(), heapIndex, localDeviceIndex, remoteDeviceIndex, &peerMemoryFeatures);
}

inline void CmdSetDeviceMaskKHR(uint32_t deviceMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDeviceMaskKHR(ThreadContext::CommandBuffer(), deviceMask);
}

inline void CmdDispatchBaseKHR(uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDispatchBaseKHR(ThreadContext::CommandBuffer(), baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

inline void TrimCommandPoolKHR(VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkTrimCommandPoolKHR(DeviceContext::Device(), commandPool, flags);
}

inline VkResult EnumeratePhysicalDeviceGroupsKHR(uint32_t& physicalDeviceGroupCount, ArrayRef<VkPhysicalDeviceGroupProperties> physicalDeviceGroupProperties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkEnumeratePhysicalDeviceGroupsKHR(InstanceContext::Instance(), &physicalDeviceGroupCount, physicalDeviceGroupProperties);
}
inline VkResult EnumeratePhysicalDeviceGroupsKHR(IsDynamicArray<VkPhysicalDeviceGroupProperties> auto& physicalDeviceGroupProperties) {
	uint32_t count = 0;
	VkResult result = EnumeratePhysicalDeviceGroupsKHR(count);
	if (result == VK_SUCCESS)
		physicalDeviceGroupProperties.resize(count),
		result = EnumeratePhysicalDeviceGroupsKHR(count, physicalDeviceGroupProperties);
	return result;
}

inline void GetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo& externalBufferInfo, VkExternalBufferProperties& externalBufferProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, &externalBufferInfo, &externalBufferProperties);
}
inline void GetPhysicalDeviceExternalBufferPropertiesKHR(const VkPhysicalDeviceExternalBufferInfo& externalBufferInfo, VkExternalBufferProperties& externalBufferProperties) {
	GetPhysicalDeviceExternalBufferPropertiesKHR(DeviceContext::PhysicalDevice(), externalBufferInfo, externalBufferProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceExternalBufferPropertiesKHR, PhysicalDeviceExternalBufferInfo, VkExternalBufferProperties&, externalBufferProperties);

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImportMemoryFdInfoKHR) {
	StructureClassHeader(ImportMemoryFdInfoKHR);
	DefineSetter_Copy(HandleType, VkExternalMemoryHandleTypeFlagBits, handleType);
	DefineSetter_Copy(Fd, int, fd);
};
VK_ENCAPSULATION_STRUCTURE_END(ImportMemoryFdInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryFdPropertiesKHR) {
	StructureClassHeader(MemoryFdPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryFdPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryGetFdInfoKHR) {
	StructureClassHeader(MemoryGetFdInfoKHR);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(HandleType, VkExternalMemoryHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryGetFdInfoKHR)

inline VkResult GetMemoryFdKHR(const VkMemoryGetFdInfoKHR& getFdInfo, int& fd) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetMemoryFdKHR(DeviceContext::Device(), &getFdInfo, &fd);
}
DefineRaiiFunction_ResultL(VkResult, GetMemoryFdKHR, MemoryGetFdInfoKHR, int&, fd);

inline VkResult GetMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR& memoryFdProperties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetMemoryFdPropertiesKHR(DeviceContext::Device(), handleType, fd, &memoryFdProperties);
}

inline void GetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo& externalSemaphoreInfo, VkExternalSemaphoreProperties& externalSemaphoreProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, &externalSemaphoreInfo, &externalSemaphoreProperties);
}
inline void GetPhysicalDeviceExternalSemaphorePropertiesKHR(const VkPhysicalDeviceExternalSemaphoreInfo& externalSemaphoreInfo, VkExternalSemaphoreProperties& externalSemaphoreProperties) {
	GetPhysicalDeviceExternalSemaphorePropertiesKHR(DeviceContext::PhysicalDevice(), externalSemaphoreInfo, externalSemaphoreProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceExternalSemaphorePropertiesKHR, PhysicalDeviceExternalSemaphoreInfo, VkExternalSemaphoreProperties&, externalSemaphoreProperties);

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImportSemaphoreFdInfoKHR) {
	StructureClassHeader(ImportSemaphoreFdInfoKHR);
	DefineSetter_Copy(Semaphore, VkSemaphore, semaphore);
	DefineSetter_Copy(Flags, VkSemaphoreImportFlags, flags);
	DefineSetter_Copy(HandleType, VkExternalSemaphoreHandleTypeFlagBits, handleType);
	DefineSetter_Copy(Fd, int, fd);
};
VK_ENCAPSULATION_STRUCTURE_END(ImportSemaphoreFdInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SemaphoreGetFdInfoKHR) {
	StructureClassHeader(SemaphoreGetFdInfoKHR);
	DefineSetter_Copy(Semaphore, VkSemaphore, semaphore);
	DefineSetter_Copy(HandleType, VkExternalSemaphoreHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(SemaphoreGetFdInfoKHR)

inline VkResult ImportSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR& importSemaphoreFdInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkImportSemaphoreFdKHR(DeviceContext::Device(), &importSemaphoreFdInfo);
}
DefineRaiiFunction_Result(VkResult, ImportSemaphoreFdKHR, ImportSemaphoreFdInfoKHR);

inline VkResult GetSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR& getFdInfo, int& fd) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetSemaphoreFdKHR(DeviceContext::Device(), &getFdInfo, &fd);
}
DefineRaiiFunction_ResultL(VkResult, GetSemaphoreFdKHR, SemaphoreGetFdInfoKHR, int&, fd);

inline void CmdPushDescriptorSetKHR(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, ArrayRef<const VkWriteDescriptorSet> descriptorWrites) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSetKHR(ThreadContext::CommandBuffer(), pipelineBindPoint, layout, set, descriptorWrites.size(), descriptorWrites);
}

inline void CmdPushDescriptorSetWithTemplateKHR(VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, ArrayRef<const void> data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSetWithTemplateKHR(ThreadContext::CommandBuffer(), descriptorUpdateTemplate, layout, set, data);
}
inline void CmdPushDescriptorSetWithTemplateKHR(VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const IsNotRangeOrPointer auto& data) {
	CmdPushDescriptorSetWithTemplateKHR(descriptorUpdateTemplate, layout, set, { 0, &data });
}

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(RectLayerKHR) {
	StructureClassHeader_NoSType(RectLayerKHR);
	DefineSetter_Copy(Offset, VkOffset2D, offset);
	DefineSetter_Copy(Extent, VkExtent2D, extent);
	DefineSetter_Copy(Layer, uint32_t, layer);
};
VK_ENCAPSULATION_STRUCTURE_END(RectLayerKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PresentRegionKHR) {
	StructureClassHeader_NoSType(PresentRegionKHR);
	DefineSetter_Copy(RectangleCount, uint32_t, rectangleCount);
	DefineSetter_ArrayRef(Rectangles, const VkRectLayerKHR, rectangles, rectangleCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PresentRegionKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PresentRegionsKHR) {
	StructureClassHeader(PresentRegionsKHR);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(Regions, const VkPresentRegionKHR, regions, swapchainCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PresentRegionsKHR)

inline VkResult CreateDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfo& createInfo, HandleRef<VkDescriptorUpdateTemplate> descriptorUpdateTemplate) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateDescriptorUpdateTemplateKHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &descriptorUpdateTemplate);
}
DefineRaiiFunction_ResultL(VkResult, CreateDescriptorUpdateTemplateKHR, DescriptorUpdateTemplateCreateInfo, HandleRef<VkDescriptorUpdateTemplate>, descriptorUpdateTemplate);

inline void DestroyDescriptorUpdateTemplateKHR(HandleRef<VkDescriptorUpdateTemplate> descriptorUpdateTemplate, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyDescriptorUpdateTemplateKHR(DeviceContext::Device(), descriptorUpdateTemplate, &allocator);
	descriptorUpdateTemplate = VK_NULL_HANDLE;
}

inline void UpdateDescriptorSetWithTemplateKHR(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, ArrayRef<const void> data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkUpdateDescriptorSetWithTemplateKHR(DeviceContext::Device(), descriptorSet, descriptorUpdateTemplate, data);
}
inline void UpdateDescriptorSetWithTemplateKHR(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const IsNotRangeOrPointer auto& data) {
	UpdateDescriptorSetWithTemplateKHR(DeviceContext::Device(), descriptorSet, descriptorUpdateTemplate, { 0, &data });
}

inline VkResult CreateRenderPass2KHR(const VkRenderPassCreateInfo2& createInfo, HandleRef<VkRenderPass> renderPass) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateRenderPass2KHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &renderPass);
}
DefineRaiiFunction_ResultL(VkResult, CreateRenderPass2KHR, RenderPassCreateInfo2, HandleRef<VkRenderPass>, renderPass);

inline void CmdBeginRenderPass2KHR(const VkRenderPassBeginInfo& renderPassBegin, const VkSubpassBeginInfo& subpassBeginInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginRenderPass2KHR(ThreadContext::CommandBuffer(), &renderPassBegin, &subpassBeginInfo);
}
DefineRaiiFunction_TwoStruct(CmdBeginRenderPass2KHR, RenderPassBeginInfo, SubpassBeginInfo,
	DefineSetter_Copy(RenderPass, VkRenderPass, renderPass)
	DefineSetter_Copy(Framebuffer, VkFramebuffer, framebuffer)
	DefineSetter_Copy(RenderArea, VkRect2D, renderArea)
	DefineSetter_ArrayRef(ClearValues, const VkClearValue, clearValues, clearValueCount)
	DefineSetter_Copy(Contents, VkSubpassContents, contents));

inline void CmdNextSubpass2KHR(const VkSubpassBeginInfo& subpassBeginInfo, const VkSubpassEndInfo& subpassEndInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdNextSubpass2KHR(ThreadContext::CommandBuffer(), &subpassBeginInfo, &subpassEndInfo);
}
DefineRaiiFunction_TwoStruct(CmdNextSubpass2KHR, SubpassBeginInfo, SubpassEndInfo,
	DefineSetter_Copy(Contents, VkSubpassContents, contents));

inline void CmdEndRenderPass2KHR(const VkSubpassEndInfo& subpassEndInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndRenderPass2KHR(ThreadContext::CommandBuffer(), &subpassEndInfo);
}
DefineRaiiFunction(CmdEndRenderPass2KHR, SubpassEndInfo);

VK_ENCAPSULATION_STRUCTURE_BEGIN(SharedPresentSurfaceCapabilitiesKHR) {
	StructureClassHeader(SharedPresentSurfaceCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SharedPresentSurfaceCapabilitiesKHR)

inline VkResult GetSwapchainStatusKHR(VkSwapchainKHR swapchain) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetSwapchainStatusKHR(DeviceContext::Device(), swapchain);
}

inline void GetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo& externalFenceInfo, VkExternalFenceProperties& externalFenceProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, &externalFenceInfo, &externalFenceProperties);
}
inline void GetPhysicalDeviceExternalFencePropertiesKHR(const VkPhysicalDeviceExternalFenceInfo& externalFenceInfo, VkExternalFenceProperties& externalFenceProperties) {
	GetPhysicalDeviceExternalFencePropertiesKHR(DeviceContext::PhysicalDevice(), externalFenceInfo, externalFenceProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceExternalFencePropertiesKHR, PhysicalDeviceExternalFenceInfo, VkExternalFenceProperties&, externalFenceProperties);

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImportFenceFdInfoKHR) {
	StructureClassHeader(ImportFenceFdInfoKHR);
	DefineSetter_Copy(Fence, VkFence, fence);
	DefineSetter_Copy(Flags, VkFenceImportFlags, flags);
	DefineSetter_Copy(HandleType, VkExternalFenceHandleTypeFlagBits, handleType);
	DefineSetter_Copy(Fd, int, fd);
};
VK_ENCAPSULATION_STRUCTURE_END(ImportFenceFdInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FenceGetFdInfoKHR) {
	StructureClassHeader(FenceGetFdInfoKHR);
	DefineSetter_Copy(Fence, VkFence, fence);
	DefineSetter_Copy(HandleType, VkExternalFenceHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(FenceGetFdInfoKHR)

inline VkResult ImportFenceFdKHR(const VkImportFenceFdInfoKHR& importFenceFdInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkImportFenceFdKHR(DeviceContext::Device(), &importFenceFdInfo);
}
DefineRaiiFunction_Result(VkResult, ImportFenceFdKHR, ImportFenceFdInfoKHR);

inline VkResult GetFenceFdKHR(const VkFenceGetFdInfoKHR& getFdInfo, int& fd) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetFenceFdKHR(DeviceContext::Device(), &getFdInfo, &fd);
}
DefineRaiiFunction_ResultL(VkResult, GetFenceFdKHR, FenceGetFdInfoKHR, int&, fd);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePerformanceQueryFeaturesKHR) {
	StructureClassHeader(PhysicalDevicePerformanceQueryFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePerformanceQueryFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePerformanceQueryPropertiesKHR) {
	StructureClassHeader(PhysicalDevicePerformanceQueryPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePerformanceQueryPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerformanceCounterKHR) {
	StructureClassHeader(PerformanceCounterKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceCounterKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerformanceCounterDescriptionKHR) {
	StructureClassHeader(PerformanceCounterDescriptionKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceCounterDescriptionKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueryPoolPerformanceCreateInfoKHR) {
	StructureClassHeader(QueryPoolPerformanceCreateInfoKHR);
	DefineSetter_Copy(QueueFamilyIndex, uint32_t, queueFamilyIndex);
	DefineSetter_Copy(CounterIndexCount, uint32_t, counterIndexCount);
	DefineSetter_ArrayRef(CounterIndices, const uint32_t, counterIndices, counterIndexCount);
};
VK_ENCAPSULATION_STRUCTURE_END(QueryPoolPerformanceCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(PerformanceCounterResultKHR) {
	StructureClassHeader_UnionWrapper(PerformanceCounterResultKHR);
	union {
		int32_t  int32;
		int64_t  int64;
		uint32_t uint32;
		uint64_t uint64;
		float    float32;
		double   float64;
	};
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceCounterResultKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AcquireProfilingLockInfoKHR) {
	StructureClassHeader(AcquireProfilingLockInfoKHR);
	DefineSetter_Copy(Flags, VkAcquireProfilingLockFlagsKHR, flags);
	DefineSetter_Copy(Timeout, uint64_t, timeout);
};
VK_ENCAPSULATION_STRUCTURE_END(AcquireProfilingLockInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerformanceQuerySubmitInfoKHR) {
	StructureClassHeader(PerformanceQuerySubmitInfoKHR);
	DefineSetter_Copy(CounterPassIndex, uint32_t, counterPassIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceQuerySubmitInfoKHR)

inline VkResult EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t& counterCount, ArrayRef<VkPerformanceCounterKHR> counters = {}, ArrayRef<VkPerformanceCounterDescriptionKHR> counterDescriptions = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, &counterCount, counters, counterDescriptions);
}
inline VkResult EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IsDynamicArray<VkPerformanceCounterKHR> auto& counters, IsDynamicArray<VkPerformanceCounterDescriptionKHR> auto& counterDescriptions) {
	uint32_t count = 0;
	VkResult result = EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, count);
	if (result == VK_SUCCESS)
		counters.resize(count),
		counterDescriptions.resize(count),
		result = EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, count, counters, counterDescriptions);
	return result;
}
inline VkResult EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(uint32_t queueFamilyIndex, uint32_t& counterCount, ArrayRef<VkPerformanceCounterKHR> counters = {}, ArrayRef<VkPerformanceCounterDescriptionKHR> counterDescriptions = {}) {
	return EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(DeviceContext::PhysicalDevice(), queueFamilyIndex, counterCount, counters, counterDescriptions);
}
inline VkResult EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(uint32_t queueFamilyIndex, IsDynamicArray<VkPerformanceCounterKHR> auto& counters, IsDynamicArray<VkPerformanceCounterDescriptionKHR> auto& counterDescriptions) {
	return EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(DeviceContext::PhysicalDevice(), queueFamilyIndex, counters, counterDescriptions);
}

inline void GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR& performanceQueryCreateInfo, uint32_t& numPasses) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, &performanceQueryCreateInfo, &numPasses);
}
inline void GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const VkQueryPoolPerformanceCreateInfoKHR& performanceQueryCreateInfo, uint32_t& numPasses) {
	GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(DeviceContext::PhysicalDevice(), performanceQueryCreateInfo, numPasses);
}
DefineRaiiFunction_L(GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR, QueryPoolPerformanceCreateInfoKHR, uint32_t&, numPasses);

inline VkResult AcquireProfilingLockKHR(const VkAcquireProfilingLockInfoKHR& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkAcquireProfilingLockKHR(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkResult, AcquireProfilingLockKHR, AcquireProfilingLockInfoKHR);

inline void ReleaseProfilingLockKHR() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkReleaseProfilingLockKHR(DeviceContext::Device());
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSurfaceInfo2KHR) {
	StructureClassHeader(PhysicalDeviceSurfaceInfo2KHR);
	DefineSetter_Copy(Surface, VkSurfaceKHR, surface);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSurfaceInfo2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfaceCapabilities2KHR) {
	StructureClassHeader(SurfaceCapabilities2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceCapabilities2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfaceFormat2KHR) {
	StructureClassHeader(SurfaceFormat2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceFormat2KHR)

inline VkResult GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR& surfaceInfo, VkSurfaceCapabilities2KHR& surfaceCapabilities) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, &surfaceInfo, &surfaceCapabilities);
}
inline VkResult GetPhysicalDeviceSurfaceCapabilities2KHR(const VkPhysicalDeviceSurfaceInfo2KHR& surfaceInfo, VkSurfaceCapabilities2KHR& surfaceCapabilities) {
	return GetPhysicalDeviceSurfaceCapabilities2KHR(DeviceContext::PhysicalDevice(), surfaceInfo, surfaceCapabilities);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceSurfaceCapabilities2KHR, PhysicalDeviceSurfaceInfo2KHR, VkSurfaceCapabilities2KHR&, surfaceCapabilities);

inline VkResult GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR& surfaceInfo, uint32_t& surfaceFormatCount, ArrayRef<VkSurfaceFormat2KHR> surfaceFormats = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, &surfaceInfo, &surfaceFormatCount, surfaceFormats);
}
inline VkResult GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR& surfaceInfo, IsDynamicArray<VkSurfaceFormat2KHR> auto& surfaceFormats) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, surfaceInfo, count);
	if (result == VK_SUCCESS)
		surfaceFormats.resize(count),
		result = GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, surfaceInfo, count, surfaceFormats);
	return result;
}
inline VkResult GetPhysicalDeviceSurfaceFormats2KHR(const VkPhysicalDeviceSurfaceInfo2KHR& surfaceInfo, uint32_t& surfaceFormatCount, ArrayRef<VkSurfaceFormat2KHR> surfaceFormats = {}) {
	return GetPhysicalDeviceSurfaceFormats2KHR(DeviceContext::PhysicalDevice(), surfaceInfo, surfaceFormatCount, surfaceFormats);
}
inline VkResult GetPhysicalDeviceSurfaceFormats2KHR(const VkPhysicalDeviceSurfaceInfo2KHR& surfaceInfo, IsDynamicArray<VkSurfaceFormat2KHR> auto& surfaceFormats) {
	return GetPhysicalDeviceSurfaceFormats2KHR(DeviceContext::PhysicalDevice(), surfaceInfo, surfaceFormats);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceSurfaceFormats2KHR, PhysicalDeviceSurfaceInfo2KHR, IsDynamicArray<VkSurfaceFormat2KHR> auto&, surfaceFormats);

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayProperties2KHR) {
	StructureClassHeader(DisplayProperties2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayProperties2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayPlaneProperties2KHR) {
	StructureClassHeader(DisplayPlaneProperties2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPlaneProperties2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayModeProperties2KHR) {
	StructureClassHeader(DisplayModeProperties2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayModeProperties2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayPlaneInfo2KHR) {
	StructureClassHeader(DisplayPlaneInfo2KHR);
	DefineSetter_Copy(Mode, VkDisplayModeKHR, mode);
	DefineSetter_Copy(PlaneIndex, uint32_t, planeIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPlaneInfo2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayPlaneCapabilities2KHR) {
	StructureClassHeader(DisplayPlaneCapabilities2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPlaneCapabilities2KHR)

inline VkResult GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkDisplayProperties2KHR> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkDisplayProperties2KHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceDisplayProperties2KHR(uint32_t& propertyCount, ArrayRef<VkDisplayProperties2KHR> properties = {}) {
	return GetPhysicalDeviceDisplayProperties2KHR(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayProperties2KHR(IsDynamicArray<VkDisplayProperties2KHR> auto& properties) {
	return GetPhysicalDeviceDisplayProperties2KHR(DeviceContext::PhysicalDevice(), properties);
}

inline VkResult GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkDisplayPlaneProperties2KHR> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkDisplayPlaneProperties2KHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceDisplayPlaneProperties2KHR(uint32_t& propertyCount, ArrayRef<VkDisplayPlaneProperties2KHR> properties = {}) {
	return GetPhysicalDeviceDisplayPlaneProperties2KHR(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceDisplayPlaneProperties2KHR(IsDynamicArray<VkDisplayPlaneProperties2KHR> auto& properties) {
	return GetPhysicalDeviceDisplayPlaneProperties2KHR(DeviceContext::PhysicalDevice(), properties);
}

inline VkResult GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t& propertyCount, ArrayRef<VkDisplayModeProperties2KHR> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetDisplayModeProperties2KHR(physicalDevice, display, &propertyCount, properties);
}
inline VkResult GetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, IsDynamicArray<VkDisplayModeProperties2KHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetDisplayModeProperties2KHR(physicalDevice, display, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetDisplayModeProperties2KHR(physicalDevice, display, count, properties);
	return result;
}
inline VkResult GetDisplayModeProperties2KHR(VkDisplayKHR display, uint32_t& propertyCount, ArrayRef<VkDisplayModeProperties2KHR> properties = {}) {
	return GetDisplayModeProperties2KHR(DeviceContext::PhysicalDevice(), display, propertyCount, properties);
}
inline VkResult GetDisplayModeProperties2KHR(VkDisplayKHR display, IsDynamicArray<VkDisplayModeProperties2KHR> auto& properties) {
	return GetDisplayModeProperties2KHR(DeviceContext::PhysicalDevice(), display, properties);
}

inline VkResult GetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR& displayPlaneInfo, VkDisplayPlaneCapabilities2KHR& capabilities) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetDisplayPlaneCapabilities2KHR(physicalDevice, &displayPlaneInfo, &capabilities);
}
inline VkResult GetDisplayPlaneCapabilities2KHR(const VkDisplayPlaneInfo2KHR& displayPlaneInfo, VkDisplayPlaneCapabilities2KHR& capabilities) {
	return GetDisplayPlaneCapabilities2KHR(DeviceContext::PhysicalDevice(), displayPlaneInfo, capabilities);
}
DefineRaiiFunction_ResultL(VkResult, GetDisplayPlaneCapabilities2KHR, DisplayPlaneInfo2KHR, VkDisplayPlaneCapabilities2KHR&, capabilities);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderBfloat16FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceShaderBfloat16FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderBfloat16FeaturesKHR)

inline void GetImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageMemoryRequirements2KHR(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetImageMemoryRequirements2KHR, ImageMemoryRequirementsInfo2, VkMemoryRequirements2&, memoryRequirements);

inline void GetBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferMemoryRequirements2KHR(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetBufferMemoryRequirements2KHR, BufferMemoryRequirementsInfo2, VkMemoryRequirements2&, memoryRequirements);

inline void GetImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2& info, uint32_t& sparseMemoryRequirementCount, ArrayRef<VkSparseImageMemoryRequirements2> sparseMemoryRequirements = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageSparseMemoryRequirements2KHR(DeviceContext::Device(), &info, &sparseMemoryRequirementCount, sparseMemoryRequirements);
}
inline void GetImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2& info, IsDynamicArray<VkSparseImageMemoryRequirements2> auto& sparseMemoryRequirements) {
	uint32_t count = 0;
	GetImageSparseMemoryRequirements2KHR(info, count);
	sparseMemoryRequirements.resize(count);
	GetImageSparseMemoryRequirements2KHR(info, count, sparseMemoryRequirements);
}
DefineRaiiFunction_L(GetImageSparseMemoryRequirements2KHR, ImageSparseMemoryRequirementsInfo2, IsDynamicArray<VkSparseImageMemoryRequirements2> auto&, sparseMemoryRequirements);

inline VkResult CreateSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfo& createInfo, HandleRef<VkSamplerYcbcrConversion> ycbcrConversion) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateSamplerYcbcrConversionKHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &ycbcrConversion);
}
DefineRaiiFunction_ResultL(VkResult, CreateSamplerYcbcrConversionKHR, SamplerYcbcrConversionCreateInfo, HandleRef<VkSamplerYcbcrConversion>, ycbcrConversion);

inline void DestroySamplerYcbcrConversionKHR(HandleRef<VkSamplerYcbcrConversion> ycbcrConversion, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroySamplerYcbcrConversionKHR(DeviceContext::Device(), ycbcrConversion, &allocator);
	ycbcrConversion = VK_NULL_HANDLE;
}

inline VkResult BindBufferMemory2KHR(ArrayRef<const VkBindBufferMemoryInfo> bindInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindBufferMemory2KHR(DeviceContext::Device(), bindInfos.size(), bindInfos);
}
DefineRaiiFunction_Result(VkResult, BindBufferMemory2KHR, BindBufferMemoryInfo);

inline VkResult BindImageMemory2KHR(ArrayRef<const VkBindImageMemoryInfo> bindInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindImageMemory2KHR(DeviceContext::Device(), bindInfos.size(), bindInfos);
}
DefineRaiiFunction_Result(VkResult, BindImageMemory2KHR, BindImageMemoryInfo);

inline void GetDescriptorSetLayoutSupportKHR(const VkDescriptorSetLayoutCreateInfo& createInfo, VkDescriptorSetLayoutSupport& support) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDescriptorSetLayoutSupportKHR(DeviceContext::Device(), &createInfo, &support);
}
DefineRaiiFunction_L(GetDescriptorSetLayoutSupportKHR, DescriptorSetLayoutCreateInfo, VkDescriptorSetLayoutSupport&, support);

inline void CmdDrawIndirectCountKHR(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndirectCountKHR(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

inline void CmdDrawIndexedIndirectCountKHR(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndexedIndirectCountKHR(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderClockFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceShaderClockFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderClockFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH265ProfileInfoKHR) {
	StructureClassHeader(VideoDecodeH265ProfileInfoKHR);
	DefineSetter_Copy(StdProfileIdc, StdVideoH265ProfileIdc, stdProfileIdc);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH265ProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH265CapabilitiesKHR) {
	StructureClassHeader(VideoDecodeH265CapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH265CapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH265SessionParametersAddInfoKHR) {
	StructureClassHeader(VideoDecodeH265SessionParametersAddInfoKHR);
	DefineSetter_Copy(StdVPSCount, uint32_t, stdVPSCount);
	DefineSetter_ArrayRef(StdVPSs, const StdVideoH265VideoParameterSet, stdVPSs, stdVPSCount);
	DefineSetter_Copy(StdSPSCount, uint32_t, stdSPSCount);
	DefineSetter_ArrayRef(StdSPSs, const StdVideoH265SequenceParameterSet, stdSPSs, stdSPSCount);
	DefineSetter_Copy(StdPPSCount, uint32_t, stdPPSCount);
	DefineSetter_ArrayRef(StdPPSs, const StdVideoH265PictureParameterSet, stdPPSs, stdPPSCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH265SessionParametersAddInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH265SessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoDecodeH265SessionParametersCreateInfoKHR);
	DefineSetter_Copy(MaxStdVPSCount, uint32_t, maxStdVPSCount);
	DefineSetter_Copy(MaxStdSPSCount, uint32_t, maxStdSPSCount);
	DefineSetter_Copy(MaxStdPPSCount, uint32_t, maxStdPPSCount);
	DefineSetter_Ref(ParametersAddInfo, const VkVideoDecodeH265SessionParametersAddInfoKHR, parametersAddInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH265SessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH265PictureInfoKHR) {
	StructureClassHeader(VideoDecodeH265PictureInfoKHR);
	DefineSetter_Ref(StdPictureInfo, const StdVideoDecodeH265PictureInfo, stdPictureInfo);
	DefineSetter_Copy(SliceSegmentCount, uint32_t, sliceSegmentCount);
	DefineSetter_ArrayRef(SliceSegmentOffsets, const uint32_t, sliceSegmentOffsets, sliceSegmentCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH265PictureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH265DpbSlotInfoKHR) {
	StructureClassHeader(VideoDecodeH265DpbSlotInfoKHR);
	DefineSetter_Ref(StdReferenceInfo, const StdVideoDecodeH265ReferenceInfo, stdReferenceInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH265DpbSlotInfoKHR)

inline VkResult GetSemaphoreCounterValueKHR(VkSemaphore semaphore, uint64_t& value) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetSemaphoreCounterValueKHR(DeviceContext::Device(), semaphore, &value);
}

inline VkResult WaitSemaphoresKHR(const VkSemaphoreWaitInfo& waitInfo, uint64_t timeout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkWaitSemaphoresKHR(DeviceContext::Device(), &waitInfo, timeout);
}
DefineRaiiFunction_ResultL(VkResult, WaitSemaphoresKHR, SemaphoreWaitInfo, uint64_t, timeout);

inline VkResult SignalSemaphoreKHR(const VkSemaphoreSignalInfo& signalInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkSignalSemaphoreKHR(DeviceContext::Device(), &signalInfo);
}
DefineRaiiFunction_Result(VkResult, SignalSemaphoreKHR, SemaphoreSignalInfo);

VK_ENCAPSULATION_STRUCTURE_BEGIN(FragmentShadingRateAttachmentInfoKHR) {
	StructureClassHeader(FragmentShadingRateAttachmentInfoKHR);
	DefineSetter_Ref(FragmentShadingRateAttachment, const VkAttachmentReference2, fragmentShadingRateAttachment);
	DefineSetter_Copy(ShadingRateAttachmentTexelSize, VkExtent2D, shadingRateAttachmentTexelSize);
};
VK_ENCAPSULATION_STRUCTURE_END(FragmentShadingRateAttachmentInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineFragmentShadingRateStateCreateInfoKHR) {
	StructureClassHeader(PipelineFragmentShadingRateStateCreateInfoKHR);
	DefineSetter_Copy(FragmentSize, VkExtent2D, fragmentSize);
	// VkFragmentShadingRateCombinerOpKHR combinerOps[2];
	DefineSetter_ArrayCopy(CombinerOps, VkFragmentShadingRateCombinerOpKHR, combinerOps);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineFragmentShadingRateStateCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShadingRateFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceFragmentShadingRateFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShadingRateFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShadingRatePropertiesKHR) {
	StructureClassHeader(PhysicalDeviceFragmentShadingRatePropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShadingRatePropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShadingRateKHR) {
	StructureClassHeader(PhysicalDeviceFragmentShadingRateKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShadingRateKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingFragmentShadingRateAttachmentInfoKHR) {
	StructureClassHeader(RenderingFragmentShadingRateAttachmentInfoKHR);
	DefineSetter_Copy(ImageView, VkImageView, imageView);
	DefineSetter_Copy(ImageLayout, VkImageLayout, imageLayout);
	DefineSetter_Copy(ShadingRateAttachmentTexelSize, VkExtent2D, shadingRateAttachmentTexelSize);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingFragmentShadingRateAttachmentInfoKHR)

inline VkResult GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t& fragmentShadingRateCount, ArrayRef<VkPhysicalDeviceFragmentShadingRateKHR> fragmentShadingRates = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, &fragmentShadingRateCount, fragmentShadingRates);
}
inline VkResult GetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkPhysicalDeviceFragmentShadingRateKHR> auto& fragmentShadingRates) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, count);
	if (result == VK_SUCCESS)
		fragmentShadingRates.resize(count),
		result = GetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, count, fragmentShadingRates);
	return result;
}
inline VkResult GetPhysicalDeviceFragmentShadingRatesKHR(uint32_t& fragmentShadingRateCount, ArrayRef<VkPhysicalDeviceFragmentShadingRateKHR> fragmentShadingRates = {}) {
	return GetPhysicalDeviceFragmentShadingRatesKHR(DeviceContext::PhysicalDevice(), fragmentShadingRateCount, fragmentShadingRates);
}
inline VkResult GetPhysicalDeviceFragmentShadingRatesKHR(IsDynamicArray<VkPhysicalDeviceFragmentShadingRateKHR> auto& fragmentShadingRates) {
	return GetPhysicalDeviceFragmentShadingRatesKHR(DeviceContext::PhysicalDevice(), fragmentShadingRates);
}

inline void CmdSetFragmentShadingRateKHR(const VkExtent2D& fragmentSize, ArrayRef<const VkFragmentShadingRateCombinerOpKHR> combinerOps) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetFragmentShadingRateKHR(ThreadContext::CommandBuffer(), &fragmentSize, combinerOps);
}

inline void CmdSetRenderingAttachmentLocationsKHR(const VkRenderingAttachmentLocationInfo& locationInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRenderingAttachmentLocationsKHR(ThreadContext::CommandBuffer(), &locationInfo);
}
DefineRaiiFunction(CmdSetRenderingAttachmentLocationsKHR, RenderingAttachmentLocationInfo);

inline void CmdSetRenderingInputAttachmentIndicesKHR(const VkRenderingInputAttachmentIndexInfo& inputAttachmentIndexInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRenderingInputAttachmentIndicesKHR(ThreadContext::CommandBuffer(), &inputAttachmentIndexInfo);
}
DefineRaiiFunction(CmdSetRenderingInputAttachmentIndicesKHR, RenderingInputAttachmentIndexInfo);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderQuadControlFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceShaderQuadControlFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderQuadControlFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfaceProtectedCapabilitiesKHR) {
	StructureClassHeader(SurfaceProtectedCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceProtectedCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePresentWaitFeaturesKHR) {
	StructureClassHeader(PhysicalDevicePresentWaitFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePresentWaitFeaturesKHR)

inline VkResult WaitForPresentKHR(VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkWaitForPresentKHR(DeviceContext::Device(), swapchain, presentId, timeout);
}

inline VkDeviceAddress GetBufferDeviceAddressKHR(const VkBufferDeviceAddressInfo& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferDeviceAddressKHR(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkDeviceAddress, GetBufferDeviceAddressKHR, BufferDeviceAddressInfo);

inline uint64_t GetBufferOpaqueCaptureAddressKHR(const VkBufferDeviceAddressInfo& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferOpaqueCaptureAddressKHR(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkDeviceAddress, GetBufferOpaqueCaptureAddressKHR, BufferDeviceAddressInfo);

inline uint64_t GetDeviceMemoryOpaqueCaptureAddressKHR(const VkDeviceMemoryOpaqueCaptureAddressInfo& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceMemoryOpaqueCaptureAddressKHR(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(uint64_t, GetDeviceMemoryOpaqueCaptureAddressKHR, DeviceMemoryOpaqueCaptureAddressInfo);

inline VkResult CreateDeferredOperationKHR(HandleRef<VkDeferredOperationKHR> deferredOperation) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateDeferredOperationKHR(DeviceContext::Device(), ThreadContext::PAllocator(), &deferredOperation);
}

inline void DestroyDeferredOperationKHR(HandleRef<VkDeferredOperationKHR> operation, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyDeferredOperationKHR(DeviceContext::Device(), operation, &allocator);
	operation = VK_NULL_HANDLE;
}

inline uint32_t GetDeferredOperationMaxConcurrencyKHR(VkDeferredOperationKHR operation) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeferredOperationMaxConcurrencyKHR(DeviceContext::Device(), operation);
}

inline VkResult GetDeferredOperationResultKHR(VkDeferredOperationKHR operation) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeferredOperationResultKHR(DeviceContext::Device(), operation);
}

inline VkResult DeferredOperationJoinKHR(VkDeferredOperationKHR operation) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkDeferredOperationJoinKHR(DeviceContext::Device(), operation);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineExecutablePropertiesFeaturesKHR) {
	StructureClassHeader(PhysicalDevicePipelineExecutablePropertiesFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineExecutablePropertiesFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineInfoKHR) {
	StructureClassHeader(PipelineInfoKHR);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineExecutablePropertiesKHR) {
	StructureClassHeader(PipelineExecutablePropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineExecutablePropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineExecutableInfoKHR) {
	StructureClassHeader(PipelineExecutableInfoKHR);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
	DefineSetter_Copy(ExecutableIndex, uint32_t, executableIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineExecutableInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(PipelineExecutableStatisticValueKHR) {
	StructureClassHeader_UnionWrapper(PipelineExecutableStatisticValueKHR);
	union {
		VkBool32 b32;
		int64_t  i64;
		uint64_t u64;
		double   f64;
	};
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineExecutableStatisticValueKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineExecutableStatisticKHR) {
	StructureClassHeader(PipelineExecutableStatisticKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineExecutableStatisticKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineExecutableInternalRepresentationKHR) {
	StructureClassHeader(PipelineExecutableInternalRepresentationKHR);
	DefineSetter_ArrayRefIgnoreC(Data, void, data);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineExecutableInternalRepresentationKHR)

inline VkResult GetPipelineExecutablePropertiesKHR(const VkPipelineInfoKHR& pipelineInfo, uint32_t& executableCount, ArrayRef<VkPipelineExecutablePropertiesKHR> properties = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineExecutablePropertiesKHR(DeviceContext::Device(), &pipelineInfo, &executableCount, properties);
}
inline VkResult GetPipelineExecutablePropertiesKHR(const VkPipelineInfoKHR& pipelineInfo, IsDynamicArray<VkPipelineExecutablePropertiesKHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPipelineExecutablePropertiesKHR(pipelineInfo, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPipelineExecutablePropertiesKHR(pipelineInfo, count, properties);
	return result;
}
DefineRaiiFunction_ResultL(VkResult, GetPipelineExecutablePropertiesKHR, PipelineInfoKHR, IsDynamicArray<VkPipelineExecutablePropertiesKHR> auto&, properties);

inline VkResult GetPipelineExecutableStatisticsKHR(const VkPipelineExecutableInfoKHR& executableInfo, uint32_t& statisticCount, ArrayRef<VkPipelineExecutableStatisticKHR> statistics = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineExecutableStatisticsKHR(DeviceContext::Device(), &executableInfo, &statisticCount, statistics);
}
inline VkResult GetPipelineExecutableStatisticsKHR(const VkPipelineExecutableInfoKHR& executableInfo, IsDynamicArray<VkPipelineExecutableStatisticKHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPipelineExecutableStatisticsKHR(executableInfo, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPipelineExecutableStatisticsKHR(executableInfo, count, properties);
	return result;
}
DefineRaiiFunction_ResultL(VkResult, GetPipelineExecutableStatisticsKHR, PipelineExecutableInfoKHR, IsDynamicArray<VkPipelineExecutableStatisticKHR> auto&, properties);

inline VkResult GetPipelineExecutableInternalRepresentationsKHR(const VkPipelineExecutableInfoKHR& executableInfo, uint32_t& internalRepresentationCount, ArrayRef<VkPipelineExecutableInternalRepresentationKHR> internalRepresentations = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineExecutableInternalRepresentationsKHR(DeviceContext::Device(), &executableInfo, &internalRepresentationCount, internalRepresentations);
}
inline VkResult GetPipelineExecutableInternalRepresentationsKHR(const VkPipelineExecutableInfoKHR& executableInfo, IsDynamicArray<VkPipelineExecutableInternalRepresentationKHR> auto& internalRepresentations, IsDynamicByteArray auto& data) {
	uint32_t count = 0;
	VkResult result = GetPipelineExecutableInternalRepresentationsKHR(executableInfo, count);
	if (result == VK_SUCCESS)
		internalRepresentations.resize(count),
		result = GetPipelineExecutableInternalRepresentationsKHR(executableInfo, count, internalRepresentations);
	if (result == VK_SUCCESS) {
		size_t size = 0;
		for (auto& i : internalRepresentations)
			i.pData = reinterpret_cast<void*>(size),
			size += i.dataSize;
		data.resize(size);
		for (auto& i : internalRepresentations)
			i.pData = std::ranges::data(data) + reinterpret_cast<size_t>(i.pData);
		result = GetPipelineExecutableInternalRepresentationsKHR(executableInfo, count, internalRepresentations);
	}
	return result;
}

inline VkResult MapMemory2KHR(const VkMemoryMapInfo& memoryMapInfo, void*& pData) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkMapMemory2KHR(DeviceContext::Device(), &memoryMapInfo, &pData);
}
DefineRaiiFunction_ResultL(VkResult, MapMemory2KHR, MemoryMapInfo, void*&, pData);

inline VkResult UnmapMemory2KHR(const VkMemoryUnmapInfo& memoryUnmapInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkUnmapMemory2KHR(DeviceContext::Device(), &memoryUnmapInfo);
}
DefineRaiiFunction_Result(VkResult, UnmapMemory2KHR, MemoryUnmapInfo);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineLibraryCreateInfoKHR) {
	StructureClassHeader(PipelineLibraryCreateInfoKHR);
	DefineSetter_Copy(LibraryCount, uint32_t, libraryCount);
	DefineSetter_ArrayRef(Libraries, const VkPipeline, libraries, libraryCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineLibraryCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PresentIdKHR) {
	StructureClassHeader(PresentIdKHR);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(PresentIds, const uint64_t, presentIds, swapchainCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PresentIdKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePresentIdFeaturesKHR) {
	StructureClassHeader(PhysicalDevicePresentIdFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePresentIdFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeInfoKHR) {
	StructureClassHeader(VideoEncodeInfoKHR);
	DefineSetter_Copy(Flags, VkVideoEncodeFlagsKHR, flags);
	DefineSetter_Copy(DstBuffer, VkBuffer, dstBuffer);
	DefineSetter_Copy(DstBufferOffset, VkDeviceSize, dstBufferOffset);
	DefineSetter_Copy(DstBufferRange, VkDeviceSize, dstBufferRange);
	DefineSetter_Copy(SrcPictureResource, VkVideoPictureResourceInfoKHR, srcPictureResource);
	DefineSetter_Ref(SetupReferenceSlot, const VkVideoReferenceSlotInfoKHR, setupReferenceSlot);
	DefineSetter_Copy(ReferenceSlotCount, uint32_t, referenceSlotCount);
	DefineSetter_ArrayRef(ReferenceSlots, const VkVideoReferenceSlotInfoKHR, referenceSlots, referenceSlotCount);
	DefineSetter_Copy(PrecedingExternallyEncodedBytes, uint32_t, precedingExternallyEncodedBytes);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeCapabilitiesKHR) {
	StructureClassHeader(VideoEncodeCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueryPoolVideoEncodeFeedbackCreateInfoKHR) {
	StructureClassHeader(QueryPoolVideoEncodeFeedbackCreateInfoKHR);
	DefineSetter_Copy(EncodeFeedbackFlags, VkVideoEncodeFeedbackFlagsKHR, encodeFeedbackFlags);
};
VK_ENCAPSULATION_STRUCTURE_END(QueryPoolVideoEncodeFeedbackCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeUsageInfoKHR) {
	StructureClassHeader(VideoEncodeUsageInfoKHR);
	DefineSetter_Copy(VideoUsageHints, VkVideoEncodeUsageFlagsKHR, videoUsageHints);
	DefineSetter_Copy(VideoContentHints, VkVideoEncodeContentFlagsKHR, videoContentHints);
	DefineSetter_Copy(TuningMode, VkVideoEncodeTuningModeKHR, tuningMode);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeUsageInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeRateControlLayerInfoKHR) {
	StructureClassHeader(VideoEncodeRateControlLayerInfoKHR);
	DefineSetter_Copy(AverageBitrate, uint64_t, averageBitrate);
	DefineSetter_Copy(MaxBitrate, uint64_t, maxBitrate);
	DefineSetter_Copy(FrameRateNumerator, uint32_t, frameRateNumerator);
	DefineSetter_Copy(FrameRateDenominator, uint32_t, frameRateDenominator);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeRateControlLayerInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeRateControlInfoKHR) {
	StructureClassHeader(VideoEncodeRateControlInfoKHR);
	DefineSetter_Copy(Flags, VkVideoEncodeRateControlFlagsKHR, flags);
	DefineSetter_Copy(RateControlMode, VkVideoEncodeRateControlModeFlagBitsKHR, rateControlMode);
	DefineSetter_Copy(LayerCount, uint32_t, layerCount);
	DefineSetter_ArrayRef(Layers, const VkVideoEncodeRateControlLayerInfoKHR, layers, layerCount);
	DefineSetter_Copy(VirtualBufferSizeInMs, uint32_t, virtualBufferSizeInMs);
	DefineSetter_Copy(InitialVirtualBufferSizeInMs, uint32_t, initialVirtualBufferSizeInMs);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeRateControlInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoEncodeQualityLevelInfoKHR) {
	StructureClassHeader(PhysicalDeviceVideoEncodeQualityLevelInfoKHR);
	DefineSetter_Ref(VideoProfile, const VkVideoProfileInfoKHR, videoProfile);
	DefineSetter_Copy(QualityLevel, uint32_t, qualityLevel);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoEncodeQualityLevelInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeQualityLevelPropertiesKHR) {
	StructureClassHeader(VideoEncodeQualityLevelPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeQualityLevelPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeQualityLevelInfoKHR) {
	StructureClassHeader(VideoEncodeQualityLevelInfoKHR);
	DefineSetter_Copy(QualityLevel, uint32_t, qualityLevel);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeQualityLevelInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeSessionParametersGetInfoKHR) {
	StructureClassHeader(VideoEncodeSessionParametersGetInfoKHR);
	DefineSetter_Copy(VideoSessionParameters, VkVideoSessionParametersKHR, videoSessionParameters);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeSessionParametersGetInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeSessionParametersFeedbackInfoKHR) {
	StructureClassHeader(VideoEncodeSessionParametersFeedbackInfoKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeSessionParametersFeedbackInfoKHR)

inline VkResult GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR& qualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR& qualityLevelProperties) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(physicalDevice, &qualityLevelInfo, &qualityLevelProperties);
}
inline VkResult GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR& qualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR& qualityLevelProperties) {
	return GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(DeviceContext::PhysicalDevice(), qualityLevelInfo, qualityLevelProperties);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR, PhysicalDeviceVideoEncodeQualityLevelInfoKHR, VkVideoEncodeQualityLevelPropertiesKHR&, qualityLevelProperties);

inline VkResult GetEncodedVideoSessionParametersKHR(const VkVideoEncodeSessionParametersGetInfoKHR& videoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR& feedbackInfo, size_t& dataSize, ArrayRef<void> data = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetEncodedVideoSessionParametersKHR(DeviceContext::Device(), &videoSessionParametersInfo, &feedbackInfo, &dataSize, data);
}
inline VkResult GetEncodedVideoSessionParametersKHR(const VkVideoEncodeSessionParametersGetInfoKHR& videoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR& feedbackInfo, size_t& dataSize, IsNotRangeOrPointer auto& data) {
	return GetEncodedVideoSessionParametersKHR(videoSessionParametersInfo, feedbackInfo, dataSize, { 0, &data });
}
inline VkResult GetEncodedVideoSessionParametersKHR(const VkVideoEncodeSessionParametersGetInfoKHR& videoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR& feedbackInfo, IsDynamicByteArray auto& data) {
	size_t size = 0;
	VkResult result = GetEncodedVideoSessionParametersKHR(videoSessionParametersInfo, feedbackInfo, size);
	if (result == VK_SUCCESS)
		data.resize(size),
		result = GetEncodedVideoSessionParametersKHR(videoSessionParametersInfo, feedbackInfo, size, data);
	return result;
}

inline void CmdEncodeVideoKHR(const VkVideoEncodeInfoKHR& encodeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEncodeVideoKHR(ThreadContext::CommandBuffer(), &encodeInfo);
}
DefineRaiiFunction(CmdEncodeVideoKHR, VideoEncodeInfoKHR);

inline void CmdSetEvent2KHR(VkEvent event, const VkDependencyInfo& dependencyInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetEvent2KHR(ThreadContext::CommandBuffer(), event, &dependencyInfo);
}
DefineRaiiFunction_R(CmdSetEvent2KHR, VkEvent, event, DependencyInfo);

inline void CmdResetEvent2KHR(VkEvent event, VkPipelineStageFlags2 stageMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdResetEvent2KHR(ThreadContext::CommandBuffer(), event, stageMask);
}

inline void CmdWaitEvents2KHR(ArrayRef<const VkEvent> events, ArrayRef<const VkDependencyInfo> dependencyInfos) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWaitEvents2KHR(ThreadContext::CommandBuffer(), events.size(), events, dependencyInfos);
}
DefineRaiiFunction_R(CmdWaitEvents2KHR, VkEvent, event, DependencyInfo);

inline void CmdPipelineBarrier2KHR(const VkDependencyInfo& dependencyInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPipelineBarrier2KHR(ThreadContext::CommandBuffer(), &dependencyInfo);
}
DefineRaiiFunction(CmdPipelineBarrier2KHR, DependencyInfo);

inline void CmdWriteTimestamp2KHR(VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteTimestamp2KHR(ThreadContext::CommandBuffer(), stage, queryPool, query);
}

inline VkResult QueueSubmit2KHR(VkQueue queue, ArrayRef<const VkSubmitInfo2> submits, VkFence fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkQueueSubmit2KHR(queue, submits.size(), submits, fence);
}
inline VkResult QueueSubmit2KHR(ArrayRef<const VkSubmitInfo2> submits, VkFence fence) {
	return QueueSubmit2KHR(ThreadContext::Queue(), submits, fence);
}
DefineRaiiFunction_ResultL(VkResult, QueueSubmit2KHR, SubmitInfo2, VkFence, fence);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShaderBarycentricFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceFragmentShaderBarycentricFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShaderBarycentricFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShaderBarycentricPropertiesKHR) {
	StructureClassHeader(PhysicalDeviceFragmentShaderBarycentricPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShaderBarycentricPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR)

inline void CmdCopyBuffer2KHR(const VkCopyBufferInfo2& copyBufferInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyBuffer2KHR(ThreadContext::CommandBuffer(), &copyBufferInfo);
}
DefineRaiiFunction(CmdCopyBuffer2KHR, CopyBufferInfo2);

inline void CmdCopyImage2KHR(const VkCopyImageInfo2& copyImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyImage2KHR(ThreadContext::CommandBuffer(), &copyImageInfo);
}
DefineRaiiFunction(CmdCopyImage2KHR, CopyImageInfo2);

inline void CmdCopyBufferToImage2KHR(const VkCopyBufferToImageInfo2& copyBufferToImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyBufferToImage2KHR(ThreadContext::CommandBuffer(), &copyBufferToImageInfo);
}
DefineRaiiFunction(CmdCopyBufferToImage2KHR, CopyBufferToImageInfo2);

inline void CmdCopyImageToBuffer2KHR(const VkCopyImageToBufferInfo2& copyImageToBufferInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyImageToBuffer2KHR(ThreadContext::CommandBuffer(), &copyImageToBufferInfo);
}
DefineRaiiFunction(CmdCopyImageToBuffer2KHR, CopyImageToBufferInfo2);

inline void CmdBlitImage2KHR(const VkBlitImageInfo2& blitImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBlitImage2KHR(ThreadContext::CommandBuffer(), &blitImageInfo);
}
DefineRaiiFunction(CmdBlitImage2KHR, BlitImageInfo2);

inline void CmdResolveImage2KHR(const VkResolveImageInfo2& resolveImageInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdResolveImage2KHR(ThreadContext::CommandBuffer(), &resolveImageInfo);
}
DefineRaiiFunction(CmdResolveImage2KHR, ResolveImageInfo2);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingMaintenance1FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceRayTracingMaintenance1FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingMaintenance1FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(TraceRaysIndirectCommand2KHR) {
	StructureClassHeader_NoSType(TraceRaysIndirectCommand2KHR);
	DefineSetter_Copy(RaygenShaderRecordAddress, VkDeviceAddress, raygenShaderRecordAddress);
	DefineSetter_Copy(RaygenShaderRecordSize, VkDeviceSize, raygenShaderRecordSize);
	DefineSetter_Copy(MissShaderBindingTableAddress, VkDeviceAddress, missShaderBindingTableAddress);
	DefineSetter_Copy(MissShaderBindingTableSize, VkDeviceSize, missShaderBindingTableSize);
	DefineSetter_Copy(MissShaderBindingTableStride, VkDeviceSize, missShaderBindingTableStride);
	DefineSetter_Copy(HitShaderBindingTableAddress, VkDeviceAddress, hitShaderBindingTableAddress);
	DefineSetter_Copy(HitShaderBindingTableSize, VkDeviceSize, hitShaderBindingTableSize);
	DefineSetter_Copy(HitShaderBindingTableStride, VkDeviceSize, hitShaderBindingTableStride);
	DefineSetter_Copy(CallableShaderBindingTableAddress, VkDeviceAddress, callableShaderBindingTableAddress);
	DefineSetter_Copy(CallableShaderBindingTableSize, VkDeviceSize, callableShaderBindingTableSize);
	DefineSetter_Copy(CallableShaderBindingTableStride, VkDeviceSize, callableShaderBindingTableStride);
	DefineSetter_Copy(Width, uint32_t, width);
	DefineSetter_Copy(Height, uint32_t, height);
	DefineSetter_Copy(Depth, uint32_t, depth);
};
VK_ENCAPSULATION_STRUCTURE_END(TraceRaysIndirectCommand2KHR)

inline void CmdTraceRaysIndirect2KHR(VkDeviceAddress indirectDeviceAddress) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdTraceRaysIndirect2KHR(ThreadContext::CommandBuffer(), indirectDeviceAddress);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderUntypedPointersFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceShaderUntypedPointersFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderUntypedPointersFeaturesKHR)

inline void GetDeviceBufferMemoryRequirementsKHR(const VkDeviceBufferMemoryRequirements& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceBufferMemoryRequirementsKHR(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetDeviceBufferMemoryRequirementsKHR, DeviceBufferMemoryRequirements, VkMemoryRequirements2&, memoryRequirements);

inline void GetDeviceImageMemoryRequirementsKHR(const VkDeviceImageMemoryRequirements& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceImageMemoryRequirementsKHR(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetDeviceImageMemoryRequirementsKHR, DeviceImageMemoryRequirements, VkMemoryRequirements2&, memoryRequirements);

inline void GetDeviceImageSparseMemoryRequirementsKHR(const VkDeviceImageMemoryRequirements& info, uint32_t& sparseMemoryRequirementCount, ArrayRef<VkSparseImageMemoryRequirements2> sparseMemoryRequirements = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceImageSparseMemoryRequirementsKHR(DeviceContext::Device(), &info, &sparseMemoryRequirementCount, sparseMemoryRequirements);
}
inline void GetDeviceImageSparseMemoryRequirementsKHR(const VkDeviceImageMemoryRequirements& info, IsDynamicArray<VkSparseImageMemoryRequirements2> auto& sparseMemoryRequirements) {
	uint32_t count = 0;
	GetDeviceImageSparseMemoryRequirementsKHR(info, count);
	sparseMemoryRequirements.resize(count);
	GetDeviceImageSparseMemoryRequirementsKHR(info, count, sparseMemoryRequirements);
}
DefineRaiiFunction_L(GetDeviceImageSparseMemoryRequirementsKHR, DeviceImageMemoryRequirements, IsDynamicArray<VkSparseImageMemoryRequirements2> auto&, sparseMemoryRequirements);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR)

inline void CmdBindIndexBuffer2KHR(VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindIndexBuffer2KHR(ThreadContext::CommandBuffer(), buffer, offset, size, indexType);
}

inline void GetRenderingAreaGranularityKHR(const VkRenderingAreaInfo& renderingAreaInfo, VkExtent2D& granularity) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRenderingAreaGranularityKHR(DeviceContext::Device(), &renderingAreaInfo, &granularity);
}
DefineRaiiFunction_L(GetRenderingAreaGranularityKHR, RenderingAreaInfo, VkExtent2D&, granularity);

inline void GetDeviceImageSubresourceLayoutKHR(const VkDeviceImageSubresourceInfo& info, VkSubresourceLayout2& layout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceImageSubresourceLayoutKHR(DeviceContext::Device(), &info, &layout);
}
DefineRaiiFunction_L(GetDeviceImageSubresourceLayoutKHR, DeviceImageSubresourceInfo, VkSubresourceLayout2&, layout);

inline void GetImageSubresourceLayout2KHR(VkImage image, const VkImageSubresource2& subresource, VkSubresourceLayout2& layout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageSubresourceLayout2KHR(DeviceContext::Device(), image, &subresource, &layout);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfaceCapabilitiesPresentId2KHR) {
	StructureClassHeader(SurfaceCapabilitiesPresentId2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceCapabilitiesPresentId2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PresentId2KHR) {
	StructureClassHeader(PresentId2KHR);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(PresentIds, const uint64_t, presentIds, swapchainCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PresentId2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePresentId2FeaturesKHR) {
	StructureClassHeader(PhysicalDevicePresentId2FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePresentId2FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfaceCapabilitiesPresentWait2KHR) {
	StructureClassHeader(SurfaceCapabilitiesPresentWait2KHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceCapabilitiesPresentWait2KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePresentWait2FeaturesKHR) {
	StructureClassHeader(PhysicalDevicePresentWait2FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePresentWait2FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PresentWait2InfoKHR) {
	StructureClassHeader(PresentWait2InfoKHR);
	DefineSetter_Copy(PresentId, uint64_t, presentId);
	DefineSetter_Copy(Timeout, uint64_t, timeout);
};
VK_ENCAPSULATION_STRUCTURE_END(PresentWait2InfoKHR)

inline VkResult WaitForPresent2KHR(VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR& presentWait2Info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkWaitForPresent2KHR(DeviceContext::Device(), swapchain, &presentWait2Info);
}
DefineRaiiFunction_ResultR(VkResult, WaitForPresent2KHR, VkSwapchainKHR, swapchain, PresentWait2InfoKHR);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingPositionFetchFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceRayTracingPositionFetchFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingPositionFetchFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineBinaryFeaturesKHR) {
	StructureClassHeader(PhysicalDevicePipelineBinaryFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineBinaryFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineBinaryPropertiesKHR) {
	StructureClassHeader(PhysicalDevicePipelineBinaryPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineBinaryPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DevicePipelineBinaryInternalCacheControlKHR) {
	StructureClassHeader(DevicePipelineBinaryInternalCacheControlKHR);
	DefineSetter_Copy(DisableInternalCache, VkBool32, disableInternalCache);
};
VK_ENCAPSULATION_STRUCTURE_END(DevicePipelineBinaryInternalCacheControlKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineBinaryKeyKHR) {
	StructureClassHeader(PipelineBinaryKeyKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineBinaryKeyKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PipelineBinaryDataKHR) {
	StructureClassHeader_NoSType(PipelineBinaryDataKHR);
	DefineSetter_Copy(DataSize, size_t, dataSize);
	// VkPipelineBinaryDataKHR::pData points to a non-const buffer, though currently no Vulkan function returns data to it.
	DefineSetter_ArrayRef(Data, void, data, dataSize);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineBinaryDataKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PipelineBinaryKeysAndDataKHR) {
	StructureClassHeader_NoSType(PipelineBinaryKeysAndDataKHR);
	DefineSetter_Copy(BinaryCount, uint32_t, binaryCount);
	DefineSetter_ArrayRef(PipelineBinaryKeys, const VkPipelineBinaryKeyKHR, pipelineBinaryKeys, binaryCount);
	DefineSetter_ArrayRefIgnoreC(PipelineBinaryData, const VkPipelineBinaryDataKHR, pipelineBinaryData);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineBinaryKeysAndDataKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCreateInfoKHR) {
	StructureClassHeader(PipelineCreateInfoKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineBinaryCreateInfoKHR) {
	StructureClassHeader(PipelineBinaryCreateInfoKHR);
	DefineSetter_Ref(KeysAndDataInfo, const VkPipelineBinaryKeysAndDataKHR, keysAndDataInfo);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
	DefineSetter_Ref(PipelineCreateInfo, const VkPipelineCreateInfoKHR, pipelineCreateInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineBinaryCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineBinaryInfoKHR) {
	StructureClassHeader(PipelineBinaryInfoKHR);
	DefineSetter_Copy(BinaryCount, uint32_t, binaryCount);
	DefineSetter_ArrayRef(PipelineBinaries, const VkPipelineBinaryKHR, pipelineBinaries, binaryCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineBinaryInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ReleaseCapturedPipelineDataInfoKHR) {
	StructureClassHeader(ReleaseCapturedPipelineDataInfoKHR);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
};
VK_ENCAPSULATION_STRUCTURE_END(ReleaseCapturedPipelineDataInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineBinaryDataInfoKHR) {
	StructureClassHeader(PipelineBinaryDataInfoKHR);
	DefineSetter_Copy(PipelineBinary, VkPipelineBinaryKHR, pipelineBinary);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineBinaryDataInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineBinaryHandlesInfoKHR) {
	StructureClassHeader(PipelineBinaryHandlesInfoKHR);
	_& PipelineBinaries(HandleArrayRef<VkPipelineBinaryKHR> pipelineBinaries) & { pipelineBinaryCount = pipelineBinaries.size(); pPipelineBinaries = pipelineBinaries; return *this; }
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineBinaryHandlesInfoKHR)

inline VkResult CreatePipelineBinariesKHR(const VkPipelineBinaryCreateInfoKHR& createInfo, VkPipelineBinaryHandlesInfoKHR& binaries) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreatePipelineBinariesKHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &binaries);
}
DefineRaiiFunction_ResultL(VkResult, CreatePipelineBinariesKHR, PipelineBinaryCreateInfoKHR, VkPipelineBinaryHandlesInfoKHR&, binaries);
inline VkResult CreatePipelineBinariesKHR(const VkPipelineBinaryCreateInfoKHR& createInfo, IsDynamicArray<VkPipelineBinaryKHR> auto& binaries) {
	PipelineBinaryHandlesInfoKHR binaryHandlesInfo;
	if (createInfo.pKeysAndDataInfo)
		binaryHandlesInfo.pipelineBinaryCount = createInfo.pKeysAndDataInfo->binaryCount;
	else
		if (VkResult result = CreatePipelineBinariesKHR(createInfo, binaryHandlesInfo);
			result != VK_SUCCESS)
			return result;
	binaries.resize(binaryHandlesInfo.pipelineBinaryCount);
	binaryHandlesInfo.pPipelineBinaries = reinterpret_cast<VkPipelineBinaryKHR*>(std::ranges::data(binaries));
	return CreatePipelineBinariesKHR(createInfo, binaryHandlesInfo);
}
DefineRaiiFunction_ResultL(VkResult, CreatePipelineBinariesKHR, PipelineBinaryCreateInfoKHR, IsDynamicArray<VkPipelineBinaryKHR> auto&, binaries);

inline void DestroyPipelineBinaryKHR(HandleRef<VkPipelineBinaryKHR> pipelineBinary, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyPipelineBinaryKHR(DeviceContext::Device(), pipelineBinary, &allocator);
	pipelineBinary = VK_NULL_HANDLE;
}

inline VkResult GetPipelineKeyKHR(const VkPipelineCreateInfoKHR& pipelineCreateInfo, VkPipelineBinaryKeyKHR& pipelineKey) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineKeyKHR(DeviceContext::Device(), &pipelineCreateInfo, &pipelineKey);
}
DefineRaiiFunction_ResultL(VkResult, GetPipelineKeyKHR, PipelineCreateInfoKHR, VkPipelineBinaryKeyKHR&, pipelineKey);

inline VkResult GetPipelineBinaryDataKHR(const VkPipelineBinaryDataInfoKHR& info, VkPipelineBinaryKeyKHR& pipelineBinaryKey, size_t& pipelineBinaryDataSize, ArrayRef<void> pipelineBinaryData = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineBinaryDataKHR(DeviceContext::Device(), &info, &pipelineBinaryKey, &pipelineBinaryDataSize, pipelineBinaryData);
}
inline VkResult GetPipelineBinaryDataKHR(const VkPipelineBinaryDataInfoKHR& info, VkPipelineBinaryKeyKHR& pipelineBinaryKey, size_t& pipelineBinaryDataSize, IsNotRangeOrPointer auto& pipelineBinaryData) {
	return GetPipelineBinaryDataKHR(info, pipelineBinaryKey, pipelineBinaryDataSize, { 0, &pipelineBinaryData });
}
inline VkResult GetPipelineBinaryDataKHR(const VkPipelineBinaryDataInfoKHR& info, VkPipelineBinaryKeyKHR& pipelineBinaryKey, IsDynamicByteArray auto& pipelineBinaryData) {
	size_t size = 0;
	VkResult result = GetPipelineBinaryDataKHR(info, pipelineBinaryKey, size);
	if (result == VK_SUCCESS)
		pipelineBinaryData.resize(size),
		result = GetPipelineBinaryDataKHR(info, pipelineBinaryKey, size, pipelineBinaryData);
	return result;
}

inline VkResult ReleaseCapturedPipelineDataKHR(const VkReleaseCapturedPipelineDataInfoKHR& info, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkReleaseCapturedPipelineDataKHR(DeviceContext::Device(), &info, &allocator);
}
DefineRaiiFunction_ResultL(VkResult, ReleaseCapturedPipelineDataKHR, ReleaseCapturedPipelineDataInfoKHR, OptionalRef<const VkAllocationCallbacks>, allocator, = {});

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfacePresentModeKHR) {
	StructureClassHeader(SurfacePresentModeKHR);
	DefineSetter_Copy(PresentMode, VkPresentModeKHR, presentMode);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfacePresentModeKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfacePresentScalingCapabilitiesKHR) {
	StructureClassHeader(SurfacePresentScalingCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfacePresentScalingCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfacePresentModeCompatibilityKHR) {
	StructureClassHeader(SurfacePresentModeCompatibilityKHR);
	DefineSetter_ArrayRefIgnoreC(PresentModes, VkPresentModeKHR, presentModes);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfacePresentModeCompatibilityKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSwapchainMaintenance1FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceSwapchainMaintenance1FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSwapchainMaintenance1FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainPresentFenceInfoKHR) {
	StructureClassHeader(SwapchainPresentFenceInfoKHR);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(Fences, const VkFence, fences, swapchainCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainPresentFenceInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainPresentModesCreateInfoKHR) {
	StructureClassHeader(SwapchainPresentModesCreateInfoKHR);
	DefineSetter_Copy(PresentModeCount, uint32_t, presentModeCount);
	DefineSetter_ArrayRef(PresentModes, const VkPresentModeKHR, presentModes, presentModeCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainPresentModesCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainPresentModeInfoKHR) {
	StructureClassHeader(SwapchainPresentModeInfoKHR);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(PresentModes, const VkPresentModeKHR, presentModes, swapchainCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainPresentModeInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainPresentScalingCreateInfoKHR) {
	StructureClassHeader(SwapchainPresentScalingCreateInfoKHR);
	DefineSetter_Copy(ScalingBehavior, VkPresentScalingFlagsKHR, scalingBehavior);
	DefineSetter_Copy(PresentGravityX, VkPresentGravityFlagsKHR, presentGravityX);
	DefineSetter_Copy(PresentGravityY, VkPresentGravityFlagsKHR, presentGravityY);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainPresentScalingCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ReleaseSwapchainImagesInfoKHR) {
	StructureClassHeader(ReleaseSwapchainImagesInfoKHR);
	DefineSetter_Copy(Swapchain, VkSwapchainKHR, swapchain);
	DefineSetter_Copy(ImageIndexCount, uint32_t, imageIndexCount);
	DefineSetter_ArrayRef(ImageIndices, const uint32_t, imageIndices, imageIndexCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ReleaseSwapchainImagesInfoKHR)

inline VkResult ReleaseSwapchainImagesKHR(const VkReleaseSwapchainImagesInfoKHR& releaseInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkReleaseSwapchainImagesKHR(DeviceContext::Device(), &releaseInfo);
}
DefineRaiiFunction_Result(VkResult, ReleaseSwapchainImagesKHR, ReleaseSwapchainImagesInfoKHR);

VK_ENCAPSULATION_STRUCTURE_BEGIN(CooperativeMatrixPropertiesKHR) {
	StructureClassHeader(CooperativeMatrixPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(CooperativeMatrixPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeMatrixFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceCooperativeMatrixFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeMatrixFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeMatrixPropertiesKHR) {
	StructureClassHeader(PhysicalDeviceCooperativeMatrixPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeMatrixPropertiesKHR)

inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkCooperativeMatrixPropertiesKHR> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkCooperativeMatrixPropertiesKHR> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceCooperativeMatrixPropertiesKHR(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceCooperativeMatrixPropertiesKHR(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesKHR(uint32_t& propertyCount, ArrayRef<VkCooperativeMatrixPropertiesKHR> properties = {}) {
	return GetPhysicalDeviceCooperativeMatrixPropertiesKHR(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesKHR(IsDynamicArray<VkCooperativeMatrixPropertiesKHR> auto& properties) {
	return GetPhysicalDeviceCooperativeMatrixPropertiesKHR(DeviceContext::PhysicalDevice(), properties);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceComputeShaderDerivativesFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceComputeShaderDerivativesFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceComputeShaderDerivativesFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceComputeShaderDerivativesPropertiesKHR) {
	StructureClassHeader(PhysicalDeviceComputeShaderDerivativesPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceComputeShaderDerivativesPropertiesKHR)

//#include "vk_video/vulkan_video_codec_av1std.h"
//#include "vk_video/vulkan_video_codec_av1std_decode.h"

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeAV1ProfileInfoKHR) {
	StructureClassHeader(VideoDecodeAV1ProfileInfoKHR);
	DefineSetter_Copy(StdProfile, StdVideoAV1Profile, stdProfile);
	DefineSetter_Copy(FilmGrainSupport, VkBool32, filmGrainSupport);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeAV1ProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeAV1CapabilitiesKHR) {
	StructureClassHeader(VideoDecodeAV1CapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeAV1CapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeAV1SessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoDecodeAV1SessionParametersCreateInfoKHR);
	DefineSetter_Ref(StdSequenceHeader, const StdVideoAV1SequenceHeader, stdSequenceHeader);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeAV1SessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeAV1PictureInfoKHR) {
	StructureClassHeader(VideoDecodeAV1PictureInfoKHR);
	DefineSetter_Ref(StdPictureInfo, const StdVideoDecodeAV1PictureInfo, stdPictureInfo);
	// int32_t referenceNameSlotIndices[7];
	DefineSetter_ArrayCopy(ReferenceNameSlotIndices, int32_t, referenceNameSlotIndices);
	DefineSetter_Copy(FrameHeaderOffset, uint32_t, frameHeaderOffset);
	DefineSetter_Copy(TileCount, uint32_t, tileCount);
	DefineSetter_ArrayRef(TileOffsets, const uint32_t, tileOffsets, tileCount);
	DefineSetter_ArrayRefIgnoreC(TileSizes, const uint32_t, tileSizes);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeAV1PictureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeAV1DpbSlotInfoKHR) {
	StructureClassHeader(VideoDecodeAV1DpbSlotInfoKHR);
	DefineSetter_Ref(StdReferenceInfo, const StdVideoDecodeAV1ReferenceInfo, stdReferenceInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeAV1DpbSlotInfoKHR)

//#include "vk_video/vulkan_video_codec_av1std_encode.h"

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoEncodeAV1FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceVideoEncodeAV1FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoEncodeAV1FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1CapabilitiesKHR) {
	StructureClassHeader(VideoEncodeAV1CapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1CapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VideoEncodeAV1QIndexKHR) {
	StructureClassHeader_NoSType(VideoEncodeAV1QIndexKHR);
	DefineSetter_Copy(IntraQIndex, uint32_t, intraQIndex);
	DefineSetter_Copy(PredictiveQIndex, uint32_t, predictiveQIndex);
	DefineSetter_Copy(BipredictiveQIndex, uint32_t, bipredictiveQIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1QIndexKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1QualityLevelPropertiesKHR) {
	StructureClassHeader(VideoEncodeAV1QualityLevelPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1QualityLevelPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1SessionCreateInfoKHR) {
	StructureClassHeader(VideoEncodeAV1SessionCreateInfoKHR);
	DefineSetter_Copy(UseMaxLevel, VkBool32, useMaxLevel);
	DefineSetter_CopyOptional(MaxLevel, StdVideoAV1Level, maxLevel, useMaxLevel, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1SessionCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1SessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoEncodeAV1SessionParametersCreateInfoKHR);
	DefineSetter_Ref(StdSequenceHeader, const StdVideoAV1SequenceHeader, stdSequenceHeader);
	DefineSetter_Ref(StdDecoderModelInfo, const StdVideoEncodeAV1DecoderModelInfo, stdDecoderModelInfo);
	DefineSetter_Copy(StdOperatingPointCount, uint32_t, stdOperatingPointCount);
	DefineSetter_ArrayRef(StdOperatingPoints, const StdVideoEncodeAV1OperatingPointInfo, stdOperatingPoints, stdOperatingPointCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1SessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1PictureInfoKHR) {
	StructureClassHeader(VideoEncodeAV1PictureInfoKHR);
	DefineSetter_Copy(PredictionMode, VkVideoEncodeAV1PredictionModeKHR, predictionMode);
	DefineSetter_Copy(RateControlGroup, VkVideoEncodeAV1RateControlGroupKHR, rateControlGroup);
	DefineSetter_Copy(ConstantQIndex, uint32_t, constantQIndex);
	DefineSetter_Ref(StdPictureInfo, const StdVideoDecodeAV1PictureInfo, stdPictureInfo);
	// int32_t referenceNameSlotIndices[7];
	DefineSetter_ArrayCopy(ReferenceNameSlotIndices, int32_t, referenceNameSlotIndices);
	DefineSetter_Copy(PrimaryReferenceCdfOnly, VkBool32, primaryReferenceCdfOnly);
	DefineSetter_Copy(GenerateObuExtensionHeader, VkBool32, generateObuExtensionHeader);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1PictureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1DpbSlotInfoKHR) {
	StructureClassHeader(VideoEncodeAV1DpbSlotInfoKHR);
	DefineSetter_Ref(StdReferenceInfo, const StdVideoEncodeAV1ReferenceInfo, stdReferenceInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1DpbSlotInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1ProfileInfoKHR) {
	StructureClassHeader(VideoEncodeAV1ProfileInfoKHR);
	DefineSetter_Copy(StdProfile, StdVideoAV1Profile, stdProfile);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1ProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(VideoEncodeAV1FrameSizeKHR) {
	StructureClassHeader_NoSType(VideoEncodeAV1FrameSizeKHR);
	DefineSetter_Copy(IntraFrameSize, uint32_t, intraFrameSize);
	DefineSetter_Copy(PredictiveFrameSize, uint32_t, predictiveFrameSize);
	DefineSetter_Copy(BipredictiveFrameSize, uint32_t, bipredictiveFrameSize);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1FrameSizeKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1GopRemainingFrameInfoKHR) {
	StructureClassHeader(VideoEncodeAV1GopRemainingFrameInfoKHR);
	DefineSetter_Copy(UseGopRemainingFrames, VkBool32, useGopRemainingFrames);
	DefineSetter_CopyOptional(GopRemainingIntra, uint32_t, gopRemainingIntra, useGopRemainingFrames, true);
	DefineSetter_CopyOptional(GopRemainingPredictive, uint32_t, gopRemainingPredictive, useGopRemainingFrames, true);
	DefineSetter_CopyOptional(GopRemainingBipredictive, uint32_t, gopRemainingBipredictive, useGopRemainingFrames, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1GopRemainingFrameInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1RateControlInfoKHR) {
	StructureClassHeader(VideoEncodeAV1RateControlInfoKHR);
	DefineSetter_Copy(Flags, VkVideoEncodeAV1RateControlFlagsKHR, flags);
	DefineSetter_Copy(GopFrameCount, uint32_t, gopFrameCount);
	DefineSetter_Copy(KeyFramePeriod, uint32_t, keyFramePeriod);
	DefineSetter_Copy(ConsecutiveBipredictiveFrameCount, uint32_t, consecutiveBipredictiveFrameCount);
	DefineSetter_Copy(TemporalLayerCount, uint32_t, temporalLayerCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1RateControlInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1RateControlLayerInfoKHR) {
	StructureClassHeader(VideoEncodeAV1RateControlLayerInfoKHR);
	DefineSetter_Copy(UseMinQIndex, VkBool32, useMinQIndex);
	DefineSetter_CopyOptional(MinQIndex, VkVideoEncodeAV1QIndexKHR, minQIndex, useMinQIndex, true);
	DefineSetter_Copy(UseMaxQIndex, VkBool32, useMaxQIndex);
	DefineSetter_CopyOptional(MaxQIndex, VkVideoEncodeAV1QIndexKHR, maxQIndex, useMaxQIndex, true);
	DefineSetter_Copy(UseMaxFrameSize, VkBool32, useMaxFrameSize);
	DefineSetter_CopyOptional(MaxFrameSize, VkVideoEncodeAV1FrameSizeKHR, maxFrameSize, useMaxFrameSize, true);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1RateControlLayerInfoKHR)

//#include "vk_video/vulkan_video_codec_vp9std.h"
//#include "vk_video/vulkan_video_codec_vp9std_decode.h"

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoDecodeVP9FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceVideoDecodeVP9FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoDecodeVP9FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeVP9ProfileInfoKHR) {
	StructureClassHeader(VideoDecodeVP9ProfileInfoKHR);
	DefineSetter_Copy(StdProfile, StdVideoVP9Profile, stdProfile);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeVP9ProfileInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeVP9CapabilitiesKHR) {
	StructureClassHeader(VideoDecodeVP9CapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeVP9CapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeVP9PictureInfoKHR) {
	StructureClassHeader(VideoDecodeVP9PictureInfoKHR);
	DefineSetter_Ref(StdPictureInfo, const StdVideoDecodeVP9PictureInfo, stdPictureInfo);
	// int32_t referenceNameSlotIndices[3]
	DefineSetter_ArrayCopy(ReferenceNameSlotIndices, int32_t, referenceNameSlotIndices);
	DefineSetter_Copy(UncompressedHeaderOffset, uint32_t, uncompressedHeaderOffset);
	DefineSetter_Copy(CompressedHeaderOffset, uint32_t, compressedHeaderOffset);
	DefineSetter_Copy(TilesOffset, uint32_t, tilesOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeVP9PictureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoMaintenance1FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceVideoMaintenance1FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoMaintenance1FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoInlineQueryInfoKHR) {
	StructureClassHeader(VideoInlineQueryInfoKHR);
	DefineSetter_Copy(QueryPool, VkQueryPool, queryPool);
	DefineSetter_Copy(FirstQuery, uint32_t, firstQuery);
	DefineSetter_Copy(QueryCount, uint32_t, queryCount);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoInlineQueryInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceUnifiedImageLayoutsFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceUnifiedImageLayoutsFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceUnifiedImageLayoutsFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AttachmentFeedbackLoopInfoEXT) {
	StructureClassHeader(AttachmentFeedbackLoopInfoEXT);
	DefineSetter_Copy(FeedbackLoopEnable, VkBool32, feedbackLoopEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentFeedbackLoopInfoEXT)

inline void CmdSetLineStippleKHR(uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLineStippleKHR(ThreadContext::CommandBuffer(), lineStippleFactor, lineStipplePattern);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(CalibratedTimestampInfoKHR) {
	StructureClassHeader(CalibratedTimestampInfoKHR);
	DefineSetter_Copy(TimeDomain, VkTimeDomainKHR, timeDomain);
};
VK_ENCAPSULATION_STRUCTURE_END(CalibratedTimestampInfoKHR)

inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t& timeDomainCount, ArrayRef<VkTimeDomainKHR> timeDomains = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, &timeDomainCount, timeDomains);
}
inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, IsDynamicArray<VkTimeDomainKHR> auto& timeDomains) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, count);
	if (result == VK_SUCCESS)
		timeDomains.resize(count),
		result = GetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, count, timeDomains);
	return result;
}
inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsKHR(uint32_t& timeDomainCount, ArrayRef<VkTimeDomainKHR> timeDomains = {}) {
	return GetPhysicalDeviceCalibrateableTimeDomainsKHR(DeviceContext::PhysicalDevice(), timeDomainCount, timeDomains);
}
inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsKHR(IsDynamicArray<VkTimeDomainKHR> auto& timeDomains) {
	return GetPhysicalDeviceCalibrateableTimeDomainsKHR(DeviceContext::PhysicalDevice(), timeDomains);
}

inline VkResult GetCalibratedTimestampsKHR(ArrayRef<const VkCalibratedTimestampInfoKHR> timestampInfos, ArrayRef<uint64_t> timestamps, uint64_t& maxDeviation) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetCalibratedTimestampsKHR(DeviceContext::Device(), timestampInfos.size(), timestampInfos, timestamps, &maxDeviation);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(SetDescriptorBufferOffsetsInfoEXT) {
	StructureClassHeader(SetDescriptorBufferOffsetsInfoEXT);
	DefineSetter_Copy(StageFlags, VkShaderStageFlags, stageFlags);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(FirstSet, uint32_t, firstSet);
	DefineSetter_Copy(SetCount, uint32_t, setCount);
	DefineSetter_ArrayRef(BufferIndices, const uint32_t, bufferIndices, setCount);
	DefineSetter_ArrayRefIgnoreC(Offsets, const uint32_t, offsets);
};
VK_ENCAPSULATION_STRUCTURE_END(SetDescriptorBufferOffsetsInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindDescriptorBufferEmbeddedSamplersInfoEXT) {
	StructureClassHeader(BindDescriptorBufferEmbeddedSamplersInfoEXT);
	DefineSetter_Copy(StageFlags, VkShaderStageFlags, stageFlags);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(Set, uint32_t, set);
};
VK_ENCAPSULATION_STRUCTURE_END(BindDescriptorBufferEmbeddedSamplersInfoEXT)

inline void CmdBindDescriptorSets2KHR(const VkBindDescriptorSetsInfo& bindDescriptorSetsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindDescriptorSets2KHR(ThreadContext::CommandBuffer(), &bindDescriptorSetsInfo);
}
DefineRaiiFunction(CmdBindDescriptorSets2KHR, BindDescriptorSetsInfo);

inline void CmdPushConstants2KHR(const VkPushConstantsInfo& pushConstantsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushConstants2KHR(ThreadContext::CommandBuffer(), &pushConstantsInfo);
}
DefineRaiiFunction(CmdPushConstants2KHR, PushConstantsInfo);

inline void CmdPushDescriptorSet2KHR(const VkPushDescriptorSetInfo& pushDescriptorSetInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSet2KHR(ThreadContext::CommandBuffer(), &pushDescriptorSetInfo);
}
DefineRaiiFunction(CmdPushDescriptorSet2KHR, PushDescriptorSetInfo);

inline void CmdPushDescriptorSetWithTemplate2KHR(const VkPushDescriptorSetWithTemplateInfo& pushDescriptorSetWithTemplateInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPushDescriptorSetWithTemplate2KHR(ThreadContext::CommandBuffer(), &pushDescriptorSetWithTemplateInfo);
}
DefineRaiiFunction(CmdPushDescriptorSetWithTemplate2KHR, PushDescriptorSetWithTemplateInfo);

inline void CmdSetDescriptorBufferOffsets2EXT(const VkSetDescriptorBufferOffsetsInfoEXT& setDescriptorBufferOffsetsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDescriptorBufferOffsets2EXT(ThreadContext::CommandBuffer(), &setDescriptorBufferOffsetsInfo);
}
DefineRaiiFunction(CmdSetDescriptorBufferOffsets2EXT, SetDescriptorBufferOffsetsInfoEXT);

inline void CmdBindDescriptorBufferEmbeddedSamplers2EXT(const VkBindDescriptorBufferEmbeddedSamplersInfoEXT& bindDescriptorBufferEmbeddedSamplersInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(ThreadContext::CommandBuffer(), &bindDescriptorBufferEmbeddedSamplersInfo);
}
DefineRaiiFunction(CmdBindDescriptorBufferEmbeddedSamplers2EXT, BindDescriptorBufferEmbeddedSamplersInfoEXT);

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(StridedDeviceAddressRangeKHR) {
	StructureClassHeader_NoSType(StridedDeviceAddressRangeKHR);
	DefineSetter_Copy(Address, VkDeviceAddress, address);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(Stride, VkDeviceSize, stride);
};
VK_ENCAPSULATION_STRUCTURE_END(StridedDeviceAddressRangeKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(CopyMemoryIndirectCommandKHR) {
	StructureClassHeader_NoSType(CopyMemoryIndirectCommandKHR);
	DefineSetter_Copy(SrcAddress, VkDeviceAddress, srcAddress);
	DefineSetter_Copy(DstAddress, VkDeviceAddress, dstAddress);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMemoryIndirectCommandKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyMemoryIndirectInfoKHR) {
	StructureClassHeader(CopyMemoryIndirectInfoKHR);
	DefineSetter_Copy(SrcCopyFlags, VkAddressCopyFlagsKHR, srcCopyFlags);
	DefineSetter_Copy(DstCopyFlags, VkAddressCopyFlagsKHR, dstCopyFlags);
	DefineSetter_Copy(CopyCount, uint32_t, copyCount);
	DefineSetter_Copy(CopyAddressRange, VkStridedDeviceAddressRangeKHR, copyAddressRange);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMemoryIndirectInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(CopyMemoryToImageIndirectCommandKHR) {
	StructureClassHeader_NoSType(CopyMemoryToImageIndirectCommandKHR);
	DefineSetter_Copy(SrcAddress, VkDeviceAddress, srcAddress);
	DefineSetter_Copy(BufferRowLength, uint32_t, bufferRowLength);
	DefineSetter_Copy(BufferImageHeight, uint32_t, bufferImageHeight);
	DefineSetter_Copy(ImageSubresource, VkImageSubresourceLayers, imageSubresource);
	DefineSetter_Copy(ImageOffset, VkOffset3D, imageOffset);
	DefineSetter_Copy(ImageExtent, VkExtent3D, imageExtent);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMemoryToImageIndirectCommandKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyMemoryToImageIndirectInfoKHR) {
	StructureClassHeader(CopyMemoryToImageIndirectInfoKHR);
	DefineSetter_Copy(SrcCopyFlags, VkAddressCopyFlagsKHR, srcCopyFlags);
	DefineSetter_Copy(CopyAddressRange, VkStridedDeviceAddressRangeKHR, copyAddressRange);
	DefineSetter_Copy(DstImage, VkImage, dstImage);
	DefineSetter_Copy(DstImageLayout, VkImageLayout, dstImageLayout);
	DefineSetter_Copy(CopyCount, uint32_t, copyCount);
	DefineSetter_ArrayRef(ImageSubresources, const VkImageSubresourceLayers, imageSubresources, copyCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMemoryToImageIndirectInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCopyMemoryIndirectFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceCopyMemoryIndirectFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCopyMemoryIndirectFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCopyMemoryIndirectPropertiesKHR) {
	StructureClassHeader(PhysicalDeviceCopyMemoryIndirectPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCopyMemoryIndirectPropertiesKHR)

inline void CmdCopyMemoryIndirectKHR(const VkCopyMemoryIndirectInfoKHR& copyMemoryIndirectInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMemoryIndirectKHR(ThreadContext::CommandBuffer(), &copyMemoryIndirectInfo);
}
DefineRaiiFunction(CmdCopyMemoryIndirectKHR, CopyMemoryIndirectInfoKHR);

inline void CmdCopyMemoryToImageIndirectKHR(const VkCopyMemoryToImageIndirectInfoKHR& copyMemoryToImageIndirectInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMemoryToImageIndirectKHR(ThreadContext::CommandBuffer(), &copyMemoryToImageIndirectInfo);
}
DefineRaiiFunction(CmdCopyMemoryToImageIndirectKHR, CopyMemoryToImageIndirectInfoKHR);

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeIntraRefreshCapabilitiesKHR) {
	StructureClassHeader(VideoEncodeIntraRefreshCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeIntraRefreshCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeSessionIntraRefreshCreateInfoKHR) {
	StructureClassHeader(VideoEncodeSessionIntraRefreshCreateInfoKHR);
	DefineSetter_Copy(IntraRefreshMode, VkVideoEncodeIntraRefreshModeFlagBitsKHR, intraRefreshMode);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeSessionIntraRefreshCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeIntraRefreshInfoKHR) {
	StructureClassHeader(VideoEncodeIntraRefreshInfoKHR);
	DefineSetter_Copy(IntraRefreshCycleDuration, uint32_t, intraRefreshCycleDuration);
	DefineSetter_Copy(IntraRefreshIndex, uint32_t, intraRefreshIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeIntraRefreshInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoReferenceIntraRefreshInfoKHR) {
	StructureClassHeader(VideoReferenceIntraRefreshInfoKHR);
	DefineSetter_Copy(DirtyIntraRefreshRegions, uint32_t, dirtyIntraRefreshRegions);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoReferenceIntraRefreshInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeQuantizationMapCapabilitiesKHR) {
	StructureClassHeader(VideoEncodeQuantizationMapCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeQuantizationMapCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoFormatQuantizationMapPropertiesKHR) {
	StructureClassHeader(VideoFormatQuantizationMapPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoFormatQuantizationMapPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeQuantizationMapInfoKHR) {
	StructureClassHeader(VideoEncodeQuantizationMapInfoKHR);
	DefineSetter_Copy(QuantizationMap, VkImageView, quantizationMap);
	DefineSetter_Copy(QuantizationMapExtent, VkExtent2D, quantizationMapExtent);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeQuantizationMapInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeQuantizationMapSessionParametersCreateInfoKHR) {
	StructureClassHeader(VideoEncodeQuantizationMapSessionParametersCreateInfoKHR);
	DefineSetter_Copy(QuantizationMapTexelSize, VkExtent2D, quantizationMapTexelSize);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeQuantizationMapSessionParametersCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH264QuantizationMapCapabilitiesKHR) {
	StructureClassHeader(VideoEncodeH264QuantizationMapCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH264QuantizationMapCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeH265QuantizationMapCapabilitiesKHR) {
	StructureClassHeader(VideoEncodeH265QuantizationMapCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeH265QuantizationMapCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoFormatH265QuantizationMapPropertiesKHR) {
	StructureClassHeader(VideoFormatH265QuantizationMapPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoFormatH265QuantizationMapPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeAV1QuantizationMapCapabilitiesKHR) {
	StructureClassHeader(VideoEncodeAV1QuantizationMapCapabilitiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeAV1QuantizationMapCapabilitiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoFormatAV1QuantizationMapPropertiesKHR) {
	StructureClassHeader(VideoFormatAV1QuantizationMapPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoFormatAV1QuantizationMapPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance7FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceMaintenance7FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance7FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance7PropertiesKHR) {
	StructureClassHeader(PhysicalDeviceMaintenance7PropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance7PropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLayeredApiPropertiesKHR) {
	StructureClassHeader(PhysicalDeviceLayeredApiPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLayeredApiPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLayeredApiPropertiesListKHR) {
	StructureClassHeader(PhysicalDeviceLayeredApiPropertiesListKHR);
	DefineSetter_Copy(LayeredApiCount, uint32_t, layeredApiCount);
	DefineSetter_ArrayRef(LayeredApis, VkPhysicalDeviceLayeredApiPropertiesKHR, layeredApis, layeredApiCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLayeredApiPropertiesListKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLayeredApiVulkanPropertiesKHR) {
	StructureClassHeader(PhysicalDeviceLayeredApiVulkanPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLayeredApiVulkanPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryBarrierAccessFlags3KHR) {
	StructureClassHeader(MemoryBarrierAccessFlags3KHR);
	DefineSetter_Copy(SrcAccessMask3, VkAccessFlags3KHR, srcAccessMask3);
	DefineSetter_Copy(DstAccessMask3, VkAccessFlags3KHR, dstAccessMask3);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryBarrierAccessFlags3KHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance8FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceMaintenance8FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance8FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance9FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceMaintenance9FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance9FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMaintenance9PropertiesKHR) {
	StructureClassHeader(PhysicalDeviceMaintenance9PropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMaintenance9PropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyOwnershipTransferPropertiesKHR) {
	StructureClassHeader(QueueFamilyOwnershipTransferPropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyOwnershipTransferPropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoMaintenance2FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceVideoMaintenance2FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoMaintenance2FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH264InlineSessionParametersInfoKHR) {
	StructureClassHeader(VideoDecodeH264InlineSessionParametersInfoKHR);
	DefineSetter_Ref(StdSPS, const StdVideoH264SequenceParameterSet, stdSPS);
	DefineSetter_Ref(StdPPS, const StdVideoH264PictureParameterSet, stdPPS);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH264InlineSessionParametersInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeH265InlineSessionParametersInfoKHR) {
	StructureClassHeader(VideoDecodeH265InlineSessionParametersInfoKHR);
	DefineSetter_Ref(StdVPS, const StdVideoH265VideoParameterSet, stdVPS);
	DefineSetter_Ref(StdSPS, const StdVideoH265SequenceParameterSet, stdSPS);
	DefineSetter_Ref(StdPPS, const StdVideoH265PictureParameterSet, stdPPS);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeH265InlineSessionParametersInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoDecodeAV1InlineSessionParametersInfoKHR) {
	StructureClassHeader(VideoDecodeAV1InlineSessionParametersInfoKHR);
	DefineSetter_Ref(StdSequenceHeader, const StdVideoAV1SequenceHeader, stdSequenceHeader);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoDecodeAV1InlineSessionParametersInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDepthClampZeroOneFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceDepthClampZeroOneFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDepthClampZeroOneFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRobustness2FeaturesKHR) {
	StructureClassHeader(PhysicalDeviceRobustness2FeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRobustness2FeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRobustness2PropertiesKHR) {
	StructureClassHeader(PhysicalDeviceRobustness2PropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRobustness2PropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR) {
	StructureClassHeader(PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugReportCallbackCreateInfoEXT) {
	StructureClassHeader(DebugReportCallbackCreateInfoEXT);
	DefineSetter_Copy(Flags, VkDebugReportFlagsEXT, flags);
	DefineSetter_Copy(FnCallback, PFN_vkDebugReportCallbackEXT, pfnCallback);
	DefineSetter_PointerAndRef(UserData, void, userData);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugReportCallbackCreateInfoEXT)

inline VkResult CreateDebugReportCallbackEXT(const VkDebugReportCallbackCreateInfoEXT& createInfo, HandleRef<VkDebugReportCallbackEXT> callback) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkCreateDebugReportCallbackEXT(InstanceContext::Instance(), &createInfo, ThreadContext::PAllocator(), &callback);
}
DefineRaiiFunction_ResultL(VkResult, CreateDebugReportCallbackEXT, DebugReportCallbackCreateInfoEXT, HandleRef<VkDebugReportCallbackEXT>, callback);

inline void DestroyDebugReportCallbackEXT(HandleRef<VkDebugReportCallbackEXT> callback, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkDestroyDebugReportCallbackEXT(InstanceContext::Instance(), callback, &allocator);
	callback = VK_NULL_HANDLE;
}

inline void DebugReportMessageEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, ArrayRef<const char> layerPrefix, ArrayRef<const char> message) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkDebugReportMessageEXT(InstanceContext::Instance(), flags, objectType, object, location, messageCode, layerPrefix, message);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRasterizationStateRasterizationOrderAMD) {
	StructureClassHeader(PipelineRasterizationStateRasterizationOrderAMD);
	DefineSetter_Copy(RasterizationOrder, VkRasterizationOrderAMD, rasterizationOrder);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRasterizationStateRasterizationOrderAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugMarkerObjectNameInfoEXT) {
	StructureClassHeader(DebugMarkerObjectNameInfoEXT);
	DefineSetter_Copy(ObjectType, VkDebugReportObjectTypeEXT, objectType);
	DefineSetter_Copy(Object, uint64_t, object);
	DefineSetter_ArrayRefIgnoreC(ObjectName, const char, objectName);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugMarkerObjectNameInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugMarkerObjectTagInfoEXT) {
	StructureClassHeader(DebugMarkerObjectTagInfoEXT);
	DefineSetter_Copy(ObjectType, VkDebugReportObjectTypeEXT, objectType);
	DefineSetter_Copy(Object, uint64_t, object);
	DefineSetter_Copy(TagName, uint64_t, tagName);
	DefineSetter_Copy(TagSize, size_t, tagSize);
	DefineSetter_ArrayRef(Tag, const void, tag, tagSize);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugMarkerObjectTagInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugMarkerMarkerInfoEXT) {
	StructureClassHeader(DebugMarkerMarkerInfoEXT);
	DefineSetter_ArrayRefIgnoreC(MarkerName, const char, markerName);
	// float color[4];
	DefineSetter_ArrayCopy(Color, float, color);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugMarkerMarkerInfoEXT)

inline VkResult DebugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT& tagInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkDebugMarkerSetObjectTagEXT(DeviceContext::Device(), &tagInfo);
}
DefineRaiiFunction_Result(VkResult, DebugMarkerSetObjectTagEXT, DebugMarkerObjectTagInfoEXT);

inline VkResult DebugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT& nameInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkDebugMarkerSetObjectNameEXT(DeviceContext::Device(), &nameInfo);
}
DefineRaiiFunction_Result(VkResult, DebugMarkerSetObjectNameEXT, DebugMarkerObjectNameInfoEXT);

inline void CmdDebugMarkerBeginEXT(const VkDebugMarkerMarkerInfoEXT& markerInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDebugMarkerBeginEXT(ThreadContext::CommandBuffer(), &markerInfo);
}
DefineRaiiFunction(CmdDebugMarkerBeginEXT, DebugMarkerMarkerInfoEXT);

inline void CmdDebugMarkerEndEXT() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDebugMarkerEndEXT(ThreadContext::CommandBuffer());
}

inline void CmdDebugMarkerInsertEXT(const VkDebugMarkerMarkerInfoEXT& markerInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDebugMarkerInsertEXT(ThreadContext::CommandBuffer(), &markerInfo);
}
DefineRaiiFunction(CmdDebugMarkerInsertEXT, DebugMarkerMarkerInfoEXT);

VK_ENCAPSULATION_STRUCTURE_BEGIN(DedicatedAllocationImageCreateInfoNV) {
	StructureClassHeader(DedicatedAllocationImageCreateInfoNV);
	DefineSetter_Copy(DedicatedAllocation, VkBool32, dedicatedAllocation);
};
VK_ENCAPSULATION_STRUCTURE_END(DedicatedAllocationImageCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DedicatedAllocationBufferCreateInfoNV) {
	StructureClassHeader(DedicatedAllocationBufferCreateInfoNV);
	DefineSetter_Copy(DedicatedAllocation, VkBool32, dedicatedAllocation);
};
VK_ENCAPSULATION_STRUCTURE_END(DedicatedAllocationBufferCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DedicatedAllocationMemoryAllocateInfoNV) {
	StructureClassHeader(DedicatedAllocationMemoryAllocateInfoNV);
	DefineSetter_Copy(Image, VkImage, image);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
};
VK_ENCAPSULATION_STRUCTURE_END(DedicatedAllocationMemoryAllocateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTransformFeedbackFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceTransformFeedbackFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTransformFeedbackFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTransformFeedbackPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceTransformFeedbackPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTransformFeedbackPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRasterizationStateStreamCreateInfoEXT) {
	StructureClassHeader(PipelineRasterizationStateStreamCreateInfoEXT);
	DefineSetter_Copy(Flags, VkPipelineRasterizationStateStreamCreateFlagsEXT, flags);
	DefineSetter_Copy(RasterizationStream, uint32_t, rasterizationStream);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRasterizationStateStreamCreateInfoEXT)

inline void CmdBindTransformFeedbackBuffersEXT(uint32_t firstBinding, ArrayRef<const VkBuffer> buffers, ArrayRef<const VkDeviceSize> offsets, ArrayRef<const VkDeviceSize> sizes) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindTransformFeedbackBuffersEXT(ThreadContext::CommandBuffer(), firstBinding, buffers.size(), buffers, offsets, sizes);
}

inline void CmdBeginTransformFeedbackEXT(uint32_t firstCounterBuffer, uint32_t counterBufferCount, ArrayRef<const VkBuffer> counterBuffers, ArrayRef<const VkDeviceSize> counterBufferOffsets) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginTransformFeedbackEXT(ThreadContext::CommandBuffer(), firstCounterBuffer, counterBufferCount, counterBuffers, counterBufferOffsets);
}

inline void CmdEndTransformFeedbackEXT(uint32_t firstCounterBuffer, uint32_t counterBufferCount, ArrayRef<const VkBuffer> counterBuffers, ArrayRef<const VkDeviceSize> counterBufferOffsets) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndTransformFeedbackEXT(ThreadContext::CommandBuffer(), firstCounterBuffer, counterBufferCount, counterBuffers, counterBufferOffsets);
}

inline void CmdBeginQueryIndexedEXT(VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginQueryIndexedEXT(ThreadContext::CommandBuffer(), queryPool, query, flags, index);
}

inline void CmdEndQueryIndexedEXT(VkQueryPool queryPool, uint32_t query, uint32_t index) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndQueryIndexedEXT(ThreadContext::CommandBuffer(), queryPool, query, index);
}

inline void CmdDrawIndirectByteCountEXT(uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndirectByteCountEXT(ThreadContext::CommandBuffer(), instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(CuModuleCreateInfoNVX) {
	StructureClassHeader(CuModuleCreateInfoNVX);
	DefineSetter_Copy(DataSize, size_t, dataSize);
	DefineSetter_ArrayRef(Data, const void, data, dataSize);
};
VK_ENCAPSULATION_STRUCTURE_END(CuModuleCreateInfoNVX)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CuModuleTexturingModeCreateInfoNVX) {
	StructureClassHeader(CuModuleTexturingModeCreateInfoNVX);
	DefineSetter_Copy(Use64bitTexturing, VkBool32, use64bitTexturing);
};
VK_ENCAPSULATION_STRUCTURE_END(CuModuleTexturingModeCreateInfoNVX)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CuFunctionCreateInfoNVX) {
	StructureClassHeader(CuFunctionCreateInfoNVX, .pName = "main");
	DefineSetter_Copy(Module, VkCuModuleNVX, module);
	DefineSetter_ArrayRefIgnoreC(Name, const char, name);
};
VK_ENCAPSULATION_STRUCTURE_END(CuFunctionCreateInfoNVX)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CuLaunchInfoNVX) {
	StructureClassHeader(CuLaunchInfoNVX);
	DefineSetter_Copy(Function, VkCuFunctionNVX, function);
	DefineSetter_Copy(GridDimX, uint32_t, gridDimX);
	DefineSetter_Copy(GridDimY, uint32_t, gridDimY);
	DefineSetter_Copy(GridDimZ, uint32_t, gridDimZ);
	DefineSetter_Copy(BlockDimX, uint32_t, blockDimX);
	DefineSetter_Copy(BlockDimY, uint32_t, blockDimY);
	DefineSetter_Copy(BlockDimZ, uint32_t, blockDimZ);
	DefineSetter_Copy(SharedMemBytes, uint32_t, sharedMemBytes);
	DefineSetter_Copy(ParamCount, uint32_t, paramCount);
	DefineSetter_ArrayRef(Params, const void* const, params, paramCount);
	DefineSetter_Copy(ExtraCount, uint32_t, extraCount);
	DefineSetter_ArrayRef(Extras, const void* const, extras, extraCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CuLaunchInfoNVX)

inline VkResult CreateCuModuleNVX(const VkCuModuleCreateInfoNVX& createInfo, HandleRef<VkCuModuleNVX> module) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateCuModuleNVX(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &module);
}
DefineRaiiFunction_ResultL(VkResult, CreateCuModuleNVX, CuModuleCreateInfoNVX, HandleRef<VkCuModuleNVX>, module);

inline VkResult CreateCuFunctionNVX(const VkCuFunctionCreateInfoNVX& createInfo, HandleRef<VkCuFunctionNVX> function) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateCuFunctionNVX(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &function);
}
DefineRaiiFunction_ResultL(VkResult, CreateCuFunctionNVX, CuFunctionCreateInfoNVX, HandleRef<VkCuFunctionNVX>, function);

inline void DestroyCuModuleNVX(HandleRef<VkCuModuleNVX> module, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyCuModuleNVX(DeviceContext::Device(), module, &allocator);
	module = VK_NULL_HANDLE;
}

inline void DestroyCuFunctionNVX(HandleRef<VkCuFunctionNVX> function, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyCuFunctionNVX(DeviceContext::Device(), function, &allocator);
	function = VK_NULL_HANDLE;
}

inline void CmdCuLaunchKernelNVX(const VkCuLaunchInfoNVX& launchInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCuLaunchKernelNVX(ThreadContext::CommandBuffer(), &launchInfo);
}
DefineRaiiFunction(CmdCuLaunchKernelNVX, CuLaunchInfoNVX);

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewHandleInfoNVX) {
	StructureClassHeader(ImageViewHandleInfoNVX);
	DefineSetter_Copy(ImageView, VkImageView, imageView);
	DefineSetter_Copy(DescriptorType, VkDescriptorType, descriptorType);
	DefineSetter_Copy(Sampler, VkSampler, sampler);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewHandleInfoNVX)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewAddressPropertiesNVX) {
	StructureClassHeader(ImageViewAddressPropertiesNVX);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewAddressPropertiesNVX)

inline uint32_t GetImageViewHandleNVX(const VkImageViewHandleInfoNVX& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageViewHandleNVX(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(uint32_t, GetImageViewHandleNVX, ImageViewHandleInfoNVX);

inline uint64_t GetImageViewHandle64NVX(const VkImageViewHandleInfoNVX& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageViewHandle64NVX(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(uint64_t, GetImageViewHandle64NVX, ImageViewHandleInfoNVX);

inline VkResult GetImageViewAddressNVX(VkImageView imageView, VkImageViewAddressPropertiesNVX& properties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageViewAddressNVX(DeviceContext::Device(), imageView, &properties);
}

inline void CmdDrawIndirectCountAMD(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndirectCountAMD(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

inline void CmdDrawIndexedIndirectCountAMD(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawIndexedIndirectCountAMD(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(TextureLODGatherFormatPropertiesAMD) {
	StructureClassHeader(TextureLODGatherFormatPropertiesAMD);
};
VK_ENCAPSULATION_STRUCTURE_END(TextureLODGatherFormatPropertiesAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ShaderResourceUsageAMD) {
	StructureClassHeader_NoSType(ShaderResourceUsageAMD);
	DefineSetter_Copy(NumUsedVgprs, uint32_t, numUsedVgprs);
	DefineSetter_Copy(NumUsedSgprs, uint32_t, numUsedSgprs);
	DefineSetter_Copy(LdsSizePerLocalWorkGroup, uint32_t, ldsSizePerLocalWorkGroup);
	DefineSetter_Copy(LdsUsageSizeInBytes, size_t, ldsUsageSizeInBytes);
	DefineSetter_Copy(ScratchMemUsageInBytes, size_t, scratchMemUsageInBytes);
};
VK_ENCAPSULATION_STRUCTURE_END(ShaderResourceUsageAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ShaderStatisticsInfoAMD) {
	StructureClassHeader_NoSType(ShaderStatisticsInfoAMD);
	DefineSetter_Copy(ShaderStageMask, VkShaderStageFlags, shaderStageMask);
	DefineSetter_Copy(ResourceUsage, VkShaderResourceUsageAMD, resourceUsage);
	DefineSetter_Copy(NumPhysicalVgprs, uint32_t, numPhysicalVgprs);
	DefineSetter_Copy(NumPhysicalSgprs, uint32_t, numPhysicalSgprs);
	DefineSetter_Copy(NumAvailableVgprs, uint32_t, numAvailableVgprs);
	DefineSetter_Copy(NumAvailableSgprs, uint32_t, numAvailableSgprs);
	// uint32_t computeWorkGroupSize[3];
	DefineSetter_ArrayCopy(ComputeWorkGroupSize, uint32_t, computeWorkGroupSize);
};
VK_ENCAPSULATION_STRUCTURE_END(ShaderStatisticsInfoAMD)

inline VkResult GetShaderInfoAMD(VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t& infoSize, ArrayRef<void> info = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetShaderInfoAMD(DeviceContext::Device(), pipeline, shaderStage, infoType, &infoSize, info);
}
inline VkResult GetShaderInfoAMD(VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t& infoSize, IsNotRangeOrPointer auto& info) {
	return GetShaderInfoAMD(DeviceContext::Device(), pipeline, shaderStage, infoType, &infoSize, { 0, &info });
}
inline VkResult GetShaderInfoAMD(VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, IsDynamicByteArray auto& info) {
	size_t size = 0;
	VkResult result = GetShaderInfoAMD(pipeline, shaderStage, infoType, size);
	if (result == VK_SUCCESS)
		info.resize(size),
		result = GetShaderInfoAMD(pipeline, shaderStage, infoType, size, info);
	return result;
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCornerSampledImageFeaturesNV) {
	StructureClassHeader(PhysicalDeviceCornerSampledImageFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCornerSampledImageFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ExternalImageFormatPropertiesNV) {
	StructureClassHeader_NoSType(ExternalImageFormatPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalImageFormatPropertiesNV)

inline VkResult GetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV& externalImageFormatProperties) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, &externalImageFormatProperties);
}
inline VkResult GetPhysicalDeviceExternalImageFormatPropertiesNV(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV& externalImageFormatProperties) {
	return GetPhysicalDeviceExternalImageFormatPropertiesNV(DeviceContext::PhysicalDevice(), format, type, tiling, usage, flags, externalHandleType, externalImageFormatProperties);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalMemoryImageCreateInfoNV) {
	StructureClassHeader(ExternalMemoryImageCreateInfoNV);
	DefineSetter_Copy(HandleTypes, VkExternalMemoryHandleTypeFlagsNV, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalMemoryImageCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExportMemoryAllocateInfoNV) {
	StructureClassHeader(ExportMemoryAllocateInfoNV);
	DefineSetter_Copy(HandleTypes, VkExternalMemoryHandleTypeFlagsNV, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExportMemoryAllocateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ValidationFlagsEXT) {
	StructureClassHeader(ValidationFlagsEXT);
	DefineSetter_Copy(DisabledValidationCheckCount, uint32_t, disabledValidationCheckCount);
	DefineSetter_ArrayRef(DisabledValidationChecks, const VkValidationCheckEXT, disabledValidationChecks, disabledValidationCheckCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ValidationFlagsEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewASTCDecodeModeEXT) {
	StructureClassHeader(ImageViewASTCDecodeModeEXT);
	DefineSetter_Copy(DecodeMode, VkFormat, decodeMode);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewASTCDecodeModeEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceASTCDecodeFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceASTCDecodeFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceASTCDecodeFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ConditionalRenderingBeginInfoEXT) {
	StructureClassHeader(ConditionalRenderingBeginInfoEXT);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Flags, VkConditionalRenderingFlagsEXT, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(ConditionalRenderingBeginInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceConditionalRenderingFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceConditionalRenderingFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceConditionalRenderingFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferInheritanceConditionalRenderingInfoEXT) {
	StructureClassHeader(CommandBufferInheritanceConditionalRenderingInfoEXT);
	DefineSetter_Copy(ConditionalRenderingEnable, VkBool32, conditionalRenderingEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferInheritanceConditionalRenderingInfoEXT)

inline void CmdBeginConditionalRenderingEXT(const VkConditionalRenderingBeginInfoEXT& conditionalRenderingBegin) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginConditionalRenderingEXT(ThreadContext::CommandBuffer(), &conditionalRenderingBegin);
}
DefineRaiiFunction(CmdBeginConditionalRenderingEXT, ConditionalRenderingBeginInfoEXT);

inline void CmdEndConditionalRenderingEXT() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndConditionalRenderingEXT(ThreadContext::CommandBuffer());
}

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ViewportWScalingNV) {
	StructureClassHeader_NoSType(ViewportWScalingNV);
	DefineSetter_Copy(Xcoeff, float, xcoeff);
	DefineSetter_Copy(Ycoeff, float, ycoeff);
};
VK_ENCAPSULATION_STRUCTURE_END(ViewportWScalingNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportWScalingStateCreateInfoNV) {
	StructureClassHeader(PipelineViewportWScalingStateCreateInfoNV);
	DefineSetter_Copy(ViewportWScalingEnable, VkBool32, viewportWScalingEnable);
	DefineSetter_CopyOptional(ViewportCount, uint32_t, viewportCount, viewportWScalingEnable, true);
	// If the viewport W scaling state is dynamic, pViewportWScalings is ignored.
	DefineSetter_ArrayRef(ViewportWScalings, const VkViewportWScalingNV, viewportWScalings, viewportCount, viewportWScalingEnable = bool(viewportWScalings));
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportWScalingStateCreateInfoNV)

inline void CmdSetViewportWScalingNV(uint32_t firstViewport, ArrayRef<const VkViewportWScalingNV> viewportWScalings) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetViewportWScalingNV(ThreadContext::CommandBuffer(), firstViewport, viewportWScalings.size(), viewportWScalings);
}

inline VkResult ReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkReleaseDisplayEXT(physicalDevice, display);
}
inline VkResult ReleaseDisplayEXT(VkDisplayKHR display) {
	return ReleaseDisplayEXT(DeviceContext::PhysicalDevice(), display);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfaceCapabilities2EXT) {
	StructureClassHeader(SurfaceCapabilities2EXT);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceCapabilities2EXT)

inline VkResult GetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT& surfaceCapabilities) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, &surfaceCapabilities);
}
inline VkResult GetPhysicalDeviceSurfaceCapabilities2EXT(VkSurfaceKHR surface, VkSurfaceCapabilities2EXT& surfaceCapabilities) {
	return GetPhysicalDeviceSurfaceCapabilities2EXT(DeviceContext::PhysicalDevice(), surface, surfaceCapabilities);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayPowerInfoEXT) {
	StructureClassHeader(DisplayPowerInfoEXT);
	DefineSetter_Copy(PowerState, VkDisplayPowerStateEXT, powerState);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayPowerInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceEventInfoEXT) {
	StructureClassHeader(DeviceEventInfoEXT);
	DefineSetter_Copy(DeviceEvent, VkDeviceEventTypeEXT, deviceEvent);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceEventInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayEventInfoEXT) {
	StructureClassHeader(DisplayEventInfoEXT);
	DefineSetter_Copy(DisplayEvent, VkDisplayEventTypeEXT, displayEvent);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayEventInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainCounterCreateInfoEXT) {
	StructureClassHeader(SwapchainCounterCreateInfoEXT);
	DefineSetter_Copy(SurfaceCounters, VkSurfaceCounterFlagsEXT, surfaceCounters);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainCounterCreateInfoEXT)

inline VkResult DisplayPowerControlEXT(VkDisplayKHR display, const VkDisplayPowerInfoEXT& displayPowerInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkDisplayPowerControlEXT(DeviceContext::Device(), display, &displayPowerInfo);
}
DefineRaiiFunction_ResultR(VkResult, DisplayPowerControlEXT, VkDisplayKHR, display, DisplayPowerInfoEXT);

inline VkResult RegisterDeviceEventEXT(const VkDeviceEventInfoEXT& deviceEventInfo, HandleRef<VkFence> fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkRegisterDeviceEventEXT(DeviceContext::Device(), &deviceEventInfo, ThreadContext::PAllocator(), &fence);
}
DefineRaiiFunction_ResultL(VkResult, RegisterDeviceEventEXT, DeviceEventInfoEXT, HandleRef<VkFence>, fence);

inline VkResult RegisterDisplayEventEXT(VkDisplayKHR display, const VkDisplayEventInfoEXT& displayEventInfo, HandleRef<VkFence> fence) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkRegisterDisplayEventEXT(DeviceContext::Device(), display, &displayEventInfo, ThreadContext::PAllocator(), &fence);
}

inline VkResult GetSwapchainCounterEXT(VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t& counterValue) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetSwapchainCounterEXT(DeviceContext::Device(), swapchain, counter, &counterValue);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(RefreshCycleDurationGOOGLE) {
	StructureClassHeader_NoSType(RefreshCycleDurationGOOGLE);
	DefineSetter_Copy(RefreshDuration, uint64_t, refreshDuration);
};
VK_ENCAPSULATION_STRUCTURE_END(RefreshCycleDurationGOOGLE)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PastPresentationTimingGOOGLE) {
	StructureClassHeader_NoSType(PastPresentationTimingGOOGLE);
	DefineSetter_Copy(PresentID, uint32_t, presentID);
	DefineSetter_Copy(DesiredPresentTime, uint64_t, desiredPresentTime);
	DefineSetter_Copy(ActualPresentTime, uint64_t, actualPresentTime);
	DefineSetter_Copy(EarliestPresentTime, uint64_t, earliestPresentTime);
	DefineSetter_Copy(PresentMargin, uint64_t, presentMargin);
};
VK_ENCAPSULATION_STRUCTURE_END(PastPresentationTimingGOOGLE)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PresentTimeGOOGLE) {
	StructureClassHeader_NoSType(PresentTimeGOOGLE);
	DefineSetter_Copy(PresentID, uint32_t, presentID);
	DefineSetter_Copy(DesiredPresentTime, uint64_t, desiredPresentTime);
};
VK_ENCAPSULATION_STRUCTURE_END(PresentTimeGOOGLE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PresentTimesInfoGOOGLE) {
	StructureClassHeader(PresentTimesInfoGOOGLE);
	DefineSetter_Copy(SwapchainCount, uint32_t, swapchainCount);
	DefineSetter_ArrayRef(Times, const VkPresentTimeGOOGLE, times, swapchainCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PresentTimesInfoGOOGLE)

inline VkResult GetRefreshCycleDurationGOOGLE(VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE& displayTimingProperties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRefreshCycleDurationGOOGLE(DeviceContext::Device(), swapchain, &displayTimingProperties);
}

inline VkResult GetPastPresentationTimingGOOGLE(VkSwapchainKHR swapchain, uint32_t& presentationTimingCount, ArrayRef<VkPastPresentationTimingGOOGLE> presentationTimings = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPastPresentationTimingGOOGLE(DeviceContext::Device(), swapchain, &presentationTimingCount, presentationTimings);
}
inline VkResult GetPastPresentationTimingGOOGLE(VkSwapchainKHR swapchain, IsDynamicArray<VkPastPresentationTimingGOOGLE> auto& presentationTimings) {
	uint32_t count = 0;
	VkResult result = GetPastPresentationTimingGOOGLE(swapchain, count);
	if (result == VK_SUCCESS)
		presentationTimings.resize(count),
		result = GetPastPresentationTimingGOOGLE(swapchain, count, presentationTimings);
	return result;
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX) {
	StructureClassHeader(PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MultiviewPerViewAttributesInfoNVX) {
	StructureClassHeader(MultiviewPerViewAttributesInfoNVX);
	DefineSetter_Copy(PerViewAttributes, VkBool32, perViewAttributes);
	DefineSetter_CopyOptional(PerViewAttributesPositionXOnly, VkBool32, perViewAttributesPositionXOnly, perViewAttributes, true);
};
VK_ENCAPSULATION_STRUCTURE_END(MultiviewPerViewAttributesInfoNVX)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ViewportSwizzleNV) {
	StructureClassHeader_NoSType(ViewportSwizzleNV);
	DefineSetter_Copy(X, VkViewportCoordinateSwizzleNV, x);
	DefineSetter_Copy(Y, VkViewportCoordinateSwizzleNV, y);
	DefineSetter_Copy(Z, VkViewportCoordinateSwizzleNV, z);
	DefineSetter_Copy(W, VkViewportCoordinateSwizzleNV, w);
};
VK_ENCAPSULATION_STRUCTURE_END(ViewportSwizzleNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportSwizzleStateCreateInfoNV) {
	StructureClassHeader(PipelineViewportSwizzleStateCreateInfoNV);
	DefineSetter_Copy(Flags, VkPipelineViewportSwizzleStateCreateFlagsNV, flags);
	DefineSetter_Copy(ViewportCount, uint32_t, viewportCount);
	DefineSetter_ArrayRef(ViewportSwizzles, const VkViewportSwizzleNV, viewportSwizzles, viewportCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportSwizzleStateCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDiscardRectanglePropertiesEXT) {
	StructureClassHeader(PhysicalDeviceDiscardRectanglePropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDiscardRectanglePropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineDiscardRectangleStateCreateInfoEXT) {
	StructureClassHeader(PipelineDiscardRectangleStateCreateInfoEXT);
	DefineSetter_Copy(Flags, VkPipelineDiscardRectangleStateCreateFlagsEXT, flags);
	DefineSetter_Copy(DiscardRectangleMode, VkDiscardRectangleModeEXT, discardRectangleMode);
	DefineSetter_Copy(DiscardRectangleCount, uint32_t, discardRectangleCount);
	DefineSetter_ArrayRef(DiscardRectangles, const VkRect2D, discardRectangles, discardRectangleCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineDiscardRectangleStateCreateInfoEXT)

inline void CmdSetDiscardRectangleEXT(uint32_t firstDiscardRectangle, ArrayRef<const VkRect2D> discardRectangles) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDiscardRectangleEXT(ThreadContext::CommandBuffer(), firstDiscardRectangle, discardRectangles.size(), discardRectangles);
}

inline void CmdSetDiscardRectangleEnableEXT(VkBool32 discardRectangleEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDiscardRectangleEnableEXT(ThreadContext::CommandBuffer(), discardRectangleEnable);
}

inline void CmdSetDiscardRectangleModeEXT(VkDiscardRectangleModeEXT discardRectangleMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDiscardRectangleModeEXT(ThreadContext::CommandBuffer(), discardRectangleMode);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceConservativeRasterizationPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceConservativeRasterizationPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceConservativeRasterizationPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRasterizationConservativeStateCreateInfoEXT) {
	StructureClassHeader(PipelineRasterizationConservativeStateCreateInfoEXT);
	DefineSetter_Copy(Flags, VkPipelineRasterizationConservativeStateCreateFlagsEXT, flags);
	DefineSetter_Copy(ConservativeRasterizationMode, VkConservativeRasterizationModeEXT, conservativeRasterizationMode);
	DefineSetter_Copy(ExtraPrimitiveOverestimationSize, float, extraPrimitiveOverestimationSize);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRasterizationConservativeStateCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDepthClipEnableFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDepthClipEnableFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDepthClipEnableFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRasterizationDepthClipStateCreateInfoEXT) {
	StructureClassHeader(PipelineRasterizationDepthClipStateCreateInfoEXT);
	DefineSetter_Copy(Flags, VkPipelineRasterizationDepthClipStateCreateFlagsEXT, flags);
	DefineSetter_Copy(DepthClipEnable, VkBool32, depthClipEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRasterizationDepthClipStateCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(XYColorEXT) {
	StructureClassHeader_NoSType(XYColorEXT);
	DefineSetter_Copy(X, float, x);
	DefineSetter_Copy(Y, float, y);
};
VK_ENCAPSULATION_STRUCTURE_END(XYColorEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(HdrMetadataEXT) {
	StructureClassHeader(HdrMetadataEXT);
	DefineSetter_Copy(DisplayPrimaryRed, VkXYColorEXT, displayPrimaryRed);
	DefineSetter_Copy(DisplayPrimaryGreen, VkXYColorEXT, displayPrimaryGreen);
	DefineSetter_Copy(DisplayPrimaryBlue, VkXYColorEXT, displayPrimaryBlue);
	DefineSetter_Copy(WhitePoint, VkXYColorEXT, whitePoint);
	DefineSetter_Copy(MaxLuminance, float, maxLuminance);
	DefineSetter_Copy(MinLuminance, float, minLuminance);
	DefineSetter_Copy(MaxContentLightLevel, float, maxContentLightLevel);
	DefineSetter_Copy(MaxFrameAverageLightLevel, float, maxFrameAverageLightLevel);
};
VK_ENCAPSULATION_STRUCTURE_END(HdrMetadataEXT)

inline void SetHdrMetadataEXT(ArrayRef<const VkSwapchainKHR> swapchains, ArrayRef<const VkHdrMetadataEXT> metadata) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkSetHdrMetadataEXT(DeviceContext::Device(), swapchains.size(), swapchains, metadata);
}
DefineRaiiFunction_R(SetHdrMetadataEXT, VkSwapchainKHR, swapchain, HdrMetadataEXT);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRelaxedLineRasterizationFeaturesIMG) {
	StructureClassHeader(PhysicalDeviceRelaxedLineRasterizationFeaturesIMG);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRelaxedLineRasterizationFeaturesIMG)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugUtilsLabelEXT) {
	StructureClassHeader(DebugUtilsLabelEXT);
	DefineSetter_ArrayRefIgnoreC(LabelName, const char, labelName);
	// float color[4];
	DefineSetter_ArrayCopy(Color, float, color);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugUtilsLabelEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugUtilsObjectNameInfoEXT) {
	StructureClassHeader(DebugUtilsObjectNameInfoEXT);
	DefineSetter_Copy(ObjectType, VkObjectType, objectType);
	DefineSetter_Copy(ObjectHandle, uint64_t, objectHandle);
	DefineSetter_ArrayRefIgnoreC(ObjectName, const char, objectName);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugUtilsObjectNameInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugUtilsMessengerCallbackDataEXT) {
	StructureClassHeader(DebugUtilsMessengerCallbackDataEXT);
	DefineSetter_Copy(Flags, VkDebugUtilsMessengerCallbackDataFlagsEXT, flags);
	DefineSetter_ArrayRefIgnoreC(MessageIdName, const char, messageIdName);
	DefineSetter_Copy(MessageIdNumber, int32_t, messageIdNumber);
	DefineSetter_ArrayRefIgnoreC(Message, const char, message);
	DefineSetter_Copy(QueueLabelCount, uint32_t, queueLabelCount);
	DefineSetter_ArrayRef(QueueLabels, const VkDebugUtilsLabelEXT, queueLabels, queueLabelCount);
	DefineSetter_Copy(CmdBufLabelCount, uint32_t, cmdBufLabelCount);
	DefineSetter_ArrayRef(CmdBufLabels, const VkDebugUtilsLabelEXT, cmdBufLabels, cmdBufLabelCount);
	DefineSetter_Copy(ObjectCount, uint32_t, objectCount);
	DefineSetter_ArrayRef(Objects, const VkDebugUtilsObjectNameInfoEXT, objects, objectCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugUtilsMessengerCallbackDataEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugUtilsMessengerCreateInfoEXT) {
	StructureClassHeader(DebugUtilsMessengerCreateInfoEXT);
	DefineSetter_Copy(Flags, VkDebugUtilsMessengerCreateFlagsEXT, flags);
	DefineSetter_Copy(MessageSeverity, VkDebugUtilsMessageSeverityFlagsEXT, messageSeverity);
	DefineSetter_Copy(MessageType, VkDebugUtilsMessageTypeFlagsEXT, messageType);
	DefineSetter_Copy(FnUserCallback, PFN_vkDebugUtilsMessengerCallbackEXT, pfnUserCallback);
	DefineSetter_PointerAndRef(UserData, void, userData);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugUtilsMessengerCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DebugUtilsObjectTagInfoEXT) {
	StructureClassHeader(DebugUtilsObjectTagInfoEXT);
	DefineSetter_Copy(ObjectType, VkObjectType, objectType);
	DefineSetter_Copy(ObjectHandle, uint64_t, objectHandle);
	DefineSetter_Copy(TagName, uint64_t, tagName);
	DefineSetter_Copy(TagSize, size_t, tagSize);
	DefineSetter_ArrayRef(Tag, const void, tag, tagSize);
};
VK_ENCAPSULATION_STRUCTURE_END(DebugUtilsObjectTagInfoEXT)

inline VkResult SetDebugUtilsObjectNameEXT(const VkDebugUtilsObjectNameInfoEXT& nameInfo) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkSetDebugUtilsObjectNameEXT(DeviceContext::Device(), &nameInfo);
}
DefineRaiiFunction_Result(VkResult, SetDebugUtilsObjectNameEXT, DebugUtilsObjectNameInfoEXT);

inline VkResult SetDebugUtilsObjectTagEXT(const VkDebugUtilsObjectTagInfoEXT& tagInfo) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkSetDebugUtilsObjectTagEXT(DeviceContext::Device(), &tagInfo);
}
DefineRaiiFunction_Result(VkResult, SetDebugUtilsObjectTagEXT, DebugUtilsObjectTagInfoEXT);

inline void QueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT& labelInfo) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkQueueBeginDebugUtilsLabelEXT(queue, &labelInfo);
}
DefineRaiiFunction_R(QueueBeginDebugUtilsLabelEXT, VkQueue, queue, DebugUtilsLabelEXT);
inline void QueueBeginDebugUtilsLabelEXT(const VkDebugUtilsLabelEXT& labelInfo) {
	QueueBeginDebugUtilsLabelEXT(ThreadContext::Queue(), labelInfo);
}
DefineRaiiFunction(QueueBeginDebugUtilsLabelEXT, DebugUtilsLabelEXT);

inline void QueueEndDebugUtilsLabelEXT(VkQueue queue = ThreadContext::Queue()) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkQueueEndDebugUtilsLabelEXT(queue);
}

inline void QueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT& labelInfo) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkQueueInsertDebugUtilsLabelEXT(queue, &labelInfo);
}
DefineRaiiFunction_R(QueueInsertDebugUtilsLabelEXT, VkQueue, queue, DebugUtilsLabelEXT);
inline void QueueInsertDebugUtilsLabelEXT(const VkDebugUtilsLabelEXT& labelInfo) {
	QueueInsertDebugUtilsLabelEXT(ThreadContext::Queue(), labelInfo);
}
DefineRaiiFunction(QueueInsertDebugUtilsLabelEXT, DebugUtilsLabelEXT);

inline void CmdBeginDebugUtilsLabelEXT(const VkDebugUtilsLabelEXT& labelInfo) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkCmdBeginDebugUtilsLabelEXT(ThreadContext::CommandBuffer(), &labelInfo);
}
DefineRaiiFunction(CmdBeginDebugUtilsLabelEXT, DebugUtilsLabelEXT);

inline void CmdEndDebugUtilsLabelEXT() {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkCmdEndDebugUtilsLabelEXT(ThreadContext::CommandBuffer());
}

inline void CmdInsertDebugUtilsLabelEXT(const VkDebugUtilsLabelEXT& labelInfo) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkCmdInsertDebugUtilsLabelEXT(ThreadContext::CommandBuffer(), &labelInfo);
}
DefineRaiiFunction(CmdInsertDebugUtilsLabelEXT, DebugUtilsLabelEXT);

inline VkResult CreateDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT& createInfo, HandleRef<VkDebugUtilsMessengerEXT> messenger) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkCreateDebugUtilsMessengerEXT(InstanceContext::Instance(), &createInfo, ThreadContext::PAllocator(), &messenger);
}
DefineRaiiFunction_ResultL(VkResult, CreateDebugUtilsMessengerEXT, DebugUtilsMessengerCreateInfoEXT, HandleRef<VkDebugUtilsMessengerEXT>, messenger);

inline void DestroyDebugUtilsMessengerEXT(HandleRef<VkDebugUtilsMessengerEXT> messenger, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkDestroyDebugUtilsMessengerEXT(InstanceContext::Instance(), messenger, &allocator);
	messenger = VK_NULL_HANDLE;
}

inline void SubmitDebugUtilsMessageEXT(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT& callbackData) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkSubmitDebugUtilsMessageEXT(InstanceContext::Instance(), messageSeverity, messageTypes, &callbackData);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(AttachmentSampleCountInfoAMD) {
	StructureClassHeader(AttachmentSampleCountInfoAMD);
	DefineSetter_Copy(ColorAttachmentCount, uint32_t, colorAttachmentCount);
	DefineSetter_ArrayRef(ColorAttachmentSamples, const VkSampleCountFlagBits, colorAttachmentSamples, colorAttachmentCount);
	DefineSetter_Copy(DepthStencilAttachmentSamples, VkSampleCountFlagBits, depthStencilAttachmentSamples);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentSampleCountInfoAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SampleLocationEXT) {
	StructureClassHeader_NoSType(SampleLocationEXT);
	DefineSetter_Copy(X, float, x);
	DefineSetter_Copy(Y, float, y);
};
VK_ENCAPSULATION_STRUCTURE_END(SampleLocationEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SampleLocationsInfoEXT) {
	StructureClassHeader(SampleLocationsInfoEXT);
	DefineSetter_Copy(SampleLocationsPerPixel, VkSampleCountFlagBits, sampleLocationsPerPixel);
	DefineSetter_Copy(SampleLocationGridSize, VkExtent2D, sampleLocationGridSize);
	DefineSetter_Copy(SampleLocationsCount, uint32_t, sampleLocationsCount);
	DefineSetter_ArrayRef(SampleLocations, const VkSampleLocationEXT, sampleLocations, sampleLocationsCount);
};
VK_ENCAPSULATION_STRUCTURE_END(SampleLocationsInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AttachmentSampleLocationsEXT) {
	StructureClassHeader_NoSType(AttachmentSampleLocationsEXT);
	DefineSetter_Copy(AttachmentIndex, uint32_t, attachmentIndex);
	DefineSetter_Copy(SampleLocationsInfo, VkSampleLocationsInfoEXT, sampleLocationsInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(AttachmentSampleLocationsEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SubpassSampleLocationsEXT) {
	StructureClassHeader_NoSType(SubpassSampleLocationsEXT);
	DefineSetter_Copy(SubpassIndex, uint32_t, subpassIndex);
	DefineSetter_Copy(SampleLocationsInfo, VkSampleLocationsInfoEXT, sampleLocationsInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassSampleLocationsEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassSampleLocationsBeginInfoEXT) {
	StructureClassHeader(RenderPassSampleLocationsBeginInfoEXT);
	DefineSetter_Copy(AttachmentInitialSampleLocationsCount, uint32_t, attachmentInitialSampleLocationsCount);
	DefineSetter_ArrayRef(AttachmentInitialSampleLocations, const VkAttachmentSampleLocationsEXT, attachmentInitialSampleLocations, attachmentInitialSampleLocationsCount);
	DefineSetter_Copy(PostSubpassSampleLocationsCount, uint32_t, postSubpassSampleLocationsCount);
	DefineSetter_ArrayRef(PostSubpassSampleLocations, const VkSubpassSampleLocationsEXT, postSubpassSampleLocations, postSubpassSampleLocationsCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassSampleLocationsBeginInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineSampleLocationsStateCreateInfoEXT) {
	StructureClassHeader(PipelineSampleLocationsStateCreateInfoEXT);
	DefineSetter_Copy(SampleLocationsEnable, VkBool32, sampleLocationsEnable);
	DefineSetter_CopyOptional(SampleLocationsInfo, VkSampleLocationsInfoEXT, sampleLocationsInfo, sampleLocationsEnable, true);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineSampleLocationsStateCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSampleLocationsPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceSampleLocationsPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSampleLocationsPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MultisamplePropertiesEXT) {
	StructureClassHeader(MultisamplePropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(MultisamplePropertiesEXT)

inline void CmdSetSampleLocationsEXT(const VkSampleLocationsInfoEXT& sampleLocationsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetSampleLocationsEXT(ThreadContext::CommandBuffer(), &sampleLocationsInfo);
}
DefineRaiiFunction(CmdSetSampleLocationsEXT, SampleLocationsInfoEXT);

inline void GetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT& multisampleProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, &multisampleProperties);
}
inline void GetPhysicalDeviceMultisamplePropertiesEXT(VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT& multisampleProperties) {
	GetPhysicalDeviceMultisamplePropertiesEXT(DeviceContext::PhysicalDevice(), samples, multisampleProperties);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceBlendOperationAdvancedFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceBlendOperationAdvancedFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceBlendOperationAdvancedFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceBlendOperationAdvancedPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceBlendOperationAdvancedPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceBlendOperationAdvancedPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineColorBlendAdvancedStateCreateInfoEXT) {
	StructureClassHeader(PipelineColorBlendAdvancedStateCreateInfoEXT);
	DefineSetter_Copy(SrcPremultiplied, VkBool32, srcPremultiplied);
	DefineSetter_Copy(DstPremultiplied, VkBool32, dstPremultiplied);
	DefineSetter_Copy(BlendOverlap, VkBlendOverlapEXT, blendOverlap);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineColorBlendAdvancedStateCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCoverageToColorStateCreateInfoNV) {
	StructureClassHeader(PipelineCoverageToColorStateCreateInfoNV);
	DefineSetter_Copy(Flags, VkPipelineCoverageToColorStateCreateFlagsNV, flags);
	DefineSetter_Copy(CoverageToColorEnable, VkBool32, coverageToColorEnable);
	DefineSetter_CopyOptional(CoverageToColorLocation, uint32_t, coverageToColorLocation, coverageToColorEnable, true);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCoverageToColorStateCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCoverageModulationStateCreateInfoNV) {
	StructureClassHeader(PipelineCoverageModulationStateCreateInfoNV);
	DefineSetter_Copy(Flags, VkPipelineCoverageModulationStateCreateFlagsNV, flags);
	DefineSetter_Copy(CoverageModulationMode, VkCoverageModulationModeNV, coverageModulationMode);
	DefineSetter_Copy(CoverageModulationTableEnable, VkBool32, coverageModulationTableEnable);
	DefineSetter_ArrayRef(CoverageModulationTable, const float, coverageModulationTable, coverageModulationTableCount, coverageModulationTableEnable = bool(coverageModulationTable));
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCoverageModulationStateCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderSMBuiltinsPropertiesNV) {
	StructureClassHeader(PhysicalDeviceShaderSMBuiltinsPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderSMBuiltinsPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderSMBuiltinsFeaturesNV) {
	StructureClassHeader(PhysicalDeviceShaderSMBuiltinsFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderSMBuiltinsFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DrmFormatModifierPropertiesEXT) {
	StructureClassHeader_NoSType(DrmFormatModifierPropertiesEXT);
	DefineSetter_Copy(DrmFormatModifier, uint64_t, drmFormatModifier);
	DefineSetter_Copy(DrmFormatModifierPlaneCount, uint32_t, drmFormatModifierPlaneCount);
	DefineSetter_Copy(DrmFormatModifierTilingFeatures, VkFormatFeatureFlags, drmFormatModifierTilingFeatures);
};
VK_ENCAPSULATION_STRUCTURE_END(DrmFormatModifierPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DrmFormatModifierPropertiesListEXT) {
	StructureClassHeader(DrmFormatModifierPropertiesListEXT);
	DefineSetter_Copy(DrmFormatModifierCount, uint32_t, drmFormatModifierCount);
	DefineSetter_ArrayRef(DrmFormatModifierProperties, VkDrmFormatModifierPropertiesEXT, drmFormatModifierProperties, drmFormatModifierCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DrmFormatModifierPropertiesListEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageDrmFormatModifierInfoEXT) {
	StructureClassHeader(PhysicalDeviceImageDrmFormatModifierInfoEXT);
	DefineSetter_Copy(DrmFormatModifier, uint64_t, drmFormatModifier);
	DefineSetter_Copy(SharingMode, VkSharingMode, sharingMode);
	DefineSetter_ArrayRef(QueueFamilyIndices, const uint32_t, queueFamilyIndices, queueFamilyIndexCount, sharingMode = VkSharingMode(bool(queueFamilyIndices)));
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageDrmFormatModifierInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageDrmFormatModifierListCreateInfoEXT) {
	StructureClassHeader(ImageDrmFormatModifierListCreateInfoEXT);
	DefineSetter_Copy(DrmFormatModifierCount, uint32_t, drmFormatModifierCount);
	DefineSetter_ArrayRef(DrmFormatModifiers, const uint64_t, drmFormatModifiers, drmFormatModifierCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageDrmFormatModifierListCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageDrmFormatModifierExplicitCreateInfoEXT) {
	StructureClassHeader(ImageDrmFormatModifierExplicitCreateInfoEXT);
	DefineSetter_Copy(DrmFormatModifier, uint64_t, drmFormatModifier);
	DefineSetter_Copy(DrmFormatModifierPlaneCount, uint32_t, drmFormatModifierPlaneCount);
	DefineSetter_ArrayRef(PlaneLayouts, const VkSubresourceLayout, planeLayouts, drmFormatModifierPlaneCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageDrmFormatModifierExplicitCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageDrmFormatModifierPropertiesEXT) {
	StructureClassHeader(ImageDrmFormatModifierPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageDrmFormatModifierPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DrmFormatModifierProperties2EXT) {
	StructureClassHeader_NoSType(DrmFormatModifierProperties2EXT);
};
VK_ENCAPSULATION_STRUCTURE_END(DrmFormatModifierProperties2EXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DrmFormatModifierPropertiesList2EXT) {
	StructureClassHeader(DrmFormatModifierPropertiesList2EXT);
	DefineSetter_Copy(DrmFormatModifierCount, uint32_t, drmFormatModifierCount);
	DefineSetter_ArrayRef(DrmFormatModifierProperties, VkDrmFormatModifierProperties2EXT, drmFormatModifierProperties, drmFormatModifierCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DrmFormatModifierPropertiesList2EXT)

inline VkResult GetImageDrmFormatModifierPropertiesEXT(VkImage image, VkImageDrmFormatModifierPropertiesEXT& properties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageDrmFormatModifierPropertiesEXT(DeviceContext::Device(), image, &properties);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(ValidationCacheCreateInfoEXT) {
	StructureClassHeader(ValidationCacheCreateInfoEXT);
	DefineSetter_Copy(Flags, VkValidationCacheCreateFlagsEXT, flags);
	DefineSetter_Copy(InitialDataSize, size_t, initialDataSize);
	DefineSetter_ArrayRef(InitialData, const void, initialData, initialDataSize);
	_&  InitialData(const IsNotRangeOrPointer auto& initialData) &  { return InitialData({ sizeof * &initialData, &initialData }); }
	_&& InitialData(const IsNotRangeOrPointer auto& initialData) && { return std::move(InitialData(initialData)); }
	_&  InitialData(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(ValidationCacheCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ShaderModuleValidationCacheCreateInfoEXT) {
	StructureClassHeader(ShaderModuleValidationCacheCreateInfoEXT);
	DefineSetter_Copy(ValidationCache, VkValidationCacheEXT, validationCache);
};
VK_ENCAPSULATION_STRUCTURE_END(ShaderModuleValidationCacheCreateInfoEXT)

inline VkResult CreateValidationCacheEXT(const VkValidationCacheCreateInfoEXT& createInfo, HandleRef<VkValidationCacheEXT> validationCache) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateValidationCacheEXT(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &validationCache);
}
DefineRaiiFunction_ResultL(VkResult, CreateValidationCacheEXT, ValidationCacheCreateInfoEXT, HandleRef<VkValidationCacheEXT>, validationCache);

inline void DestroyValidationCacheEXT(HandleRef<VkValidationCacheEXT> validationCache, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyValidationCacheEXT(DeviceContext::Device(), validationCache, &allocator);
	validationCache = VK_NULL_HANDLE;
}

inline VkResult MergeValidationCachesEXT(VkValidationCacheEXT dstCache, ArrayRef<const VkValidationCacheEXT> srcCaches) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkMergeValidationCachesEXT(DeviceContext::Device(), dstCache, srcCaches.size(), srcCaches);
}

inline VkResult GetValidationCacheDataEXT(VkValidationCacheEXT validationCache, size_t& dataSize, ArrayRef<void> data = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetValidationCacheDataEXT(DeviceContext::Device(), validationCache, &dataSize, data);
}
inline VkResult GetValidationCacheDataEXT(VkValidationCacheEXT validationCache, size_t& dataSize, IsNotRangeOrPointer auto& data) {
	return GetValidationCacheDataEXT(validationCache, dataSize, { 0, &data });
}
inline VkResult GetValidationCacheDataEXT(VkValidationCacheEXT validationCache, IsDynamicByteArray auto& data) {
	size_t size = 0;
	VkResult result = GetValidationCacheDataEXT(validationCache, size);
	if (result == VK_SUCCESS)
		data.resize(size),
		result = GetValidationCacheDataEXT(validationCache, size, data);
	return result;
}

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ShadingRatePaletteNV) {
	StructureClassHeader_NoSType(ShadingRatePaletteNV);
	DefineSetter_Copy(ShadingRatePaletteEntryCount, uint32_t, shadingRatePaletteEntryCount);
	DefineSetter_ArrayRef(ShadingRatePaletteEntries, const VkShadingRatePaletteEntryNV, shadingRatePaletteEntries, shadingRatePaletteEntryCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ShadingRatePaletteNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportShadingRateImageStateCreateInfoNV) {
	StructureClassHeader(PipelineViewportShadingRateImageStateCreateInfoNV);
	DefineSetter_Copy(ShadingRateImageEnable, VkBool32, shadingRateImageEnable);
	DefineSetter_CopyOptional(ViewportCount, uint32_t, viewportCount, shadingRateImageEnable, true);
	// If the shading rate palette state is dynamic, pShadingRatePalettes is ignored.
	DefineSetter_ArrayRef(ShadingRatePalettes, const VkShadingRatePaletteNV, shadingRatePalettes, viewportCount, shadingRateImageEnable = bool(shadingRatePalettes));
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportShadingRateImageStateCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShadingRateImageFeaturesNV) {
	StructureClassHeader(PhysicalDeviceShadingRateImageFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShadingRateImageFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShadingRateImagePropertiesNV) {
	StructureClassHeader(PhysicalDeviceShadingRateImagePropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShadingRateImagePropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(CoarseSampleLocationNV) {
	StructureClassHeader_NoSType(CoarseSampleLocationNV);
	DefineSetter_Copy(PixelX, uint32_t, pixelX);
	DefineSetter_Copy(PixelY, uint32_t, pixelY);
	DefineSetter_Copy(Sample, uint32_t, sample);
};
VK_ENCAPSULATION_STRUCTURE_END(CoarseSampleLocationNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(CoarseSampleOrderCustomNV) {
	StructureClassHeader_NoSType(CoarseSampleOrderCustomNV);
	DefineSetter_Copy(ShadingRate, VkShadingRatePaletteEntryNV, shadingRate);
	DefineSetter_Copy(SampleCount, uint32_t, sampleCount);
	DefineSetter_Copy(SampleLocationCount, uint32_t, sampleLocationCount);
	DefineSetter_ArrayRef(SampleLocations, const VkCoarseSampleLocationNV, sampleLocations, sampleLocationCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CoarseSampleOrderCustomNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportCoarseSampleOrderStateCreateInfoNV) {
	StructureClassHeader(PipelineViewportCoarseSampleOrderStateCreateInfoNV);
	DefineSetter_Copy(SampleOrderType, VkCoarseSampleOrderTypeNV, sampleOrderType);
	DefineSetter_Copy(CustomSampleOrderCount, uint32_t, customSampleOrderCount);
	DefineSetter_ArrayRef(CustomSampleOrders, const VkCoarseSampleOrderCustomNV, customSampleOrders, customSampleOrderCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportCoarseSampleOrderStateCreateInfoNV)

inline void CmdBindShadingRateImageNV(VkImageView imageView, VkImageLayout imageLayout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindShadingRateImageNV(ThreadContext::CommandBuffer(), imageView, imageLayout);
}

inline void CmdSetViewportShadingRatePaletteNV(uint32_t firstViewport, ArrayRef<const VkShadingRatePaletteNV> shadingRatePalettes) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetViewportShadingRatePaletteNV(ThreadContext::CommandBuffer(), firstViewport, shadingRatePalettes.size(), shadingRatePalettes);
}

inline void CmdSetCoarseSampleOrderNV(VkCoarseSampleOrderTypeNV sampleOrderType, ArrayRef<const VkCoarseSampleOrderCustomNV> customSampleOrders) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCoarseSampleOrderNV(ThreadContext::CommandBuffer(), sampleOrderType, customSampleOrders.size(), customSampleOrders);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(RayTracingShaderGroupCreateInfoNV) {
	StructureClassHeader(RayTracingShaderGroupCreateInfoNV);
	DefineSetter_Copy(Type, VkRayTracingShaderGroupTypeKHR, type);
	DefineSetter_Copy(GeneralShader, uint32_t, generalShader);
	DefineSetter_Copy(ClosestHitShader, uint32_t, closestHitShader);
	DefineSetter_Copy(AnyHitShader, uint32_t, anyHitShader);
	DefineSetter_Copy(IntersectionShader, uint32_t, intersectionShader);
};
VK_ENCAPSULATION_STRUCTURE_END(RayTracingShaderGroupCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RayTracingPipelineCreateInfoNV) {
	StructureClassHeader(RayTracingPipelineCreateInfoNV, .basePipelineIndex = -1);
	DefineSetter_Copy(Flags, VkPipelineCreateFlags, flags);
	DefineSetter_Copy(StageCount, uint32_t, stageCount);
	DefineSetter_ArrayRef(Stages, const VkPipelineShaderStageCreateInfo, stages, stageCount);
	DefineSetter_Copy(GroupCount, uint32_t, groupCount);
	DefineSetter_ArrayRef(Groups, const VkRayTracingShaderGroupCreateInfoNV, groups, groupCount);
	DefineSetter_Copy(MaxRecursionDepth, uint32_t, maxRecursionDepth);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(BasePipelineHandle, VkPipeline, basePipelineHandle);
	DefineSetter_Copy(BasePipelineIndex, int32_t, basePipelineIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(RayTracingPipelineCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeometryTrianglesNV) {
	StructureClassHeader(GeometryTrianglesNV);
	DefineSetter_Copy(VertexData, VkBuffer, vertexData);
	DefineSetter_Copy(VertexOffset, VkDeviceSize, vertexOffset);
	DefineSetter_Copy(VertexCount, uint32_t, vertexCount);
	DefineSetter_Copy(VertexStride, VkDeviceSize, vertexStride);
	DefineSetter_Copy(VertexFormat, VkFormat, vertexFormat);
	DefineSetter_Copy(IndexData, VkBuffer, indexData);
	DefineSetter_Copy(IndexOffset, VkDeviceSize, indexOffset);
	DefineSetter_Copy(IndexCount, uint32_t, indexCount);
	DefineSetter_Copy(IndexType, VkIndexType, indexType);
	DefineSetter_Copy(TransformData, VkBuffer, transformData);
	DefineSetter_Copy(TransformOffset, VkDeviceSize, transformOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(GeometryTrianglesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeometryAABBNV) {
	StructureClassHeader(GeometryAABBNV);
	DefineSetter_Copy(AabbData, VkBuffer, aabbData);
	DefineSetter_Copy(NumAABBs, uint32_t, numAABBs);
	DefineSetter_Copy(Stride, uint32_t, stride);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
};
VK_ENCAPSULATION_STRUCTURE_END(GeometryAABBNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(GeometryDataNV) {
	StructureClassHeader_NoSType(GeometryDataNV);
	DefineSetter_Copy(Triangles, VkGeometryTrianglesNV, triangles);
	DefineSetter_Copy(Aabbs, VkGeometryAABBNV, aabbs);
};
VK_ENCAPSULATION_STRUCTURE_END(GeometryDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeometryNV) {
	StructureClassHeader(GeometryNV);
	DefineSetter_Copy(GeometryType, VkGeometryTypeKHR, geometryType);
	DefineSetter_Copy(Geometry, VkGeometryDataNV, geometry);
	DefineSetter_Copy(Flags, VkGeometryFlagsKHR, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(GeometryNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureInfoNV) {
	StructureClassHeader(AccelerationStructureInfoNV);
	DefineSetter_Copy(Type, VkAccelerationStructureTypeNV, type);
	DefineSetter_Copy(Flags, VkBuildAccelerationStructureFlagsNV, flags);
	DefineSetter_Copy(InstanceCount, uint32_t, instanceCount);
	DefineSetter_Copy(GeometryCount, uint32_t, geometryCount);
	DefineSetter_ArrayRef(Geometries, const VkGeometryNV, geometries, geometryCount);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureCreateInfoNV) {
	StructureClassHeader(AccelerationStructureCreateInfoNV);
	DefineSetter_Copy(CompactedSize, VkDeviceSize, compactedSize);
	DefineSetter_Copy(Info, VkAccelerationStructureInfoNV, info);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindAccelerationStructureMemoryInfoNV) {
	StructureClassHeader(BindAccelerationStructureMemoryInfoNV);
	DefineSetter_Copy(AccelerationStructure, VkAccelerationStructureNV, accelerationStructure);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
	DefineSetter_Copy(DeviceIndexCount, uint32_t, deviceIndexCount);
	DefineSetter_ArrayRef(DeviceIndices, const uint32_t, deviceIndices, deviceIndexCount);
};
VK_ENCAPSULATION_STRUCTURE_END(BindAccelerationStructureMemoryInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteDescriptorSetAccelerationStructureNV) {
	StructureClassHeader(WriteDescriptorSetAccelerationStructureNV);
	DefineSetter_Copy(AccelerationStructureCount, uint32_t, accelerationStructureCount);
	DefineSetter_ArrayRef(AccelerationStructures, const VkAccelerationStructureNV, accelerationStructures, accelerationStructureCount);
};
VK_ENCAPSULATION_STRUCTURE_END(WriteDescriptorSetAccelerationStructureNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureMemoryRequirementsInfoNV) {
	StructureClassHeader(AccelerationStructureMemoryRequirementsInfoNV);
	DefineSetter_Copy(Type, VkAccelerationStructureMemoryRequirementsTypeNV, type);
	DefineSetter_Copy(AccelerationStructure, VkAccelerationStructureNV, accelerationStructure);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureMemoryRequirementsInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingPropertiesNV) {
	StructureClassHeader(PhysicalDeviceRayTracingPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(TransformMatrixKHR) {
	StructureClassHeader_NoSType(TransformMatrixKHR);
	// float matrix[3][4];
	DefineSetter_ArrayCopy(Matrix, float, matrix);
	_&  Matrix(const float(&matrix)[3][4]) &  { std::memcpy(this, &matrix, sizeof matrix); return *this; }
	_&& Matrix(const float(&matrix)[3][4]) && { return std::move(Matrix(matrix)); }
	_&  Matrix(const std::array<std::array<float, 4>, 3>& matrix) &  { std::memcpy(this, &matrix, sizeof matrix); return *this; }
	_&& Matrix(const std::array<std::array<float, 4>, 3>& matrix) && { return std::move(Matrix(matrix)); }
};
VK_ENCAPSULATION_STRUCTURE_END(TransformMatrixKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AabbPositionsKHR) {
	StructureClassHeader_NoSType(AabbPositionsKHR);
	DefineSetter_Copy(MinX, float, minX);
	DefineSetter_Copy(MinY, float, minY);
	DefineSetter_Copy(MinZ, float, minZ);
	DefineSetter_Copy(MaxX, float, maxX);
	DefineSetter_Copy(MaxY, float, maxY);
	DefineSetter_Copy(MaxZ, float, maxZ);
};
VK_ENCAPSULATION_STRUCTURE_END(AabbPositionsKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AccelerationStructureInstanceKHR) {
	StructureClassHeader_NoSType(AccelerationStructureInstanceKHR);
	DefineSetter_Copy(Transform, VkTransformMatrixKHR, transform);
	DefineSetter_Copy(InstanceCustomIndex, uint32_t, instanceCustomIndex);
	DefineSetter_Copy(Mask, uint32_t, mask);
	DefineSetter_Copy(InstanceShaderBindingTableRecordOffset, uint32_t, instanceShaderBindingTableRecordOffset);
	DefineSetter_Copy(Flags, VkGeometryInstanceFlagsKHR, flags);
	DefineSetter_Copy(AccelerationStructureReference, uint64_t, accelerationStructureReference);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureInstanceKHR)

inline VkResult CreateAccelerationStructureNV(const VkAccelerationStructureCreateInfoNV& createInfo, HandleRef<VkAccelerationStructureNV> accelerationStructure) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateAccelerationStructureNV(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &accelerationStructure);
}
DefineRaiiFunction_ResultL(VkResult, CreateAccelerationStructureNV, AccelerationStructureCreateInfoNV, HandleRef<VkAccelerationStructureNV>, accelerationStructure);

inline void DestroyAccelerationStructureNV(HandleRef<VkAccelerationStructureNV> accelerationStructure, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyAccelerationStructureNV(DeviceContext::Device(), accelerationStructure, &allocator);
	accelerationStructure = VK_NULL_HANDLE;
}

inline void GetAccelerationStructureMemoryRequirementsNV(const VkAccelerationStructureMemoryRequirementsInfoNV& info, VkMemoryRequirements2KHR& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetAccelerationStructureMemoryRequirementsNV(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetAccelerationStructureMemoryRequirementsNV, AccelerationStructureMemoryRequirementsInfoNV, VkMemoryRequirements2KHR&, memoryRequirements);

inline VkResult BindAccelerationStructureMemoryNV(ArrayRef<const VkBindAccelerationStructureMemoryInfoNV> bindInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindAccelerationStructureMemoryNV(DeviceContext::Device(), bindInfos.size(), bindInfos);
}
DefineRaiiFunction_Result(VkResult, BindAccelerationStructureMemoryNV, BindAccelerationStructureMemoryInfoNV);

inline void CmdBuildAccelerationStructureNV(const VkAccelerationStructureInfoNV& info, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBuildAccelerationStructureNV(ThreadContext::CommandBuffer(), &info, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

inline void CmdCopyAccelerationStructureNV(VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyAccelerationStructureNV(ThreadContext::CommandBuffer(), dst, src, mode);
}

inline void CmdTraceRaysNV(VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdTraceRaysNV(ThreadContext::CommandBuffer(), raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

inline VkResult CreateRayTracingPipelinesNV(VkPipelineCache pipelineCache, ArrayRef<const VkRayTracingPipelineCreateInfoNV> createInfos, HandleArrayRef<VkPipeline> pipelines) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateRayTracingPipelinesNV(DeviceContext::Device(), pipelineCache, createInfos.size(), createInfos, ThreadContext::PAllocator(), pipelines);
}

inline VkResult GetRayTracingShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRayTracingShaderGroupHandlesKHR(DeviceContext::Device(), pipeline, firstGroup, groupCount, data.size(), data);
}
inline VkResult GetRayTracingShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, IsNotRangeOrPointer auto& data) {
	return GetRayTracingCaptureReplayShaderGroupHandlesKHR(pipeline, firstGroup, groupCount, { sizeof *&data, &data });
}

inline VkResult GetRayTracingShaderGroupHandlesNV(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRayTracingShaderGroupHandlesNV(DeviceContext::Device(), pipeline, firstGroup, groupCount, data.size(), data);
}
inline VkResult GetRayTracingShaderGroupHandlesNV(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, IsNotRangeOrPointer auto& data) {
	return GetRayTracingShaderGroupHandlesNV(pipeline, firstGroup, groupCount, { sizeof *&data, &data });
}

inline VkResult GetAccelerationStructureHandleNV(VkAccelerationStructureNV accelerationStructure, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetAccelerationStructureHandleNV(DeviceContext::Device(), accelerationStructure, data.size(), data);
}
inline VkResult GetAccelerationStructureHandleNV(VkAccelerationStructureNV accelerationStructure, IsNotRangeOrPointer auto& data) {
	return GetAccelerationStructureHandleNV(accelerationStructure, { sizeof *&data, &data });
}

inline void CmdWriteAccelerationStructuresPropertiesNV(ArrayRef<const VkAccelerationStructureNV> accelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteAccelerationStructuresPropertiesNV(ThreadContext::CommandBuffer(), accelerationStructures.size(), accelerationStructures, queryType, queryPool, firstQuery);
}

inline VkResult CompileDeferredNV(VkPipeline pipeline, uint32_t shader) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCompileDeferredNV(DeviceContext::Device(), pipeline, shader);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRepresentativeFragmentTestFeaturesNV) {
	StructureClassHeader(PhysicalDeviceRepresentativeFragmentTestFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRepresentativeFragmentTestFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRepresentativeFragmentTestStateCreateInfoNV) {
	StructureClassHeader(PipelineRepresentativeFragmentTestStateCreateInfoNV);
	DefineSetter_Copy(RepresentativeFragmentTestEnable, VkBool32, representativeFragmentTestEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRepresentativeFragmentTestStateCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageViewImageFormatInfoEXT) {
	StructureClassHeader(PhysicalDeviceImageViewImageFormatInfoEXT);
	DefineSetter_Copy(ImageViewType, VkImageViewType, imageViewType);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageViewImageFormatInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FilterCubicImageViewImageFormatPropertiesEXT) {
	StructureClassHeader(FilterCubicImageViewImageFormatPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(FilterCubicImageViewImageFormatPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImportMemoryHostPointerInfoEXT) {
	StructureClassHeader(ImportMemoryHostPointerInfoEXT);
	DefineSetter_Copy(HandleType, VkExternalMemoryHandleTypeFlagBits, handleType);
	DefineSetter_Copy(PHostPointer, void*, pHostPointer);
};
VK_ENCAPSULATION_STRUCTURE_END(ImportMemoryHostPointerInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryHostPointerPropertiesEXT) {
	StructureClassHeader(MemoryHostPointerPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryHostPointerPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalMemoryHostPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceExternalMemoryHostPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalMemoryHostPropertiesEXT)

inline VkResult GetMemoryHostPointerPropertiesEXT(VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT& memoryHostPointerProperties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetMemoryHostPointerPropertiesEXT(DeviceContext::Device(), handleType, pHostPointer, &memoryHostPointerProperties);
}

inline void CmdWriteBufferMarkerAMD(VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteBufferMarkerAMD(ThreadContext::CommandBuffer(), pipelineStage, dstBuffer, dstOffset, marker);
}

inline void CmdWriteBufferMarker2AMD(VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteBufferMarker2AMD(ThreadContext::CommandBuffer(), stage, dstBuffer, dstOffset, marker);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCompilerControlCreateInfoAMD) {
	StructureClassHeader(PipelineCompilerControlCreateInfoAMD);
	DefineSetter_Copy(CompilerControlFlags, VkPipelineCompilerControlFlagsAMD, compilerControlFlags);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCompilerControlCreateInfoAMD)

inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t& timeDomainCount, ArrayRef<VkTimeDomainKHR> timeDomains = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, &timeDomainCount, timeDomains);
}
inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, IsDynamicArray<VkTimeDomainKHR> auto& timeDomains) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, count);
	if (result == VK_SUCCESS)
		timeDomains.resize(count),
		result = GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, count, timeDomains);
	return result;
}
inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsEXT(uint32_t& timeDomainCount, ArrayRef<VkTimeDomainKHR> timeDomains = {}) {
	return GetPhysicalDeviceCalibrateableTimeDomainsEXT(DeviceContext::PhysicalDevice(), timeDomainCount, timeDomains);
}
inline VkResult GetPhysicalDeviceCalibrateableTimeDomainsEXT(IsDynamicArray<VkTimeDomainKHR> auto& timeDomains) {
	return GetPhysicalDeviceCalibrateableTimeDomainsEXT(DeviceContext::PhysicalDevice(), timeDomains);
}

inline VkResult GetCalibratedTimestampsEXT(ArrayRef<const VkCalibratedTimestampInfoKHR> timestampInfos, ArrayRef<uint64_t> timestamps, uint64_t& maxDeviation) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetCalibratedTimestampsEXT(DeviceContext::Device(), timestampInfos.size(), timestampInfos, timestamps, &maxDeviation);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderCorePropertiesAMD) {
	StructureClassHeader(PhysicalDeviceShaderCorePropertiesAMD);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderCorePropertiesAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceMemoryOverallocationCreateInfoAMD) {
	StructureClassHeader(DeviceMemoryOverallocationCreateInfoAMD);
	DefineSetter_Copy(OverallocationBehavior, VkMemoryOverallocationBehaviorAMD, overallocationBehavior);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceMemoryOverallocationCreateInfoAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVertexAttributeDivisorPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceVertexAttributeDivisorPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVertexAttributeDivisorPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMeshShaderFeaturesNV) {
	StructureClassHeader(PhysicalDeviceMeshShaderFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMeshShaderFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMeshShaderPropertiesNV) {
	StructureClassHeader(PhysicalDeviceMeshShaderPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMeshShaderPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DrawMeshTasksIndirectCommandNV) {
	StructureClassHeader_NoSType(DrawMeshTasksIndirectCommandNV);
	DefineSetter_Copy(TaskCount, uint32_t, taskCount);
	DefineSetter_Copy(FirstTask, uint32_t, firstTask);
};
VK_ENCAPSULATION_STRUCTURE_END(DrawMeshTasksIndirectCommandNV)

inline void CmdDrawMeshTasksNV(uint32_t taskCount, uint32_t firstTask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMeshTasksNV(ThreadContext::CommandBuffer(), taskCount, firstTask);
}

inline void CmdDrawMeshTasksIndirectNV(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMeshTasksIndirectNV(ThreadContext::CommandBuffer(), buffer, offset, drawCount, stride);
}

inline void CmdDrawMeshTasksIndirectCountNV(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMeshTasksIndirectCountNV(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderImageFootprintFeaturesNV) {
	StructureClassHeader(PhysicalDeviceShaderImageFootprintFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderImageFootprintFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportExclusiveScissorStateCreateInfoNV) {
	StructureClassHeader(PipelineViewportExclusiveScissorStateCreateInfoNV);
	DefineSetter_Copy(ExclusiveScissorCount, uint32_t, exclusiveScissorCount);
	DefineSetter_ArrayRef(ExclusiveScissors, const VkRect2D, exclusiveScissors, exclusiveScissorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportExclusiveScissorStateCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExclusiveScissorFeaturesNV) {
	StructureClassHeader(PhysicalDeviceExclusiveScissorFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExclusiveScissorFeaturesNV)

inline void CmdSetExclusiveScissorEnableNV(uint32_t firstExclusiveScissor, ArrayRef<const VkBool32> exclusiveScissorEnables) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetExclusiveScissorEnableNV(ThreadContext::CommandBuffer(), firstExclusiveScissor, exclusiveScissorEnables.size(), exclusiveScissorEnables);
}

inline void CmdSetExclusiveScissorNV(uint32_t firstExclusiveScissor, ArrayRef<const VkRect2D> exclusiveScissors) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetExclusiveScissorNV(ThreadContext::CommandBuffer(), firstExclusiveScissor, exclusiveScissors.size(), exclusiveScissors);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyCheckpointPropertiesNV) {
	StructureClassHeader(QueueFamilyCheckpointPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyCheckpointPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CheckpointDataNV) {
	StructureClassHeader(CheckpointDataNV);
};
VK_ENCAPSULATION_STRUCTURE_END(CheckpointDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyCheckpointProperties2NV) {
	StructureClassHeader(QueueFamilyCheckpointProperties2NV);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyCheckpointProperties2NV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CheckpointData2NV) {
	StructureClassHeader(CheckpointData2NV);
};
VK_ENCAPSULATION_STRUCTURE_END(CheckpointData2NV)

inline void CmdSetCheckpointNV(const auto& checkpointMarker) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCheckpointNV(ThreadContext::CommandBuffer(), &checkpointMarker);
}

inline void GetQueueCheckpointDataNV(VkQueue queue, uint32_t& checkpointDataCount, ArrayRef<VkCheckpointDataNV> checkpointData = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetQueueCheckpointDataNV(queue, &checkpointDataCount, checkpointData);
}
inline void GetQueueCheckpointDataNV(uint32_t& checkpointDataCount, ArrayRef<VkCheckpointDataNV> checkpointData = {}) {
	GetQueueCheckpointDataNV(ThreadContext::Queue(), checkpointDataCount, checkpointData);
}
inline void GetQueueCheckpointDataNV(VkQueue queue, IsDynamicArray<VkCheckpointDataNV> auto& checkpointData) {
	uint32_t count = 0;
	GetQueueCheckpointDataNV(queue, count);
	checkpointData.resize(count);
	GetQueueCheckpointDataNV(queue, count, checkpointData);
}
inline void GetQueueCheckpointDataNV(IsDynamicArray<VkCheckpointDataNV> auto& checkpointData) {
	GetQueueCheckpointDataNV(ThreadContext::Queue(), checkpointData);
}

inline void GetQueueCheckpointData2NV(VkQueue queue, uint32_t& checkpointDataCount, ArrayRef<VkCheckpointData2NV> checkpointData = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetQueueCheckpointData2NV(queue, &checkpointDataCount, checkpointData);
}
inline void GetQueueCheckpointData2NV(uint32_t& checkpointDataCount, ArrayRef<VkCheckpointData2NV> checkpointData = {}) {
	GetQueueCheckpointData2NV(ThreadContext::Queue(), checkpointDataCount, checkpointData);
}
inline void GetQueueCheckpointData2NV(VkQueue queue, IsDynamicArray<VkCheckpointData2NV> auto& checkpointData) {
	uint32_t count = 0;
	GetQueueCheckpointData2NV(queue, count);
	checkpointData.resize(count);
	GetQueueCheckpointData2NV(queue, count, checkpointData);
}
inline void GetQueueCheckpointData2NV(IsDynamicArray<VkCheckpointData2NV> auto& checkpointData) {
	GetQueueCheckpointData2NV(ThreadContext::Queue(), checkpointData);
}


VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL) {
	StructureClassHeader(PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(PerformanceValueDataINTEL) {
	StructureClassHeader_UnionWrapper(PerformanceValueDataINTEL);
	union {
		uint32_t    value32;
		uint64_t    value64;
		float       valueFloat;
		VkBool32    valueBool;
		const char* valueString;
	};
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceValueDataINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PerformanceValueINTEL) {
	StructureClassHeader_NoSType(PerformanceValueINTEL);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceValueINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN(InitializePerformanceApiInfoINTEL) {
	StructureClassHeader(InitializePerformanceApiInfoINTEL);
	DefineSetter_PointerAndRef(UserData, void, userData);
};
VK_ENCAPSULATION_STRUCTURE_END(InitializePerformanceApiInfoINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueryPoolPerformanceQueryCreateInfoINTEL) {
	StructureClassHeader(QueryPoolPerformanceQueryCreateInfoINTEL);
	DefineSetter_Copy(PerformanceCountersSampling, VkQueryPoolSamplingModeINTEL, performanceCountersSampling);
};
VK_ENCAPSULATION_STRUCTURE_END(QueryPoolPerformanceQueryCreateInfoINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerformanceMarkerInfoINTEL) {
	StructureClassHeader(PerformanceMarkerInfoINTEL);
	DefineSetter_Copy(Marker, uint64_t, marker);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceMarkerInfoINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerformanceStreamMarkerInfoINTEL) {
	StructureClassHeader(PerformanceStreamMarkerInfoINTEL);
	DefineSetter_Copy(Marker, uint32_t, marker);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceStreamMarkerInfoINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerformanceOverrideInfoINTEL) {
	StructureClassHeader(PerformanceOverrideInfoINTEL);
	DefineSetter_Copy(Type, VkPerformanceOverrideTypeINTEL, type);
	DefineSetter_Copy(Enable, VkBool32, enable);
	DefineSetter_CopyOptional(Parameter, uint64_t, parameter, enable, true);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceOverrideInfoINTEL)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerformanceConfigurationAcquireInfoINTEL) {
	StructureClassHeader(PerformanceConfigurationAcquireInfoINTEL);
	DefineSetter_Copy(Type, VkPerformanceConfigurationTypeINTEL, type);
};
VK_ENCAPSULATION_STRUCTURE_END(PerformanceConfigurationAcquireInfoINTEL)

inline VkResult InitializePerformanceApiINTEL(const VkInitializePerformanceApiInfoINTEL& initializeInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkInitializePerformanceApiINTEL(DeviceContext::Device(), &initializeInfo);
}
DefineRaiiFunction_Result(VkResult, InitializePerformanceApiINTEL, InitializePerformanceApiInfoINTEL);

inline void UninitializePerformanceApiINTEL() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkUninitializePerformanceApiINTEL(DeviceContext::Device());
}

inline VkResult CmdSetPerformanceMarkerINTEL(const VkPerformanceMarkerInfoINTEL& markerInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPerformanceMarkerINTEL(ThreadContext::CommandBuffer(), &markerInfo);
}
DefineRaiiFunction_Result(VkResult, CmdSetPerformanceMarkerINTEL, PerformanceMarkerInfoINTEL);

inline VkResult CmdSetPerformanceStreamMarkerINTEL(const VkPerformanceStreamMarkerInfoINTEL& markerInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPerformanceStreamMarkerINTEL(ThreadContext::CommandBuffer(), &markerInfo);
}
DefineRaiiFunction_Result(VkResult, CmdSetPerformanceStreamMarkerINTEL, PerformanceStreamMarkerInfoINTEL);

inline VkResult CmdSetPerformanceOverrideINTEL(const VkPerformanceOverrideInfoINTEL& overrideInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPerformanceOverrideINTEL(ThreadContext::CommandBuffer(), &overrideInfo);
}
DefineRaiiFunction_Result(VkResult, CmdSetPerformanceOverrideINTEL, PerformanceOverrideInfoINTEL);

inline VkResult AcquirePerformanceConfigurationINTEL(const VkPerformanceConfigurationAcquireInfoINTEL& acquireInfo, HandleRef<VkPerformanceConfigurationINTEL> configuration) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkAcquirePerformanceConfigurationINTEL(DeviceContext::Device(), &acquireInfo, &configuration);
}
DefineRaiiFunction_ResultL(VkResult, AcquirePerformanceConfigurationINTEL, PerformanceConfigurationAcquireInfoINTEL, HandleRef<VkPerformanceConfigurationINTEL>, configuration);

inline VkResult ReleasePerformanceConfigurationINTEL(HandleRef<VkPerformanceConfigurationINTEL> configuration) {
	VkResult result = VK_ENCAPSULATION_DEVICE_DISPATCH vkReleasePerformanceConfigurationINTEL(DeviceContext::Device(), configuration);
	if (result == VK_SUCCESS)
		configuration = VK_NULL_HANDLE;
	return result;
}

inline VkResult QueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
}
inline VkResult QueueSetPerformanceConfigurationINTEL(VkPerformanceConfigurationINTEL configuration) {
	return QueueSetPerformanceConfigurationINTEL(ThreadContext::Queue(), configuration);
}

inline VkResult GetPerformanceParameterINTEL(VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL& value) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPerformanceParameterINTEL(DeviceContext::Device(), parameter, &value);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePCIBusInfoPropertiesEXT) {
	StructureClassHeader(PhysicalDevicePCIBusInfoPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePCIBusInfoPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayNativeHdrSurfaceCapabilitiesAMD) {
	StructureClassHeader(DisplayNativeHdrSurfaceCapabilitiesAMD);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayNativeHdrSurfaceCapabilitiesAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainDisplayNativeHdrCreateInfoAMD) {
	StructureClassHeader(SwapchainDisplayNativeHdrCreateInfoAMD);
	DefineSetter_Copy(LocalDimmingEnable, VkBool32, localDimmingEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainDisplayNativeHdrCreateInfoAMD)

inline void SetLocalDimmingAMD(VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkSetLocalDimmingAMD(DeviceContext::Device(), swapChain, localDimmingEnable);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMapFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMapFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMapFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMapPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMapPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMapPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassFragmentDensityMapCreateInfoEXT) {
	StructureClassHeader(RenderPassFragmentDensityMapCreateInfoEXT);
	DefineSetter_Copy(FragmentDensityMapAttachment, VkAttachmentReference, fragmentDensityMapAttachment);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassFragmentDensityMapCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingFragmentDensityMapAttachmentInfoEXT) {
	StructureClassHeader(RenderingFragmentDensityMapAttachmentInfoEXT);
	DefineSetter_Copy(ImageView, VkImageView, imageView);
	DefineSetter_Copy(ImageLayout, VkImageLayout, imageLayout);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingFragmentDensityMapAttachmentInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderCoreProperties2AMD) {
	StructureClassHeader(PhysicalDeviceShaderCoreProperties2AMD);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderCoreProperties2AMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCoherentMemoryFeaturesAMD) {
	StructureClassHeader(PhysicalDeviceCoherentMemoryFeaturesAMD);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCoherentMemoryFeaturesAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderImageAtomicInt64FeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderImageAtomicInt64FeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderImageAtomicInt64FeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMemoryBudgetPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceMemoryBudgetPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMemoryBudgetPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMemoryPriorityFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceMemoryPriorityFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMemoryPriorityFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryPriorityAllocateInfoEXT) {
	StructureClassHeader(MemoryPriorityAllocateInfoEXT);
	DefineSetter_Copy(Priority, float, priority);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryPriorityAllocateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV) {
	StructureClassHeader(PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceBufferDeviceAddressFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceBufferDeviceAddressFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceBufferDeviceAddressFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferDeviceAddressCreateInfoEXT) {
	StructureClassHeader(BufferDeviceAddressCreateInfoEXT);
	DefineSetter_Copy(DeviceAddress, VkDeviceAddress, deviceAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferDeviceAddressCreateInfoEXT)

inline VkDeviceAddress GetBufferDeviceAddressEXT(const VkBufferDeviceAddressInfo& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferDeviceAddressEXT(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkDeviceAddress, GetBufferDeviceAddressEXT, BufferDeviceAddressInfo);

inline VkResult GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t& toolCount, ArrayRef<VkPhysicalDeviceToolProperties> toolProperties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, &toolCount, toolProperties);
}
inline VkResult GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, IsDynamicArray<VkPhysicalDeviceToolProperties> auto& toolProperties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceToolPropertiesEXT(physicalDevice, count);
	if (result == VK_SUCCESS)
		toolProperties.resize(count),
		result = GetPhysicalDeviceToolPropertiesEXT(physicalDevice, count, toolProperties);
	return result;
}
inline VkResult GetPhysicalDeviceToolPropertiesEXT(uint32_t& toolCount, ArrayRef<VkPhysicalDeviceToolProperties> toolProperties = {}) {
	return GetPhysicalDeviceToolPropertiesEXT(DeviceContext::PhysicalDevice(), toolCount, toolProperties);
}
inline VkResult GetPhysicalDeviceToolPropertiesEXT(IsDynamicArray<VkPhysicalDeviceToolProperties> auto& toolProperties) {
	return GetPhysicalDeviceToolPropertiesEXT(DeviceContext::PhysicalDevice(), toolProperties);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(ValidationFeaturesEXT) {
	StructureClassHeader(ValidationFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(ValidationFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CooperativeMatrixPropertiesNV) {
	StructureClassHeader(CooperativeMatrixPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(CooperativeMatrixPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeMatrixFeaturesNV) {
	StructureClassHeader(PhysicalDeviceCooperativeMatrixFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeMatrixFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeMatrixPropertiesNV) {
	StructureClassHeader(PhysicalDeviceCooperativeMatrixPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeMatrixPropertiesNV)

inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkCooperativeMatrixPropertiesNV> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, IsDynamicArray<VkCooperativeMatrixPropertiesNV> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesNV(uint32_t& propertyCount, ArrayRef<VkCooperativeMatrixPropertiesNV> properties = {}) {
	return GetPhysicalDeviceCooperativeMatrixPropertiesNV(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeMatrixPropertiesNV(IsDynamicArray<VkCooperativeMatrixPropertiesNV> auto& properties) {
	return GetPhysicalDeviceCooperativeMatrixPropertiesNV(DeviceContext::PhysicalDevice(), properties);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCoverageReductionModeFeaturesNV) {
	StructureClassHeader(PhysicalDeviceCoverageReductionModeFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCoverageReductionModeFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineCoverageReductionStateCreateInfoNV) {
	StructureClassHeader(PipelineCoverageReductionStateCreateInfoNV);
	DefineSetter_Copy(Flags, VkPipelineCoverageReductionStateCreateFlagsNV, flags);
	DefineSetter_Copy(CoverageReductionMode, VkCoverageReductionModeNV, coverageReductionMode);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineCoverageReductionStateCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FramebufferMixedSamplesCombinationNV) {
	StructureClassHeader(FramebufferMixedSamplesCombinationNV);
};
VK_ENCAPSULATION_STRUCTURE_END(FramebufferMixedSamplesCombinationNV)

inline VkResult GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t& combinationCount, ArrayRef<VkFramebufferMixedSamplesCombinationNV> combinations = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, &combinationCount, combinations);
}
inline VkResult GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, IsDynamicArray<VkFramebufferMixedSamplesCombinationNV> auto& combinations) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, count);
	if (result == VK_SUCCESS)
		combinations.resize(count),
		result = GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, count, combinations);
	return result;
}
inline VkResult GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(uint32_t& combinationCount, ArrayRef<VkFramebufferMixedSamplesCombinationNV> combinations = {}) {
	return GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(DeviceContext::PhysicalDevice(), combinationCount, combinations);
}
inline VkResult GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(IsDynamicArray<VkFramebufferMixedSamplesCombinationNV> auto& combinations) {
	return GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(DeviceContext::PhysicalDevice(), combinations);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShaderInterlockFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceFragmentShaderInterlockFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShaderInterlockFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceYcbcrImageArraysFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceYcbcrImageArraysFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceYcbcrImageArraysFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceProvokingVertexFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceProvokingVertexFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceProvokingVertexFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceProvokingVertexPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceProvokingVertexPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceProvokingVertexPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineRasterizationProvokingVertexStateCreateInfoEXT) {
	StructureClassHeader(PipelineRasterizationProvokingVertexStateCreateInfoEXT);
	DefineSetter_Copy(ProvokingVertexMode, VkProvokingVertexModeEXT, provokingVertexMode);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineRasterizationProvokingVertexStateCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(HeadlessSurfaceCreateInfoEXT) {
	StructureClassHeader(HeadlessSurfaceCreateInfoEXT);
	DefineSetter_Copy(Flags, VkHeadlessSurfaceCreateFlagsEXT, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(HeadlessSurfaceCreateInfoEXT)

inline VkResult CreateHeadlessSurfaceEXT(const VkHeadlessSurfaceCreateInfoEXT& createInfo, HandleRef<VkSurfaceKHR> surface) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkCreateHeadlessSurfaceEXT(InstanceContext::Instance(), &createInfo, ThreadContext::PAllocator(), &surface);
}
DefineRaiiFunction_ResultL(VkResult, CreateHeadlessSurfaceEXT, HeadlessSurfaceCreateInfoEXT, HandleRef<VkSurfaceKHR>, surface);

inline void CmdSetLineStippleEXT(uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLineStippleEXT(ThreadContext::CommandBuffer(), lineStippleFactor, lineStipplePattern);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderAtomicFloatFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderAtomicFloatFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderAtomicFloatFeaturesEXT)

inline void ResetQueryPoolEXT(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkResetQueryPoolEXT(DeviceContext::Device(), queryPool, firstQuery, queryCount);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExtendedDynamicStateFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceExtendedDynamicStateFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExtendedDynamicStateFeaturesEXT)

inline void CmdSetCullModeEXT(VkCullModeFlags cullMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCullModeEXT(ThreadContext::CommandBuffer(), cullMode);
}

inline void CmdSetFrontFaceEXT(VkFrontFace frontFace) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetFrontFaceEXT(ThreadContext::CommandBuffer(), frontFace);
}

inline void CmdSetPrimitiveTopologyEXT(VkPrimitiveTopology primitiveTopology) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPrimitiveTopologyEXT(ThreadContext::CommandBuffer(), primitiveTopology);
}

inline void CmdSetViewportWithCountEXT(ArrayRef<const VkViewport> viewports) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetViewportWithCountEXT(ThreadContext::CommandBuffer(), viewports.size(), viewports);
}

inline void CmdSetScissorWithCountEXT(ArrayRef<const VkRect2D> scissors) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetScissorWithCountEXT(ThreadContext::CommandBuffer(), scissors.size(), scissors);
}

inline void CmdBindVertexBuffers2EXT(uint32_t firstBinding, ArrayRef<const VkBuffer> buffers, ArrayRef<const VkDeviceSize> offsets, ArrayRef<const VkDeviceSize> sizes, ArrayRef<const VkDeviceSize> strides) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindVertexBuffers2EXT(ThreadContext::CommandBuffer(), firstBinding, buffers.size(), buffers, offsets, sizes, strides);
}

inline void CmdSetDepthTestEnableEXT(VkBool32 depthTestEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthTestEnableEXT(ThreadContext::CommandBuffer(), depthTestEnable);
}

inline void CmdSetDepthWriteEnableEXT(VkBool32 depthWriteEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthWriteEnableEXT(ThreadContext::CommandBuffer(), depthWriteEnable);
}

inline void CmdSetDepthCompareOpEXT(VkCompareOp depthCompareOp) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthCompareOpEXT(ThreadContext::CommandBuffer(), depthCompareOp);
}

inline void CmdSetDepthBoundsTestEnableEXT(VkBool32 depthBoundsTestEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthBoundsTestEnableEXT(ThreadContext::CommandBuffer(), depthBoundsTestEnable);
}

inline void CmdSetStencilTestEnableEXT(VkBool32 stencilTestEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetStencilTestEnableEXT(ThreadContext::CommandBuffer(), stencilTestEnable);
}

inline void CmdSetStencilOpEXT(VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetStencilOpEXT(ThreadContext::CommandBuffer(), faceMask, failOp, passOp, depthFailOp, compareOp);
}

inline VkResult CopyMemoryToImageEXT(const VkCopyMemoryToImageInfo& copyMemoryToImageInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyMemoryToImageEXT(DeviceContext::Device(), &copyMemoryToImageInfo);
}
DefineRaiiFunction_Result(VkResult, CopyMemoryToImageEXT, CopyMemoryToImageInfo);

inline VkResult CopyImageToMemoryEXT(const VkCopyImageToMemoryInfo& copyImageToMemoryInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyImageToMemoryEXT(DeviceContext::Device(), &copyImageToMemoryInfo);
}
DefineRaiiFunction_Result(VkResult, CopyImageToMemoryEXT, CopyImageToMemoryInfo);

inline VkResult CopyImageToImageEXT(const VkCopyImageToImageInfo& copyImageToImageInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyImageToImageEXT(DeviceContext::Device(), &copyImageToImageInfo);
}
DefineRaiiFunction_Result(VkResult, CopyImageToImageEXT, CopyImageToImageInfo);

inline VkResult TransitionImageLayoutEXT(ArrayRef<const VkHostImageLayoutTransitionInfo> transitions) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkTransitionImageLayoutEXT(DeviceContext::Device(), transitions.size(), transitions);
}
DefineRaiiFunction_Result(VkResult, TransitionImageLayoutEXT, HostImageLayoutTransitionInfo);

inline void GetImageSubresourceLayout2EXT(VkImage image, const VkImageSubresource2& subresource, VkSubresourceLayout2& layout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageSubresourceLayout2EXT(DeviceContext::Device(), image, &subresource, &layout);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMapMemoryPlacedFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceMapMemoryPlacedFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMapMemoryPlacedFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMapMemoryPlacedPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceMapMemoryPlacedPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMapMemoryPlacedPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryMapPlacedInfoEXT) {
	StructureClassHeader(MemoryMapPlacedInfoEXT);
	DefineSetter_Copy(PPlacedAddress, void*, pPlacedAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryMapPlacedInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderAtomicFloat2FeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderAtomicFloat2FeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderAtomicFloat2FeaturesEXT)

inline VkResult ReleaseSwapchainImagesEXT(const VkReleaseSwapchainImagesInfoKHR& releaseInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkReleaseSwapchainImagesEXT(DeviceContext::Device(), &releaseInfo);
}
DefineRaiiFunction_Result(VkResult, ReleaseSwapchainImagesEXT, ReleaseSwapchainImagesInfoKHR);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDeviceGeneratedCommandsPropertiesNV) {
	StructureClassHeader(PhysicalDeviceDeviceGeneratedCommandsPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDeviceGeneratedCommandsPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDeviceGeneratedCommandsFeaturesNV) {
	StructureClassHeader(PhysicalDeviceDeviceGeneratedCommandsFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDeviceGeneratedCommandsFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GraphicsShaderGroupCreateInfoNV) {
	StructureClassHeader(GraphicsShaderGroupCreateInfoNV);
	DefineSetter_Copy(StageCount, uint32_t, stageCount);
	DefineSetter_ArrayRef(Stages, const VkPipelineShaderStageCreateInfo, stages, stageCount);
	DefineSetter_Ref(VertexInputState, const VkPipelineVertexInputStateCreateInfo, vertexInputState);
	DefineSetter_Ref(TessellationState, const VkPipelineTessellationStateCreateInfo, tessellationState);
};
VK_ENCAPSULATION_STRUCTURE_END(GraphicsShaderGroupCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GraphicsPipelineShaderGroupsCreateInfoNV) {
	StructureClassHeader(GraphicsPipelineShaderGroupsCreateInfoNV);
	DefineSetter_Copy(GroupCount, uint32_t, groupCount);
	DefineSetter_ArrayRef(Groups, const VkGraphicsShaderGroupCreateInfoNV, groups, groupCount);
	DefineSetter_Copy(PipelineCount, uint32_t, pipelineCount);
	DefineSetter_ArrayRef(Pipelines, const VkPipeline, pipelines, pipelineCount);
};
VK_ENCAPSULATION_STRUCTURE_END(GraphicsPipelineShaderGroupsCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BindShaderGroupIndirectCommandNV) {
	StructureClassHeader_NoSType(BindShaderGroupIndirectCommandNV);
	DefineSetter_Copy(GroupIndex, uint32_t, groupIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(BindShaderGroupIndirectCommandNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BindIndexBufferIndirectCommandNV) {
	StructureClassHeader_NoSType(BindIndexBufferIndirectCommandNV);
	DefineSetter_Copy(BufferAddress, VkDeviceAddress, bufferAddress);
	DefineSetter_Copy(Size, uint32_t, size);
	DefineSetter_Copy(IndexType, VkIndexType, indexType);
};
VK_ENCAPSULATION_STRUCTURE_END(BindIndexBufferIndirectCommandNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BindVertexBufferIndirectCommandNV) {
	StructureClassHeader_NoSType(BindVertexBufferIndirectCommandNV);
	DefineSetter_Copy(BufferAddress, VkDeviceAddress, bufferAddress);
	DefineSetter_Copy(Size, uint32_t, size);
	DefineSetter_Copy(Stride, uint32_t, stride);
};
VK_ENCAPSULATION_STRUCTURE_END(BindVertexBufferIndirectCommandNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SetStateFlagsIndirectCommandNV) {
	StructureClassHeader_NoSType(SetStateFlagsIndirectCommandNV);
	DefineSetter_Copy(Data, uint32_t, data);
};
VK_ENCAPSULATION_STRUCTURE_END(SetStateFlagsIndirectCommandNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(IndirectCommandsStreamNV) {
	StructureClassHeader_NoSType(IndirectCommandsStreamNV);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsStreamNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectCommandsLayoutTokenNV) {
	StructureClassHeader(IndirectCommandsLayoutTokenNV);
	DefineSetter_Copy(TokenType, VkIndirectCommandsTokenTypeNV, tokenType);
	DefineSetter_Copy(Stream, uint32_t, stream);
	DefineSetter_Copy(Offset, uint32_t, offset);
	DefineSetter_Copy(VertexBindingUnit, uint32_t, vertexBindingUnit);
	DefineSetter_Copy(VertexDynamicStride, VkBool32, vertexDynamicStride);
	DefineSetter_Copy(PushconstantPipelineLayout, VkPipelineLayout, pushconstantPipelineLayout);
	DefineSetter_Copy(PushconstantShaderStageFlags, VkShaderStageFlags, pushconstantShaderStageFlags);
	DefineSetter_Copy(PushconstantOffset, uint32_t, pushconstantOffset);
	DefineSetter_Copy(PushconstantSize, uint32_t, pushconstantSize);
	DefineSetter_Copy(IndirectStateFlags, VkIndirectStateFlagsNV, indirectStateFlags);
	DefineSetter_Copy(IndexTypeCount, uint32_t, indexTypeCount);
	DefineSetter_ArrayRef(IndexTypes, const VkIndexType, indexTypes, indexTypeCount);
	DefineSetter_ArrayRefIgnoreC(IndexTypeValues, const uint32_t, indexTypeValues);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsLayoutTokenNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectCommandsLayoutCreateInfoNV) {
	StructureClassHeader(IndirectCommandsLayoutCreateInfoNV);
	DefineSetter_Copy(Flags, VkIndirectCommandsLayoutUsageFlagsNV, flags);
	DefineSetter_Copy(PipelineBindPoint, VkPipelineBindPoint, pipelineBindPoint);
	DefineSetter_Copy(TokenCount, uint32_t, tokenCount);
	DefineSetter_ArrayRef(Tokens, const VkIndirectCommandsLayoutTokenNV, tokens, tokenCount);
	DefineSetter_Copy(StreamCount, uint32_t, streamCount);
	DefineSetter_ArrayRef(StreamStrides, const uint32_t, streamStrides, streamCount);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsLayoutCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeneratedCommandsInfoNV) {
	StructureClassHeader(GeneratedCommandsInfoNV);
	DefineSetter_Copy(PipelineBindPoint, VkPipelineBindPoint, pipelineBindPoint);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
	DefineSetter_Copy(IndirectCommandsLayout, VkIndirectCommandsLayoutNV, indirectCommandsLayout);
	DefineSetter_Copy(StreamCount, uint32_t, streamCount);
	DefineSetter_ArrayRef(Streams, const VkIndirectCommandsStreamNV, streams, streamCount);
	DefineSetter_Copy(SequencesCount, uint32_t, sequencesCount);
	DefineSetter_Copy(PreprocessBuffer, VkBuffer, preprocessBuffer);
	DefineSetter_Copy(PreprocessOffset, VkDeviceSize, preprocessOffset);
	DefineSetter_Copy(PreprocessSize, VkDeviceSize, preprocessSize);
	DefineSetter_Copy(SequencesCountBuffer, VkBuffer, sequencesCountBuffer);
	DefineSetter_Copy(SequencesCountOffset, VkDeviceSize, sequencesCountOffset);
	DefineSetter_Copy(SequencesIndexBuffer, VkBuffer, sequencesIndexBuffer);
	DefineSetter_Copy(SequencesIndexOffset, VkDeviceSize, sequencesIndexOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(GeneratedCommandsInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeneratedCommandsMemoryRequirementsInfoNV) {
	StructureClassHeader(GeneratedCommandsMemoryRequirementsInfoNV);
	DefineSetter_Copy(PipelineBindPoint, VkPipelineBindPoint, pipelineBindPoint);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
	DefineSetter_Copy(IndirectCommandsLayout, VkIndirectCommandsLayoutNV, indirectCommandsLayout);
	DefineSetter_Copy(MaxSequencesCount, uint32_t, maxSequencesCount);
};
VK_ENCAPSULATION_STRUCTURE_END(GeneratedCommandsMemoryRequirementsInfoNV)

inline void GetGeneratedCommandsMemoryRequirementsNV(const VkGeneratedCommandsMemoryRequirementsInfoNV& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetGeneratedCommandsMemoryRequirementsNV(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetGeneratedCommandsMemoryRequirementsNV, GeneratedCommandsMemoryRequirementsInfoNV, VkMemoryRequirements2&, memoryRequirements);

inline void CmdPreprocessGeneratedCommandsNV(const VkGeneratedCommandsInfoNV& generatedCommandsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPreprocessGeneratedCommandsNV(ThreadContext::CommandBuffer(), &generatedCommandsInfo);
}
DefineRaiiFunction(CmdPreprocessGeneratedCommandsNV, GeneratedCommandsInfoNV);

inline void CmdExecuteGeneratedCommandsNV(VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV& generatedCommandsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdExecuteGeneratedCommandsNV(ThreadContext::CommandBuffer(), isPreprocessed, &generatedCommandsInfo);
}
DefineRaiiFunction_R(CmdExecuteGeneratedCommandsNV, VkBool32, isPreprocessed, GeneratedCommandsInfoNV);

inline void CmdBindPipelineShaderGroupNV(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindPipelineShaderGroupNV(ThreadContext::CommandBuffer(), pipelineBindPoint, pipeline, groupIndex);
}

inline VkResult CreateIndirectCommandsLayoutNV(const VkIndirectCommandsLayoutCreateInfoNV& createInfo, HandleRef<VkIndirectCommandsLayoutNV> indirectCommandsLayout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateIndirectCommandsLayoutNV(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &indirectCommandsLayout);
}
DefineRaiiFunction_ResultL(VkResult, CreateIndirectCommandsLayoutNV, IndirectCommandsLayoutCreateInfoNV, HandleRef<VkIndirectCommandsLayoutNV>, indirectCommandsLayout);

inline void DestroyIndirectCommandsLayoutNV(HandleRef<VkIndirectCommandsLayoutNV> indirectCommandsLayout, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyIndirectCommandsLayoutNV(DeviceContext::Device(), indirectCommandsLayout, &allocator);
	indirectCommandsLayout = VK_NULL_HANDLE;
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceInheritedViewportScissorFeaturesNV) {
	StructureClassHeader(PhysicalDeviceInheritedViewportScissorFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceInheritedViewportScissorFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferInheritanceViewportScissorInfoNV) {
	StructureClassHeader(CommandBufferInheritanceViewportScissorInfoNV);
	DefineSetter_Copy(ViewportScissor2D, VkBool32, viewportScissor2D);
	DefineSetter_ArrayRef(ViewportDepths, const VkViewport, viewportDepths, viewportDepthCount, viewportScissor2D = bool(viewportDepths));
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferInheritanceViewportScissorInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTexelBufferAlignmentFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceTexelBufferAlignmentFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTexelBufferAlignmentFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassTransformBeginInfoQCOM) {
	StructureClassHeader(RenderPassTransformBeginInfoQCOM);
	DefineSetter_Copy(Transform, VkSurfaceTransformFlagBitsKHR, transform);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassTransformBeginInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CommandBufferInheritanceRenderPassTransformInfoQCOM) {
	StructureClassHeader(CommandBufferInheritanceRenderPassTransformInfoQCOM);
	DefineSetter_Copy(Transform, VkSurfaceTransformFlagBitsKHR, transform);
	DefineSetter_Copy(RenderArea, VkRect2D, renderArea);
};
VK_ENCAPSULATION_STRUCTURE_END(CommandBufferInheritanceRenderPassTransformInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDepthBiasControlFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDepthBiasControlFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDepthBiasControlFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DepthBiasInfoEXT) {
	StructureClassHeader(DepthBiasInfoEXT);
	DefineSetter_Copy(DepthBiasConstantFactor, float, depthBiasConstantFactor);
	DefineSetter_Copy(DepthBiasClamp, float, depthBiasClamp);
	DefineSetter_Copy(DepthBiasSlopeFactor, float, depthBiasSlopeFactor);
};
VK_ENCAPSULATION_STRUCTURE_END(DepthBiasInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DepthBiasRepresentationInfoEXT) {
	StructureClassHeader(DepthBiasRepresentationInfoEXT);
	DefineSetter_Copy(DepthBiasRepresentation, VkDepthBiasRepresentationEXT, depthBiasRepresentation);
	DefineSetter_Copy(DepthBiasExact, VkBool32, depthBiasExact);
};
VK_ENCAPSULATION_STRUCTURE_END(DepthBiasRepresentationInfoEXT)

inline void CmdSetDepthBias2EXT(const VkDepthBiasInfoEXT& depthBiasInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthBias2EXT(ThreadContext::CommandBuffer(), &depthBiasInfo);
}
DefineRaiiFunction(CmdSetDepthBias2EXT, DepthBiasInfoEXT);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDeviceMemoryReportFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDeviceMemoryReportFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDeviceMemoryReportFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceMemoryReportCallbackDataEXT) {
	StructureClassHeader(DeviceMemoryReportCallbackDataEXT);
	DefineSetter_Copy(Flags, VkDeviceMemoryReportFlagsEXT, flags);
	DefineSetter_Copy(Type, VkDeviceMemoryReportEventTypeEXT, type);
	DefineSetter_Copy(MemoryObjectId, uint64_t, memoryObjectId);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(ObjectType, VkObjectType, objectType);
	DefineSetter_Copy(ObjectHandle, uint64_t, objectHandle);
	DefineSetter_Copy(HeapIndex, uint32_t, heapIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceMemoryReportCallbackDataEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceDeviceMemoryReportCreateInfoEXT) {
	StructureClassHeader(DeviceDeviceMemoryReportCreateInfoEXT);
	DefineSetter_Copy(Flags, VkDeviceMemoryReportFlagsEXT, flags);
	DefineSetter_Copy(FnUserCallback, PFN_vkDeviceMemoryReportCallbackEXT, pfnUserCallback);
	DefineSetter_PointerAndRef(UserData, void, userData);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceDeviceMemoryReportCreateInfoEXT)

inline VkResult AcquireDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkAcquireDrmDisplayEXT(physicalDevice, drmFd, display);
}
inline VkResult AcquireDrmDisplayEXT(int32_t drmFd, VkDisplayKHR display) {
	return AcquireDrmDisplayEXT(DeviceContext::PhysicalDevice(), drmFd, display);
}

inline VkResult GetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, HandleRef<VkDisplayKHR> display) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetDrmDisplayEXT(physicalDevice, drmFd, connectorId, &display);
}
inline VkResult GetDrmDisplayEXT(int32_t drmFd, uint32_t connectorId, HandleRef<VkDisplayKHR> display) {
	return GetDrmDisplayEXT(DeviceContext::PhysicalDevice(), drmFd, connectorId, display);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerCustomBorderColorCreateInfoEXT) {
	StructureClassHeader(SamplerCustomBorderColorCreateInfoEXT);
	DefineSetter_Copy(CustomBorderColor, VkClearColorValue, customBorderColor);
	DefineSetter_Copy(Format, VkFormat, format);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerCustomBorderColorCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCustomBorderColorPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceCustomBorderColorPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCustomBorderColorPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCustomBorderColorFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceCustomBorderColorFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCustomBorderColorFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePresentBarrierFeaturesNV) {
	StructureClassHeader(PhysicalDevicePresentBarrierFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePresentBarrierFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SurfaceCapabilitiesPresentBarrierNV) {
	StructureClassHeader(SurfaceCapabilitiesPresentBarrierNV);
};
VK_ENCAPSULATION_STRUCTURE_END(SurfaceCapabilitiesPresentBarrierNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainPresentBarrierCreateInfoNV) {
	StructureClassHeader(SwapchainPresentBarrierCreateInfoNV);
	DefineSetter_Copy(PresentBarrierEnable, VkBool32, presentBarrierEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainPresentBarrierCreateInfoNV)

inline VkResult CreatePrivateDataSlotEXT(const VkPrivateDataSlotCreateInfo& createInfo, HandleRef<VkPrivateDataSlot> privateDataSlot) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreatePrivateDataSlotEXT(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &privateDataSlot);
}
DefineRaiiFunction_ResultL(VkResult, CreatePrivateDataSlotEXT, PrivateDataSlotCreateInfo, HandleRef<VkPrivateDataSlot>, privateDataSlot);

inline void DestroyPrivateDataSlotEXT(HandleRef<VkPrivateDataSlot> privateDataSlot, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyPrivateDataSlotEXT(DeviceContext::Device(), privateDataSlot, &allocator);
	privateDataSlot = VK_NULL_HANDLE;
}

inline VkResult SetPrivateDataEXT(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkSetPrivateDataEXT(DeviceContext::Device(), objectType, objectHandle, privateDataSlot, data);
}

inline void GetPrivateDataEXT(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t& data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPrivateDataEXT(DeviceContext::Device(), objectType, objectHandle, privateDataSlot, &data);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDiagnosticsConfigFeaturesNV) {
	StructureClassHeader(PhysicalDeviceDiagnosticsConfigFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDiagnosticsConfigFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceDiagnosticsConfigCreateInfoNV) {
	StructureClassHeader(DeviceDiagnosticsConfigCreateInfoNV);
	DefineSetter_Copy(Flags, VkDeviceDiagnosticsConfigFlagsNV, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceDiagnosticsConfigCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTileShadingFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceTileShadingFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTileShadingFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTileShadingPropertiesQCOM) {
	StructureClassHeader(PhysicalDeviceTileShadingPropertiesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTileShadingPropertiesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassTileShadingCreateInfoQCOM) {
	StructureClassHeader(RenderPassTileShadingCreateInfoQCOM);
	DefineSetter_Copy(Flags, VkTileShadingRenderPassFlagsQCOM, flags);
	DefineSetter_Copy(TileApronSize, VkExtent2D, tileApronSize);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassTileShadingCreateInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerTileBeginInfoQCOM) {
	StructureClassHeader(PerTileBeginInfoQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PerTileBeginInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PerTileEndInfoQCOM) {
	StructureClassHeader(PerTileEndInfoQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PerTileEndInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DispatchTileInfoQCOM) {
	StructureClassHeader(DispatchTileInfoQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(DispatchTileInfoQCOM)

inline void CmdDispatchTileQCOM(const VkDispatchTileInfoQCOM& dispatchTileInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDispatchTileQCOM(ThreadContext::CommandBuffer(), &dispatchTileInfo);
}
DefineRaiiFunction(CmdDispatchTileQCOM, DispatchTileInfoQCOM);

inline void CmdBeginPerTileExecutionQCOM(const VkPerTileBeginInfoQCOM& perTileBeginInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBeginPerTileExecutionQCOM(ThreadContext::CommandBuffer(), &perTileBeginInfo);
}
DefineRaiiFunction(CmdBeginPerTileExecutionQCOM, PerTileBeginInfoQCOM);

inline void CmdEndPerTileExecutionQCOM(const VkPerTileEndInfoQCOM& perTileEndInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndPerTileExecutionQCOM(ThreadContext::CommandBuffer(), &perTileEndInfo);
}
DefineRaiiFunction(CmdEndPerTileExecutionQCOM, PerTileEndInfoQCOM);

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueryLowLatencySupportNV) {
	StructureClassHeader(QueryLowLatencySupportNV);
	// void* pQueriedLowLatencyData;
};
VK_ENCAPSULATION_STRUCTURE_END(QueryLowLatencySupportNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorBufferPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceDescriptorBufferPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorBufferPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorBufferFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDescriptorBufferFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorBufferFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorAddressInfoEXT) {
	StructureClassHeader(DescriptorAddressInfoEXT, .range = VK_WHOLE_SIZE);
	DefineSetter_Copy(Address, VkDeviceAddress, address);
	DefineSetter_Copy(Range, VkDeviceSize, range);
	DefineSetter_Copy(Format, VkFormat, format);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorAddressInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorBufferBindingInfoEXT) {
	StructureClassHeader(DescriptorBufferBindingInfoEXT);
	DefineSetter_Copy(Address, VkDeviceAddress, address);
	DefineSetter_Copy(Usage, VkBufferUsageFlags, usage);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorBufferBindingInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorBufferBindingPushDescriptorBufferHandleEXT) {
	StructureClassHeader(DescriptorBufferBindingPushDescriptorBufferHandleEXT);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorBufferBindingPushDescriptorBufferHandleEXT)


VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(DescriptorDataEXT) {
	StructureClassHeader_UnionWrapper(DescriptorDataEXT);
	union {
		const VkSampler*                  pSampler;
		const VkDescriptorImageInfo*      pCombinedImageSampler;
		const VkDescriptorImageInfo*      pInputAttachmentImage;
		const VkDescriptorImageInfo*      pSampledImage;
		const VkDescriptorImageInfo*      pStorageImage;
		const VkDescriptorAddressInfoEXT* pUniformTexelBuffer;
		const VkDescriptorAddressInfoEXT* pStorageTexelBuffer;
		const VkDescriptorAddressInfoEXT* pUniformBuffer;
		const VkDescriptorAddressInfoEXT* pStorageBuffer;
		VkDeviceAddress                   accelerationStructure;
	};
	Structure(OptionalRef<const VkSampler> sampler) : pSampler(&sampler) {}
	Structure(OptionalRef<const VkDescriptorImageInfo> image) : pCombinedImageSampler(&image) {}
	Structure(OptionalRef<const VkDescriptorAddressInfoEXT> buffer) : pUniformTexelBuffer(&buffer) {}
	Structure(VkDeviceAddress accelerationStructure) : accelerationStructure(accelerationStructure) {}
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorDataEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorGetInfoEXT) {
	StructureClassHeader(DescriptorGetInfoEXT);
	DefineSetter_Copy(Type, VkDescriptorType, type);
	DefineSetter_Copy(Data, VkDescriptorDataEXT, data);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorGetInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BufferCaptureDescriptorDataInfoEXT) {
	StructureClassHeader(BufferCaptureDescriptorDataInfoEXT);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
};
VK_ENCAPSULATION_STRUCTURE_END(BufferCaptureDescriptorDataInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageCaptureDescriptorDataInfoEXT) {
	StructureClassHeader(ImageCaptureDescriptorDataInfoEXT);
	DefineSetter_Copy(Image, VkImage, image);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageCaptureDescriptorDataInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewCaptureDescriptorDataInfoEXT) {
	StructureClassHeader(ImageViewCaptureDescriptorDataInfoEXT);
	DefineSetter_Copy(ImageView, VkImageView, imageView);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewCaptureDescriptorDataInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerCaptureDescriptorDataInfoEXT) {
	StructureClassHeader(SamplerCaptureDescriptorDataInfoEXT);
	DefineSetter_Copy(Sampler, VkSampler, sampler);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerCaptureDescriptorDataInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(OpaqueCaptureDescriptorDataCreateInfoEXT) {
	StructureClassHeader(OpaqueCaptureDescriptorDataCreateInfoEXT);
	DefineSetter_Copy(OpaqueCaptureDescriptorData, ArrayRef<const void>, opaqueCaptureDescriptorData);
	_&  OpaqueCaptureDescriptorData(const IsNotRangeOrPointer auto& opaqueCaptureDescriptorData) &  { this->opaqueCaptureDescriptorData = &opaqueCaptureDescriptorData; return *this; }
	_&& OpaqueCaptureDescriptorData(const IsNotRangeOrPointer auto& opaqueCaptureDescriptorData) && { return std::move(OpaqueCaptureDescriptorData(opaqueCaptureDescriptorData)); }
	_&  OpaqueCaptureDescriptorData(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(OpaqueCaptureDescriptorDataCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureCaptureDescriptorDataInfoEXT) {
	StructureClassHeader(AccelerationStructureCaptureDescriptorDataInfoEXT);
	DefineSetter_Copy(AccelerationStructure, VkAccelerationStructureKHR, accelerationStructure);
	DefineSetter_Copy(AccelerationStructureNV, VkAccelerationStructureNV, accelerationStructureNV);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureCaptureDescriptorDataInfoEXT)

inline void GetDescriptorSetLayoutSizeEXT(VkDescriptorSetLayout layout, VkDeviceSize& layoutSizeInBytes) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDescriptorSetLayoutSizeEXT(DeviceContext::Device(), layout, &layoutSizeInBytes);
}

inline void GetDescriptorSetLayoutBindingOffsetEXT(VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize& offset) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDescriptorSetLayoutBindingOffsetEXT(DeviceContext::Device(), layout, binding, &offset);
}

inline void GetDescriptorEXT(const VkDescriptorGetInfoEXT& descriptorInfo, ArrayRef<void> descriptor) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDescriptorEXT(DeviceContext::Device(), &descriptorInfo, descriptor.size(), descriptor);
}
DefineRaiiFunction_L(GetDescriptorEXT, DescriptorGetInfoEXT, ArrayRef<void>, descriptor);
inline void GetDescriptorEXT(const VkDescriptorGetInfoEXT& descriptorInfo, IsNotRangeOrPointer auto& descriptor) {
	GetDescriptorEXT(descriptorInfo, { sizeof *&descriptor, &descriptor });
}
DefineRaiiFunction_L(GetDescriptorEXT, DescriptorGetInfoEXT, IsNotRangeOrPointer auto&, descriptor);

inline void CmdBindDescriptorBuffersEXT(ArrayRef<const VkDescriptorBufferBindingInfoEXT> bindingInfos) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindDescriptorBuffersEXT(ThreadContext::CommandBuffer(), bindingInfos.size(), bindingInfos);
}
DefineRaiiFunction(CmdBindDescriptorBuffersEXT, DescriptorBufferBindingInfoEXT);

inline void CmdSetDescriptorBufferOffsetsEXT(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, ArrayRef<const uint32_t> bufferIndices, ArrayRef<const VkDeviceSize> offsets) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDescriptorBufferOffsetsEXT(ThreadContext::CommandBuffer(), pipelineBindPoint, layout, firstSet, bufferIndices.size(), bufferIndices, offsets);
}

inline void CmdBindDescriptorBufferEmbeddedSamplersEXT(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindDescriptorBufferEmbeddedSamplersEXT(ThreadContext::CommandBuffer(), pipelineBindPoint, layout, set);
}

inline VkResult GetBufferOpaqueCaptureDescriptorDataEXT(const VkBufferCaptureDescriptorDataInfoEXT& info, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetBufferOpaqueCaptureDescriptorDataEXT(DeviceContext::Device(), &info, data);
}
DefineRaiiFunction_ResultL(VkResult, GetBufferOpaqueCaptureDescriptorDataEXT, BufferCaptureDescriptorDataInfoEXT, ArrayRef<void>, data);
inline VkResult GetBufferOpaqueCaptureDescriptorDataEXT(const VkBufferCaptureDescriptorDataInfoEXT& info, IsNotRangeOrPointer auto& data) {
	return GetBufferOpaqueCaptureDescriptorDataEXT(info, { 0, &data });
}
DefineRaiiFunction_ResultL(VkResult, GetBufferOpaqueCaptureDescriptorDataEXT, BufferCaptureDescriptorDataInfoEXT, IsNotRangeOrPointer auto&, data);

inline VkResult GetImageOpaqueCaptureDescriptorDataEXT(const VkImageCaptureDescriptorDataInfoEXT& info, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageOpaqueCaptureDescriptorDataEXT(DeviceContext::Device(), &info, data);
}
DefineRaiiFunction_ResultL(VkResult, GetImageOpaqueCaptureDescriptorDataEXT, ImageCaptureDescriptorDataInfoEXT, ArrayRef<void>, data);
inline VkResult GetImageOpaqueCaptureDescriptorDataEXT(const VkImageCaptureDescriptorDataInfoEXT& info, IsNotRangeOrPointer auto& data) {
	return GetImageOpaqueCaptureDescriptorDataEXT(info, { 0, &data });
}
DefineRaiiFunction_ResultL(VkResult, GetImageOpaqueCaptureDescriptorDataEXT, ImageCaptureDescriptorDataInfoEXT, IsNotRangeOrPointer auto&, data);

inline VkResult GetImageViewOpaqueCaptureDescriptorDataEXT(const VkImageViewCaptureDescriptorDataInfoEXT& info, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetImageViewOpaqueCaptureDescriptorDataEXT(DeviceContext::Device(), &info, data);
}
DefineRaiiFunction_ResultL(VkResult, GetImageViewOpaqueCaptureDescriptorDataEXT, ImageViewCaptureDescriptorDataInfoEXT, ArrayRef<void>, data);
inline VkResult GetImageViewOpaqueCaptureDescriptorDataEXT(const VkImageViewCaptureDescriptorDataInfoEXT& info, IsNotRangeOrPointer auto& data) {
	return GetImageViewOpaqueCaptureDescriptorDataEXT(info, { 0, &data });
}
DefineRaiiFunction_ResultL(VkResult, GetImageViewOpaqueCaptureDescriptorDataEXT, ImageViewCaptureDescriptorDataInfoEXT, IsNotRangeOrPointer auto&, data);

inline VkResult GetSamplerOpaqueCaptureDescriptorDataEXT(const VkSamplerCaptureDescriptorDataInfoEXT& info, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetSamplerOpaqueCaptureDescriptorDataEXT(DeviceContext::Device(), &info, data);
}
DefineRaiiFunction_ResultL(VkResult, GetSamplerOpaqueCaptureDescriptorDataEXT, SamplerCaptureDescriptorDataInfoEXT, ArrayRef<void>, data);
inline VkResult GetSamplerOpaqueCaptureDescriptorDataEXT(const VkSamplerCaptureDescriptorDataInfoEXT& info, IsNotRangeOrPointer auto& data) {
	return GetSamplerOpaqueCaptureDescriptorDataEXT(info, { 0, &data });
}
DefineRaiiFunction_ResultL(VkResult, GetSamplerOpaqueCaptureDescriptorDataEXT, SamplerCaptureDescriptorDataInfoEXT, IsNotRangeOrPointer auto&, data);

inline VkResult GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(const VkAccelerationStructureCaptureDescriptorDataInfoEXT& info, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(DeviceContext::Device(), &info, data);
}
DefineRaiiFunction_ResultL(VkResult, GetAccelerationStructureOpaqueCaptureDescriptorDataEXT, AccelerationStructureCaptureDescriptorDataInfoEXT, ArrayRef<void>, data);
inline VkResult GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(const VkAccelerationStructureCaptureDescriptorDataInfoEXT& info, IsNotRangeOrPointer auto& data) {
	return GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(info, { 0, &data });
}
DefineRaiiFunction_ResultL(VkResult, GetAccelerationStructureOpaqueCaptureDescriptorDataEXT, AccelerationStructureCaptureDescriptorDataInfoEXT, IsNotRangeOrPointer auto&, data);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GraphicsPipelineLibraryCreateInfoEXT) {
	StructureClassHeader(GraphicsPipelineLibraryCreateInfoEXT);
	DefineSetter_Copy(Flags, VkGraphicsPipelineLibraryFlagsEXT, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(GraphicsPipelineLibraryCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD) {
	StructureClassHeader(PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShadingRateEnumsFeaturesNV) {
	StructureClassHeader(PhysicalDeviceFragmentShadingRateEnumsFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShadingRateEnumsFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentShadingRateEnumsPropertiesNV) {
	StructureClassHeader(PhysicalDeviceFragmentShadingRateEnumsPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentShadingRateEnumsPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineFragmentShadingRateEnumStateCreateInfoNV) {
	StructureClassHeader(PipelineFragmentShadingRateEnumStateCreateInfoNV);
	DefineSetter_Copy(ShadingRateType, VkFragmentShadingRateTypeNV, shadingRateType);
	DefineSetter_Copy(ShadingRate, VkFragmentShadingRateNV, shadingRate);
	// VkFragmentShadingRateCombinerOpKHR combinerOps[2];
	DefineSetter_ArrayCopy(CombinerOps, VkFragmentShadingRateCombinerOpKHR, combinerOps);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineFragmentShadingRateEnumStateCreateInfoNV)

inline void CmdSetFragmentShadingRateEnumNV(VkFragmentShadingRateNV shadingRate, ArrayRef<const VkFragmentShadingRateCombinerOpKHR> combinerOps) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetFragmentShadingRateEnumNV(ThreadContext::CommandBuffer(), shadingRate, combinerOps);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(DeviceOrHostAddressConstKHR) {
	StructureClassHeader_UnionWrapper(DeviceOrHostAddressConstKHR);
	union {
		VkDeviceAddress deviceAddress;
		const void*     hostAddress;
	};
	Structure(VkDeviceAddress deviceAddress) : deviceAddress(deviceAddress) {}
	Structure(const void* hostAddress) : hostAddress(hostAddress) {}
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceOrHostAddressConstKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureGeometryMotionTrianglesDataNV) {
	StructureClassHeader(AccelerationStructureGeometryMotionTrianglesDataNV);
	DefineSetter_Copy(VertexData, VkDeviceOrHostAddressConstKHR, vertexData);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometryMotionTrianglesDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureMotionInfoNV) {
	StructureClassHeader(AccelerationStructureMotionInfoNV);
	DefineSetter_Copy(MaxInstances, uint32_t, maxInstances);
	DefineSetter_Copy(Flags, VkAccelerationStructureMotionInfoFlagsNV, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureMotionInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AccelerationStructureMatrixMotionInstanceNV) {
	StructureClassHeader_NoSType(AccelerationStructureMatrixMotionInstanceNV);
	DefineSetter_Copy(TransformT0, VkTransformMatrixKHR, transformT0);
	DefineSetter_Copy(TransformT1, VkTransformMatrixKHR, transformT1);
	DefineSetter_Copy(InstanceCustomIndex, uint32_t, instanceCustomIndex);
	DefineSetter_Copy(Mask, uint32_t, mask);
	DefineSetter_Copy(InstanceShaderBindingTableRecordOffset, uint32_t, instanceShaderBindingTableRecordOffset);
	DefineSetter_Copy(Flags, VkGeometryInstanceFlagsKHR, flags);
	DefineSetter_Copy(AccelerationStructureReference, uint64_t, accelerationStructureReference);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureMatrixMotionInstanceNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(SRTDataNV) {
	StructureClassHeader_NoSType(SRTDataNV);
	DefineSetter_Copy(Sx, float, sx);
	DefineSetter_Copy(A, float, a);
	DefineSetter_Copy(B, float, b);
	DefineSetter_Copy(Pvx, float, pvx);
	DefineSetter_Copy(Sy, float, sy);
	DefineSetter_Copy(C, float, c);
	DefineSetter_Copy(Pvy, float, pvy);
	DefineSetter_Copy(Sz, float, sz);
	DefineSetter_Copy(Pvz, float, pvz);
	DefineSetter_Copy(Qx, float, qx);
	DefineSetter_Copy(Qy, float, qy);
	DefineSetter_Copy(Qz, float, qz);
	DefineSetter_Copy(Qw, float, qw);
	DefineSetter_Copy(Tx, float, tx);
	DefineSetter_Copy(Ty, float, ty);
	DefineSetter_Copy(Tz, float, tz);
};
VK_ENCAPSULATION_STRUCTURE_END(SRTDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AccelerationStructureSRTMotionInstanceNV) {
	StructureClassHeader_NoSType(AccelerationStructureSRTMotionInstanceNV);
	DefineSetter_Copy(TransformT0, VkSRTDataNV, transformT0);
	DefineSetter_Copy(TransformT1, VkSRTDataNV, transformT1);
	DefineSetter_Copy(InstanceCustomIndex, uint32_t, instanceCustomIndex);
	DefineSetter_Copy(Mask, uint32_t, mask);
	DefineSetter_Copy(InstanceShaderBindingTableRecordOffset, uint32_t, instanceShaderBindingTableRecordOffset);
	DefineSetter_Copy(Flags, VkGeometryInstanceFlagsKHR, flags);
	DefineSetter_Copy(AccelerationStructureReference, uint64_t, accelerationStructureReference);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureSRTMotionInstanceNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(AccelerationStructureMotionInstanceDataNV) {
	StructureClassHeader_UnionWrapper(AccelerationStructureMotionInstanceDataNV);
	union {
		VkAccelerationStructureInstanceKHR            staticInstance;
		VkAccelerationStructureMatrixMotionInstanceNV matrixMotionInstance;
		VkAccelerationStructureSRTMotionInstanceNV    srtMotionInstance;
	};
	Structure(const VkAccelerationStructureInstanceKHR& staticInstance) : staticInstance(staticInstance) {}
	Structure(const VkAccelerationStructureMatrixMotionInstanceNV& matrixMotionInstance) : matrixMotionInstance(matrixMotionInstance) {}
	Structure(const VkAccelerationStructureSRTMotionInstanceNV& srtMotionInstance) : srtMotionInstance(srtMotionInstance) {}
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureMotionInstanceDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AccelerationStructureMotionInstanceNV) {
	StructureClassHeader_NoSType(AccelerationStructureMotionInstanceNV);
	DefineSetter_Copy(Type, VkAccelerationStructureMotionInstanceTypeNV, type);
	DefineSetter_Copy(Flags, VkAccelerationStructureMotionInstanceFlagsNV, flags);
	DefineSetter_Copy(Data, VkAccelerationStructureMotionInstanceDataNV, data);
	struct { uint8_t bytes[8]; } padding = {}; // VkAccelerationStructureMotionInstanceNV must have a stride of 160 bytes.
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureMotionInstanceNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingMotionBlurFeaturesNV) {
	StructureClassHeader(PhysicalDeviceRayTracingMotionBlurFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingMotionBlurFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMap2FeaturesEXT) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMap2FeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMap2FeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMap2PropertiesEXT) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMap2PropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMap2PropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyCommandTransformInfoQCOM) {
	StructureClassHeader(CopyCommandTransformInfoQCOM);
	DefineSetter_Copy(Transform, VkSurfaceTransformFlagBitsKHR, transform);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyCommandTransformInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageCompressionControlFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceImageCompressionControlFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageCompressionControlFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageCompressionControlEXT) {
	StructureClassHeader(ImageCompressionControlEXT);
	DefineSetter_Copy(Flags, VkImageCompressionFlagsEXT, flags);
	DefineSetter_Copy(CompressionControlPlaneCount, uint32_t, compressionControlPlaneCount);
	DefineSetter_ArrayRef(FixedRateFlags, VkImageCompressionFixedRateFlagsEXT, fixedRateFlags, compressionControlPlaneCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageCompressionControlEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageCompressionPropertiesEXT) {
	StructureClassHeader(ImageCompressionPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageCompressionPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevice4444FormatsFeaturesEXT) {
	StructureClassHeader(PhysicalDevice4444FormatsFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevice4444FormatsFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFaultFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceFaultFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFaultFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceFaultCountsEXT) {
	StructureClassHeader(DeviceFaultCountsEXT);
	DefineSetter_Copy(AddressInfoCount, uint32_t, addressInfoCount);
	DefineSetter_Copy(VendorInfoCount, uint32_t, vendorInfoCount);
	DefineSetter_Copy(VendorBinarySize, VkDeviceSize, vendorBinarySize);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceFaultCountsEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DeviceFaultAddressInfoEXT) {
	StructureClassHeader_NoSType(DeviceFaultAddressInfoEXT);
	DefineSetter_Copy(AddressType, VkDeviceFaultAddressTypeEXT, addressType);
	DefineSetter_Copy(ReportedAddress, VkDeviceAddress, reportedAddress);
	DefineSetter_Copy(AddressPrecision, VkDeviceSize, addressPrecision);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceFaultAddressInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DeviceFaultVendorInfoEXT) {
	StructureClassHeader_NoSType(DeviceFaultVendorInfoEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceFaultVendorInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceFaultInfoEXT) {
	StructureClassHeader(DeviceFaultInfoEXT);
	DefineSetter_ArrayRefIgnoreC(AddressInfos, VkDeviceFaultAddressInfoEXT, addressInfos);
	DefineSetter_ArrayRefIgnoreC(VendorInfos, VkDeviceFaultVendorInfoEXT, vendorInfos);
	DefineSetter_ArrayRefIgnoreC(VendorBinaryData, void, vendorBinaryData);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceFaultInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DeviceFaultVendorBinaryHeaderVersionOneEXT) {
	StructureClassHeader_NoSType(DeviceFaultVendorBinaryHeaderVersionOneEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceFaultVendorBinaryHeaderVersionOneEXT)

inline VkResult GetDeviceFaultInfoEXT(VkDeviceFaultCountsEXT& faultCounts, OptionalRef<VkDeviceFaultInfoEXT> faultInfo = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceFaultInfoEXT(DeviceContext::Device(), &faultCounts, &faultInfo);
}
inline VkResult GetDeviceFaultInfoEXT(VkDeviceFaultInfoEXT& faultInfo, IsDynamicArray<VkDeviceFaultAddressInfoEXT> auto& addressInfos, IsDynamicArray<VkDeviceFaultVendorInfoEXT> auto& vendorInfos, IsDynamicByteArray auto& vendorBinaryData) {
	VkDeviceFaultCountsEXT faultCounts;
	VkResult result = GetDeviceFaultInfoEXT(faultCounts);
	if (result == VK_SUCCESS)
		addressInfos.resize(faultCounts.addressInfoCount),
		vendorInfos.resize(faultCounts.vendorInfoCount),
		vendorBinaryData.resize(faultCounts.vendorBinarySize),
		faultInfo.pAddressInfos = std::ranges::data(addressInfos),
		faultInfo.pVendorInfos = std::ranges::data(vendorInfos),
		faultInfo.pVendorBinaryData = std::ranges::data(vendorBinaryData),
		result = GetDeviceFaultInfoEXT(faultCounts, faultInfo);
	return result;
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRGBA10X6FormatsFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceRGBA10X6FormatsFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRGBA10X6FormatsFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMutableDescriptorTypeFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceMutableDescriptorTypeFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMutableDescriptorTypeFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MutableDescriptorTypeListEXT) {
	StructureClassHeader_NoSType(MutableDescriptorTypeListEXT);
	DefineSetter_Copy(DescriptorTypeCount, uint32_t, descriptorTypeCount);
	DefineSetter_ArrayRef(DescriptorTypes, const VkDescriptorType, descriptorTypes, descriptorTypeCount);
};
VK_ENCAPSULATION_STRUCTURE_END(MutableDescriptorTypeListEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MutableDescriptorTypeCreateInfoEXT) {
	StructureClassHeader(MutableDescriptorTypeCreateInfoEXT);
	DefineSetter_Copy(MutableDescriptorTypeListCount, uint32_t, mutableDescriptorTypeListCount);
	DefineSetter_ArrayRef(MutableDescriptorTypeLists, const VkMutableDescriptorTypeListEXT, mutableDescriptorTypeLists, mutableDescriptorTypeListCount);
};
VK_ENCAPSULATION_STRUCTURE_END(MutableDescriptorTypeCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVertexInputDynamicStateFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceVertexInputDynamicStateFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVertexInputDynamicStateFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VertexInputBindingDescription2EXT) {
	StructureClassHeader(VertexInputBindingDescription2EXT);
	DefineSetter_Copy(Binding, uint32_t, binding);
	DefineSetter_Copy(Stride, uint32_t, stride);
	DefineSetter_Copy(InputRate, VkVertexInputRate, inputRate);
	DefineSetter_Copy(Divisor, uint32_t, divisor);
};
VK_ENCAPSULATION_STRUCTURE_END(VertexInputBindingDescription2EXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VertexInputAttributeDescription2EXT) {
	StructureClassHeader(VertexInputAttributeDescription2EXT);
	DefineSetter_Copy(Location, uint32_t, location);
	DefineSetter_Copy(Binding, uint32_t, binding);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(Offset, uint32_t, offset);
};
VK_ENCAPSULATION_STRUCTURE_END(VertexInputAttributeDescription2EXT)

inline void CmdSetVertexInputEXT(ArrayRef<const VkVertexInputBindingDescription2EXT> vertexBindingDescriptions, ArrayRef<const VkVertexInputAttributeDescription2EXT> vertexAttributeDescriptions) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetVertexInputEXT(ThreadContext::CommandBuffer(), vertexBindingDescriptions.size(), vertexBindingDescriptions, vertexAttributeDescriptions.size(), vertexAttributeDescriptions);
}
DefineRaiiFunction_L(CmdSetVertexInputEXT, VertexInputBindingDescription2EXT, ArrayRef<const VkVertexInputAttributeDescription2EXT>, vertexAttributeDescriptions);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDrmPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceDrmPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDrmPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceAddressBindingReportFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceAddressBindingReportFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceAddressBindingReportFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceAddressBindingCallbackDataEXT) {
	StructureClassHeader(DeviceAddressBindingCallbackDataEXT);
	DefineSetter_Copy(Flags, VkDeviceAddressBindingFlagsEXT, flags);
	DefineSetter_Copy(BaseAddress, VkDeviceAddress, baseAddress);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(BindingType, VkDeviceAddressBindingTypeEXT, bindingType);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceAddressBindingCallbackDataEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDepthClipControlFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDepthClipControlFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDepthClipControlFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportDepthClipControlCreateInfoEXT) {
	StructureClassHeader(PipelineViewportDepthClipControlCreateInfoEXT);
	DefineSetter_Copy(NegativeOneToOne, VkBool32, negativeOneToOne);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportDepthClipControlCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT) {
	StructureClassHeader(PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubpassShadingPipelineCreateInfoHUAWEI) {
	StructureClassHeader(SubpassShadingPipelineCreateInfoHUAWEI);
	DefineSetter_Copy(RenderPass, VkRenderPass, renderPass);
	DefineSetter_Copy(Subpass, uint32_t, subpass);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassShadingPipelineCreateInfoHUAWEI)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSubpassShadingFeaturesHUAWEI) {
	StructureClassHeader(PhysicalDeviceSubpassShadingFeaturesHUAWEI);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSubpassShadingFeaturesHUAWEI)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSubpassShadingPropertiesHUAWEI) {
	StructureClassHeader(PhysicalDeviceSubpassShadingPropertiesHUAWEI);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSubpassShadingPropertiesHUAWEI)

inline VkResult GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkRenderPass renderPass, VkExtent2D& maxWorkgroupSize) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(DeviceContext::Device(), renderPass, &maxWorkgroupSize);
}

inline void CmdSubpassShadingHUAWEI() {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSubpassShadingHUAWEI(ThreadContext::CommandBuffer());
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceInvocationMaskFeaturesHUAWEI) {
	StructureClassHeader(PhysicalDeviceInvocationMaskFeaturesHUAWEI);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceInvocationMaskFeaturesHUAWEI)

inline void CmdBindInvocationMaskHUAWEI(VkImageView imageView, VkImageLayout imageLayout) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindInvocationMaskHUAWEI(ThreadContext::CommandBuffer(), imageView, imageLayout);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryGetRemoteAddressInfoNV) {
	StructureClassHeader(MemoryGetRemoteAddressInfoNV);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(HandleType, VkExternalMemoryHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryGetRemoteAddressInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalMemoryRDMAFeaturesNV) {
	StructureClassHeader(PhysicalDeviceExternalMemoryRDMAFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalMemoryRDMAFeaturesNV)

inline VkResult GetMemoryRemoteAddressNV(const VkMemoryGetRemoteAddressInfoNV& memoryGetRemoteAddressInfo, VkRemoteAddressNV& address) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetMemoryRemoteAddressNV(DeviceContext::Device(), &memoryGetRemoteAddressInfo, &address);
}
DefineRaiiFunction_ResultL(VkResult, GetMemoryRemoteAddressNV, MemoryGetRemoteAddressInfoNV, VkRemoteAddressNV&, address);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelinePropertiesIdentifierEXT) {
	StructureClassHeader(PipelinePropertiesIdentifierEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelinePropertiesIdentifierEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelinePropertiesFeaturesEXT) {
	StructureClassHeader(PhysicalDevicePipelinePropertiesFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelinePropertiesFeaturesEXT)

inline VkResult GetPipelinePropertiesEXT(const VkPipelineInfoEXT& pipelineInfo, IsOutStructure auto& pipelineProperties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelinePropertiesEXT(DeviceContext::Device(), &pipelineInfo, &pipelineProperties);
}
DefineRaiiFunction_ResultL(VkResult, GetPipelinePropertiesEXT, PipelineInfoEXT, IsOutStructure auto&, pipelineProperties);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFrameBoundaryFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceFrameBoundaryFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFrameBoundaryFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FrameBoundaryEXT) {
	StructureClassHeader(FrameBoundaryEXT);
	DefineSetter_Copy(Flags, VkFrameBoundaryFlagsEXT, flags);
	DefineSetter_Copy(FrameID, uint64_t, frameID);
	DefineSetter_Copy(ImageCount, uint32_t, imageCount);
	DefineSetter_ArrayRef(Images, const VkImage, images, imageCount);
	DefineSetter_Copy(BufferCount, uint32_t, bufferCount);
	DefineSetter_ArrayRef(Buffers, const VkBuffer, buffers, bufferCount);
	DefineSetter_Copy(TagName, uint64_t, tagName);
	DefineSetter_Copy(TagSize, size_t, tagSize);
	DefineSetter_ArrayRef(Tag, const void, tag, tagSize);
};
VK_ENCAPSULATION_STRUCTURE_END(FrameBoundaryEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SubpassResolvePerformanceQueryEXT) {
	StructureClassHeader(SubpassResolvePerformanceQueryEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(SubpassResolvePerformanceQueryEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MultisampledRenderToSingleSampledInfoEXT) {
	StructureClassHeader(MultisampledRenderToSingleSampledInfoEXT);
	DefineSetter_Copy(MultisampledRenderToSingleSampledEnable, VkBool32, multisampledRenderToSingleSampledEnable);
	DefineSetter_CopyOptional(RasterizationSamples, VkSampleCountFlagBits, rasterizationSamples, multisampledRenderToSingleSampledEnable, true);
};
VK_ENCAPSULATION_STRUCTURE_END(MultisampledRenderToSingleSampledInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExtendedDynamicState2FeaturesEXT) {
	StructureClassHeader(PhysicalDeviceExtendedDynamicState2FeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExtendedDynamicState2FeaturesEXT)

inline void CmdSetPatchControlPointsEXT(uint32_t patchControlPoints) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPatchControlPointsEXT(ThreadContext::CommandBuffer(), patchControlPoints);
}

inline void CmdSetRasterizerDiscardEnableEXT(VkBool32 rasterizerDiscardEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRasterizerDiscardEnableEXT(ThreadContext::CommandBuffer(), rasterizerDiscardEnable);
}

inline void CmdSetDepthBiasEnableEXT(VkBool32 depthBiasEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthBiasEnableEXT(ThreadContext::CommandBuffer(), depthBiasEnable);
}

inline void CmdSetLogicOpEXT(VkLogicOp logicOp) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLogicOpEXT(ThreadContext::CommandBuffer(), logicOp);
}

inline void CmdSetPrimitiveRestartEnableEXT(VkBool32 primitiveRestartEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPrimitiveRestartEnableEXT(ThreadContext::CommandBuffer(), primitiveRestartEnable);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceColorWriteEnableFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceColorWriteEnableFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceColorWriteEnableFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineColorWriteCreateInfoEXT) {
	StructureClassHeader(PipelineColorWriteCreateInfoEXT);
	DefineSetter_Copy(AttachmentCount, uint32_t, attachmentCount);
	DefineSetter_ArrayRef(ColorWriteEnables, const VkBool32, colorWriteEnables, attachmentCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineColorWriteCreateInfoEXT)

inline void CmdSetColorWriteEnableEXT(ArrayRef<const VkBool32> colorWriteEnables) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetColorWriteEnableEXT(ThreadContext::CommandBuffer(), colorWriteEnables.size(), colorWriteEnables);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT) {
	StructureClassHeader(PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE) {
	StructureClassHeader(PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeRgbConversionCapabilitiesVALVE) {
	StructureClassHeader(VideoEncodeRgbConversionCapabilitiesVALVE);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeRgbConversionCapabilitiesVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeProfileRgbConversionInfoVALVE) {
	StructureClassHeader(VideoEncodeProfileRgbConversionInfoVALVE);
	DefineSetter_Copy(PerformEncodeRgbConversion, VkBool32, performEncodeRgbConversion);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeProfileRgbConversionInfoVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(VideoEncodeSessionRgbConversionCreateInfoVALVE) {
	StructureClassHeader(VideoEncodeSessionRgbConversionCreateInfoVALVE);
	DefineSetter_Copy(RgbModel, VkVideoEncodeRgbModelConversionFlagBitsVALVE, rgbModel);
	DefineSetter_Copy(RgbRange, VkVideoEncodeRgbRangeCompressionFlagBitsVALVE, rgbRange);
	DefineSetter_Copy(XChromaOffset, VkVideoEncodeRgbChromaOffsetFlagBitsVALVE, xChromaOffset);
	DefineSetter_Copy(YChromaOffset, VkVideoEncodeRgbChromaOffsetFlagBitsVALVE, yChromaOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(VideoEncodeSessionRgbConversionCreateInfoVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageViewMinLodFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceImageViewMinLodFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageViewMinLodFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewMinLodCreateInfoEXT) {
	StructureClassHeader(ImageViewMinLodCreateInfoEXT);
	DefineSetter_Copy(MinLod, float, minLod);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewMinLodCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultiDrawFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceMultiDrawFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultiDrawFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultiDrawPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceMultiDrawPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultiDrawPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MultiDrawInfoEXT) {
	StructureClassHeader_NoSType(MultiDrawInfoEXT);
	DefineSetter_Copy(FirstVertex, uint32_t, firstVertex);
	DefineSetter_Copy(VertexCount, uint32_t, vertexCount);
};
VK_ENCAPSULATION_STRUCTURE_END(MultiDrawInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MultiDrawIndexedInfoEXT) {
	StructureClassHeader_NoSType(MultiDrawIndexedInfoEXT);
	DefineSetter_Copy(FirstIndex, uint32_t, firstIndex);
	DefineSetter_Copy(VndexCount, uint32_t, indexCount);
	DefineSetter_Copy(VertexOffset, int32_t, vertexOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(MultiDrawIndexedInfoEXT)

inline void CmdDrawMultiEXT(uint32_t drawCount, ArrayRef<const VkMultiDrawInfoEXT> vertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMultiEXT(ThreadContext::CommandBuffer(), drawCount, vertexInfo, instanceCount, firstInstance, stride);
}

inline void CmdDrawMultiIndexedEXT(uint32_t drawCount, ArrayRef<const VkMultiDrawIndexedInfoEXT> indexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, OptionalRef<const int32_t> vertexOffset = {}) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMultiIndexedEXT(ThreadContext::CommandBuffer(), drawCount, indexInfo, instanceCount, firstInstance, stride, &vertexOffset);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImage2DViewOf3DFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceImage2DViewOf3DFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImage2DViewOf3DFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderTileImageFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderTileImageFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderTileImageFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderTileImagePropertiesEXT) {
	StructureClassHeader(PhysicalDeviceShaderTileImagePropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderTileImagePropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MicromapUsageEXT) {
	StructureClassHeader_NoSType(MicromapUsageEXT);
	DefineSetter_Copy(Count, uint32_t, count);
	DefineSetter_Copy(SubdivisionLevel, uint32_t, subdivisionLevel);
	DefineSetter_Copy(Format, uint32_t, format);
};
VK_ENCAPSULATION_STRUCTURE_END(MicromapUsageEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(DeviceOrHostAddressKHR) {
	StructureClassHeader_UnionWrapper(DeviceOrHostAddressKHR);
	union {
		VkDeviceAddress    deviceAddress;
		void*              hostAddress;
	};
	Structure(VkDeviceAddress deviceAddress) : deviceAddress(deviceAddress) {}
	Structure(void* hostAddress) : hostAddress(hostAddress) {}
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceOrHostAddressKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MicromapBuildInfoEXT) {
	StructureClassHeader(MicromapBuildInfoEXT);
	DefineSetter_Copy(Type, VkMicromapTypeEXT, type);
	DefineSetter_Copy(Flags, VkBuildMicromapFlagsEXT, flags);
	DefineSetter_Copy(Mode, VkBuildMicromapModeEXT, mode);
	DefineSetter_Copy(DstMicromap, VkMicromapEXT, dstMicromap);
	DefineSetter_Copy(UsageCountsCount, uint32_t, usageCountsCount);
	DefineSetter_ArrayRef(UsageCounts, const VkMicromapUsageEXT, usageCounts, usageCountsCount);
	_&  UsageCounts(std::pair<uint32_t, const VkMicromapUsageEXT* const*> usageCounts) &  { usageCountsCount = usageCounts.first; ppUsageCounts = usageCounts.second; return *this; }
	_&& UsageCounts(std::pair<uint32_t, const VkMicromapUsageEXT* const*> usageCounts) && { return std::move(UsageCounts(usageCounts)); }
	_&  UsageCounts(std::pair<const VkMicromapUsageEXT* const*, uint32_t> usageCounts) &  { usageCountsCount = usageCounts.second; ppUsageCounts = usageCounts.first; return *this; }
	_&& UsageCounts(std::pair<const VkMicromapUsageEXT* const*, uint32_t> usageCounts) && { return std::move(UsageCounts(usageCounts)); }
	DefineSetter_Copy(Data, VkDeviceOrHostAddressConstKHR, data);
	DefineSetter_Copy(ScratchData, VkDeviceOrHostAddressKHR, scratchData);
	DefineSetter_Copy(TriangleArray, VkDeviceOrHostAddressConstKHR, triangleArray);
	DefineSetter_Copy(TriangleArrayStride, VkDeviceSize, triangleArrayStride);
};
VK_ENCAPSULATION_STRUCTURE_END(MicromapBuildInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MicromapCreateInfoEXT) {
	StructureClassHeader(MicromapCreateInfoEXT);
	DefineSetter_Copy(CreateFlags, VkMicromapCreateFlagsEXT, createFlags);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(Type, VkMicromapTypeEXT, type);
	DefineSetter_Copy(DeviceAddress, VkDeviceAddress, deviceAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(MicromapCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceOpacityMicromapFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceOpacityMicromapFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceOpacityMicromapFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceOpacityMicromapPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceOpacityMicromapPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceOpacityMicromapPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MicromapVersionInfoEXT) {
	StructureClassHeader(MicromapVersionInfoEXT);
	DefineSetter_ArrayRefIgnoreC(VersionData, const uint8_t, versionData);
};
VK_ENCAPSULATION_STRUCTURE_END(MicromapVersionInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyMicromapToMemoryInfoEXT) {
	StructureClassHeader(CopyMicromapToMemoryInfoEXT);
	DefineSetter_Copy(Src, VkMicromapEXT, src);
	DefineSetter_Copy(Dst, VkDeviceOrHostAddressKHR, dst);
	DefineSetter_Copy(Mode, VkCopyMicromapModeEXT, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMicromapToMemoryInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyMemoryToMicromapInfoEXT) {
	StructureClassHeader(CopyMemoryToMicromapInfoEXT);
	DefineSetter_Copy(Src, VkDeviceOrHostAddressConstKHR, src);
	DefineSetter_Copy(Dst, VkMicromapEXT, dst);
	DefineSetter_Copy(Mode, VkCopyMicromapModeEXT, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMemoryToMicromapInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyMicromapInfoEXT) {
	StructureClassHeader(CopyMicromapInfoEXT);
	DefineSetter_Copy(Src, VkMicromapEXT, src);
	DefineSetter_Copy(Dst, VkMicromapEXT, dst);
	DefineSetter_Copy(Mode, VkCopyMicromapModeEXT, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMicromapInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MicromapBuildSizesInfoEXT) {
	StructureClassHeader(MicromapBuildSizesInfoEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(MicromapBuildSizesInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureTrianglesOpacityMicromapEXT) {
	StructureClassHeader(AccelerationStructureTrianglesOpacityMicromapEXT);
	DefineSetter_Copy(IndexType, VkIndexType, indexType);
	DefineSetter_Copy(IndexBuffer, VkDeviceOrHostAddressConstKHR, indexBuffer);
	DefineSetter_Copy(IndexStride, VkDeviceSize, indexStride);
	DefineSetter_Copy(BaseTriangle, uint32_t, baseTriangle);
	DefineSetter_Copy(UsageCountsCount, uint32_t, usageCountsCount);
	DefineSetter_ArrayRef(UsageCounts, const VkMicromapUsageEXT, usageCounts, usageCountsCount);
	_&  UsageCounts(std::pair<uint32_t, const VkMicromapUsageEXT* const*> usageCounts) &  { usageCountsCount = usageCounts.first; ppUsageCounts = usageCounts.second; return *this; }
	_&& UsageCounts(std::pair<uint32_t, const VkMicromapUsageEXT* const*> usageCounts) && { return std::move(UsageCounts(usageCounts)); }
	_&  UsageCounts(std::pair<const VkMicromapUsageEXT* const*, uint32_t> usageCounts) &  { usageCountsCount = usageCounts.second; ppUsageCounts = usageCounts.first; return *this; }
	_&& UsageCounts(std::pair<const VkMicromapUsageEXT* const*, uint32_t> usageCounts) && { return std::move(UsageCounts(usageCounts)); }
	DefineSetter_Copy(Micromap, VkMicromapEXT, micromap);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureTrianglesOpacityMicromapEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(MicromapTriangleEXT) {
	StructureClassHeader_NoSType(MicromapTriangleEXT);
	DefineSetter_Copy(DataOffset, uint32_t, dataOffset);
	DefineSetter_Copy(SubdivisionLevel, uint16_t, subdivisionLevel);
	DefineSetter_Copy(Format, uint16_t, format);
};
VK_ENCAPSULATION_STRUCTURE_END(MicromapTriangleEXT)

inline VkResult CreateMicromapEXT(const VkMicromapCreateInfoEXT& createInfo, HandleRef<VkMicromapEXT> micromap) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateMicromapEXT(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &micromap);
}
DefineRaiiFunction_ResultL(VkResult, CreateMicromapEXT, MicromapCreateInfoEXT, HandleRef<VkMicromapEXT>, micromap);

inline void DestroyMicromapEXT(HandleRef<VkMicromapEXT> micromap, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyMicromapEXT(DeviceContext::Device(), micromap, &allocator);
	micromap = VK_NULL_HANDLE;
}

inline void CmdBuildMicromapsEXT(ArrayRef<const VkMicromapBuildInfoEXT> infos) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBuildMicromapsEXT(ThreadContext::CommandBuffer(), infos.size(), infos);
}
DefineRaiiFunction(CmdBuildMicromapsEXT, MicromapBuildInfoEXT);

inline VkResult BuildMicromapsEXT(VkDeferredOperationKHR deferredOperation, ArrayRef<const VkMicromapBuildInfoEXT> infos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBuildMicromapsEXT(DeviceContext::Device(), deferredOperation, infos.size(), infos);
}
DefineRaiiFunction_ResultR(VkResult, BuildMicromapsEXT, VkDeferredOperationKHR, deferredOperation, MicromapBuildInfoEXT);

inline VkResult CopyMicromapEXT(VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyMicromapEXT(DeviceContext::Device(), deferredOperation, &info);
}
DefineRaiiFunction_ResultR(VkResult, CopyMicromapEXT, VkDeferredOperationKHR, deferredOperation, CopyMicromapInfoEXT);

inline VkResult CopyMicromapToMemoryEXT(VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyMicromapToMemoryEXT(DeviceContext::Device(), deferredOperation, &info);
}
DefineRaiiFunction_ResultR(VkResult, CopyMicromapToMemoryEXT, VkDeferredOperationKHR, deferredOperation, CopyMicromapToMemoryInfoEXT);

inline VkResult CopyMemoryToMicromapEXT(VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyMemoryToMicromapEXT(DeviceContext::Device(), deferredOperation, &info);
}
DefineRaiiFunction_ResultR(VkResult, CopyMemoryToMicromapEXT, VkDeferredOperationKHR, deferredOperation, CopyMemoryToMicromapInfoEXT);

inline VkResult WriteMicromapsPropertiesEXT(ArrayRef<const VkMicromapEXT> micromaps, VkQueryType queryType, ArrayRef<void> data, size_t stride) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkWriteMicromapsPropertiesEXT(DeviceContext::Device(), micromaps.size(), micromaps, queryType, data.size(), data, stride);
}
inline VkResult WriteMicromapsPropertiesEXT(VkMicromapEXT micromap, VkQueryType queryType, IsNotRangeOrPointer auto& data, size_t stride) {
	return WriteMicromapsPropertiesEXT(micromap, queryType, { sizeof *&data, &data }, stride);
}

inline void CmdCopyMicromapEXT(const VkCopyMicromapInfoEXT& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMicromapEXT(ThreadContext::CommandBuffer(), &info);
}
DefineRaiiFunction(CmdCopyMicromapEXT, CopyMicromapInfoEXT);

inline void CmdCopyMicromapToMemoryEXT(const VkCopyMicromapToMemoryInfoEXT& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMicromapToMemoryEXT(ThreadContext::CommandBuffer(), &info);
}
DefineRaiiFunction(CmdCopyMicromapToMemoryEXT, CopyMicromapToMemoryInfoEXT);

inline void CmdCopyMemoryToMicromapEXT(const VkCopyMemoryToMicromapInfoEXT& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMemoryToMicromapEXT(ThreadContext::CommandBuffer(), &info);
}
DefineRaiiFunction(CmdCopyMemoryToMicromapEXT, CopyMemoryToMicromapInfoEXT);

inline void CmdWriteMicromapsPropertiesEXT(ArrayRef<const VkMicromapEXT> micromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteMicromapsPropertiesEXT(ThreadContext::CommandBuffer(), micromaps.size(), micromaps, queryType, queryPool, firstQuery);
}

inline void GetDeviceMicromapCompatibilityEXT(const VkMicromapVersionInfoEXT& versionInfo, VkAccelerationStructureCompatibilityKHR& compatibility) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceMicromapCompatibilityEXT(DeviceContext::Device(), &versionInfo, &compatibility);
}
DefineRaiiFunction_L(GetDeviceMicromapCompatibilityEXT, MicromapVersionInfoEXT, VkAccelerationStructureCompatibilityKHR&, compatibility);

inline void GetMicromapBuildSizesEXT(VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT& buildInfo, VkMicromapBuildSizesInfoEXT& sizeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetMicromapBuildSizesEXT(DeviceContext::Device(), buildType, &buildInfo, &sizeInfo);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceClusterCullingShaderFeaturesHUAWEI) {
	StructureClassHeader(PhysicalDeviceClusterCullingShaderFeaturesHUAWEI);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceClusterCullingShaderFeaturesHUAWEI)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceClusterCullingShaderPropertiesHUAWEI) {
	StructureClassHeader(PhysicalDeviceClusterCullingShaderPropertiesHUAWEI);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceClusterCullingShaderPropertiesHUAWEI)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI) {
	StructureClassHeader(PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI)

inline void CmdDrawClusterHUAWEI(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawClusterHUAWEI(ThreadContext::CommandBuffer(), groupCountX, groupCountY, groupCountZ);
}

inline void CmdDrawClusterIndirectHUAWEI(VkBuffer buffer, VkDeviceSize offset) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawClusterIndirectHUAWEI(ThreadContext::CommandBuffer(), buffer, offset);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceBorderColorSwizzleFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceBorderColorSwizzleFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceBorderColorSwizzleFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerBorderColorComponentMappingCreateInfoEXT) {
	StructureClassHeader(SamplerBorderColorComponentMappingCreateInfoEXT);
	DefineSetter_Copy(Components, VkComponentMapping, components);
	DefineSetter_Copy(Srgb, VkBool32, srgb);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerBorderColorComponentMappingCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT) {
	StructureClassHeader(PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT)

inline void SetDeviceMemoryPriorityEXT(VkDeviceMemory memory, float priority) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkSetDeviceMemoryPriorityEXT(DeviceContext::Device(), memory, priority);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderCorePropertiesARM) {
	StructureClassHeader(PhysicalDeviceShaderCorePropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderCorePropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceQueueShaderCoreControlCreateInfoARM) {
	StructureClassHeader(DeviceQueueShaderCoreControlCreateInfoARM);
	DefineSetter_Copy(ShaderCoreCount, uint32_t, shaderCoreCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceQueueShaderCoreControlCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSchedulingControlsFeaturesARM) {
	StructureClassHeader(PhysicalDeviceSchedulingControlsFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSchedulingControlsFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSchedulingControlsPropertiesARM) {
	StructureClassHeader(PhysicalDeviceSchedulingControlsPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSchedulingControlsPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageSlicedViewOf3DFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceImageSlicedViewOf3DFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageSlicedViewOf3DFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewSlicedCreateInfoEXT) {
	StructureClassHeader(ImageViewSlicedCreateInfoEXT);
	DefineSetter_Copy(SliceOffset, uint32_t, sliceOffset);
	DefineSetter_Copy(SliceCount, uint32_t, sliceCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewSlicedCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE) {
	StructureClassHeader(PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetBindingReferenceVALVE) {
	StructureClassHeader(DescriptorSetBindingReferenceVALVE);
	DefineSetter_Copy(DescriptorSetLayout, VkDescriptorSetLayout, descriptorSetLayout);
	DefineSetter_Copy(Binding, uint32_t, binding);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetBindingReferenceVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorSetLayoutHostMappingInfoVALVE) {
	StructureClassHeader(DescriptorSetLayoutHostMappingInfoVALVE);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorSetLayoutHostMappingInfoVALVE)

inline void GetDescriptorSetLayoutHostMappingInfoVALVE(const VkDescriptorSetBindingReferenceVALVE& bindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE& hostMapping) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDescriptorSetLayoutHostMappingInfoVALVE(DeviceContext::Device(), &bindingReference, &hostMapping);
}
DefineRaiiFunction_L(GetDescriptorSetLayoutHostMappingInfoVALVE, DescriptorSetBindingReferenceVALVE, VkDescriptorSetLayoutHostMappingInfoVALVE&, hostMapping);

inline void GetDescriptorSetHostMappingVALVE(VkDescriptorSet descriptorSet, void*& pData) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDescriptorSetHostMappingVALVE(DeviceContext::Device(), descriptorSet, &pData);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceNonSeamlessCubeMapFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceNonSeamlessCubeMapFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceNonSeamlessCubeMapFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRenderPassStripedFeaturesARM) {
	StructureClassHeader(PhysicalDeviceRenderPassStripedFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRenderPassStripedFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRenderPassStripedPropertiesARM) {
	StructureClassHeader(PhysicalDeviceRenderPassStripedPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRenderPassStripedPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassStripeInfoARM) {
	StructureClassHeader(RenderPassStripeInfoARM);
	DefineSetter_Copy(StripeArea, VkRect2D, stripeArea);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassStripeInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassStripeBeginInfoARM) {
	StructureClassHeader(RenderPassStripeBeginInfoARM);
	DefineSetter_Copy(StripeInfoCount, uint32_t, stripeInfoCount);
	DefineSetter_ArrayRef(StripeInfos, const VkRenderPassStripeInfoARM, stripeInfos, stripeInfoCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassStripeBeginInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassStripeSubmitInfoARM) {
	StructureClassHeader(RenderPassStripeSubmitInfoARM);
	DefineSetter_Copy(StripeSemaphoreInfoCount, uint32_t, stripeSemaphoreInfoCount);
	DefineSetter_ArrayRef(StripeSemaphoreInfos, const VkSemaphoreSubmitInfo, stripeSemaphoreInfos, stripeSemaphoreInfoCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassStripeSubmitInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassFragmentDensityMapOffsetEndInfoEXT) {
	StructureClassHeader(RenderPassFragmentDensityMapOffsetEndInfoEXT);
	DefineSetter_Copy(FragmentDensityOffsetCount, uint32_t, fragmentDensityOffsetCount);
	DefineSetter_ArrayRef(FragmentDensityOffsets, const VkOffset2D, fragmentDensityOffsets, fragmentDensityOffsetCount);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassFragmentDensityMapOffsetEndInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCopyMemoryIndirectFeaturesNV) {
	StructureClassHeader(PhysicalDeviceCopyMemoryIndirectFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCopyMemoryIndirectFeaturesNV)

inline void CmdCopyMemoryIndirectNV(VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMemoryIndirectNV(ThreadContext::CommandBuffer(), copyBufferAddress, copyCount, stride);
}

inline void CmdCopyMemoryToImageIndirectNV(VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, ArrayRef<const VkImageSubresourceLayers> imageSubresources) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMemoryToImageIndirectNV(ThreadContext::CommandBuffer(), copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, imageSubresources);
}
inline void CmdCopyMemoryToImageIndirectNV(VkDeviceAddress copyBufferAddress, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, ArrayRef<const VkImageSubresourceLayers> imageSubresources) {
	CmdCopyMemoryToImageIndirectNV(copyBufferAddress, imageSubresources.size(), stride, dstImage, dstImageLayout, imageSubresources);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DecompressMemoryRegionNV) {
	StructureClassHeader_NoSType(DecompressMemoryRegionNV);
	DefineSetter_Copy(SrcAddress, VkDeviceAddress, srcAddress);
	DefineSetter_Copy(DstAddress, VkDeviceAddress, dstAddress);
	DefineSetter_Copy(CompressedSize, VkDeviceSize, compressedSize);
	DefineSetter_Copy(DecompressedSize, VkDeviceSize, decompressedSize);
	DefineSetter_Copy(DecompressionMethod, VkMemoryDecompressionMethodFlagsNV, decompressionMethod);
};
VK_ENCAPSULATION_STRUCTURE_END(DecompressMemoryRegionNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMemoryDecompressionFeaturesNV) {
	StructureClassHeader(PhysicalDeviceMemoryDecompressionFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMemoryDecompressionFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMemoryDecompressionPropertiesNV) {
	StructureClassHeader(PhysicalDeviceMemoryDecompressionPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMemoryDecompressionPropertiesNV)

inline void CmdDecompressMemoryNV(ArrayRef<const VkDecompressMemoryRegionNV> decompressMemoryRegions) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDecompressMemoryNV(ThreadContext::CommandBuffer(), decompressMemoryRegions.size(), decompressMemoryRegions);
}

inline void CmdDecompressMemoryIndirectCountNV(VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDecompressMemoryIndirectCountNV(ThreadContext::CommandBuffer(), indirectCommandsAddress, indirectCommandsCountAddress, stride);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV) {
	StructureClassHeader(PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ComputePipelineIndirectBufferInfoNV) {
	StructureClassHeader(ComputePipelineIndirectBufferInfoNV);
	DefineSetter_Copy(DeviceAddress, VkDeviceAddress, deviceAddress);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(PipelineDeviceAddressCaptureReplay, VkDeviceAddress, pipelineDeviceAddressCaptureReplay);
};
VK_ENCAPSULATION_STRUCTURE_END(ComputePipelineIndirectBufferInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineIndirectDeviceAddressInfoNV) {
	StructureClassHeader(PipelineIndirectDeviceAddressInfoNV);
	DefineSetter_Copy(PipelineBindPoint, VkPipelineBindPoint, pipelineBindPoint);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineIndirectDeviceAddressInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BindPipelineIndirectCommandNV) {
	StructureClassHeader_NoSType(BindPipelineIndirectCommandNV);
	DefineSetter_Copy(PipelineAddress, VkDeviceAddress, pipelineAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(BindPipelineIndirectCommandNV)

inline void GetPipelineIndirectMemoryRequirementsNV(const VkComputePipelineCreateInfo& createInfo, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineIndirectMemoryRequirementsNV(DeviceContext::Device(), &createInfo, &memoryRequirements);
}
DefineRaiiFunction_L(GetPipelineIndirectMemoryRequirementsNV, ComputePipelineCreateInfo, VkMemoryRequirements2&, memoryRequirements);

inline void CmdUpdatePipelineIndirectBufferNV(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdUpdatePipelineIndirectBufferNV(ThreadContext::CommandBuffer(), pipelineBindPoint, pipeline);
}

inline VkDeviceAddress GetPipelineIndirectDeviceAddressNV(const VkPipelineIndirectDeviceAddressInfoNV& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPipelineIndirectDeviceAddressNV(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkDeviceAddress, GetPipelineIndirectDeviceAddressNV, PipelineIndirectDeviceAddressInfoNV);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV) {
	StructureClassHeader(PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureGeometryLinearSweptSpheresDataNV) {
	StructureClassHeader(AccelerationStructureGeometryLinearSweptSpheresDataNV);
	DefineSetter_Copy(VertexFormat, VkFormat, vertexFormat);
	DefineSetter_Copy(VertexData, VkDeviceOrHostAddressConstKHR, vertexData);
	DefineSetter_Copy(VertexStride, VkDeviceSize, vertexStride);
	DefineSetter_Copy(RadiusFormat, VkFormat, radiusFormat);
	DefineSetter_Copy(RadiusData, VkDeviceOrHostAddressConstKHR, radiusData);
	DefineSetter_Copy(RadiusStride, VkDeviceSize, radiusStride);
	DefineSetter_Copy(IndexType, VkIndexType, indexType);
	DefineSetter_Copy(IndexData, VkDeviceOrHostAddressConstKHR, indexData);
	DefineSetter_Copy(IndexStride, VkDeviceSize, indexStride);
	DefineSetter_Copy(IndexingMode, VkRayTracingLssIndexingModeNV, indexingMode);
	DefineSetter_Copy(EndCapsMode, VkRayTracingLssPrimitiveEndCapsModeNV, endCapsMode);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometryLinearSweptSpheresDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureGeometrySpheresDataNV) {
	StructureClassHeader(AccelerationStructureGeometrySpheresDataNV);
	DefineSetter_Copy(VertexFormat, VkFormat, vertexFormat);
	DefineSetter_Copy(VertexData, VkDeviceOrHostAddressConstKHR, vertexData);
	DefineSetter_Copy(VertexStride, VkDeviceSize, vertexStride);
	DefineSetter_Copy(RadiusFormat, VkFormat, radiusFormat);
	DefineSetter_Copy(RadiusData, VkDeviceOrHostAddressConstKHR, radiusData);
	DefineSetter_Copy(RadiusStride, VkDeviceSize, radiusStride);
	DefineSetter_Copy(IndexType, VkIndexType, indexType);
	DefineSetter_Copy(IndexData, VkDeviceOrHostAddressConstKHR, indexData);
	DefineSetter_Copy(IndexStride, VkDeviceSize, indexStride);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometrySpheresDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLinearColorAttachmentFeaturesNV) {
	StructureClassHeader(PhysicalDeviceLinearColorAttachmentFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLinearColorAttachmentFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageViewSampleWeightCreateInfoQCOM) {
	StructureClassHeader(ImageViewSampleWeightCreateInfoQCOM);
	DefineSetter_Copy(FilterCenter, VkOffset2D, filterCenter);
	DefineSetter_Copy(FilterSize, VkExtent2D, filterSize);
	DefineSetter_Copy(NumPhases, uint32_t, numPhases);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageViewSampleWeightCreateInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageProcessingFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceImageProcessingFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageProcessingFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageProcessingPropertiesQCOM) {
	StructureClassHeader(PhysicalDeviceImageProcessingPropertiesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageProcessingPropertiesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceNestedCommandBufferFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceNestedCommandBufferFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceNestedCommandBufferFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceNestedCommandBufferPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceNestedCommandBufferPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceNestedCommandBufferPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalMemoryAcquireUnmodifiedEXT) {
	StructureClassHeader(ExternalMemoryAcquireUnmodifiedEXT);
	DefineSetter_Copy(AcquireUnmodifiedMemory, VkBool32, acquireUnmodifiedMemory);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalMemoryAcquireUnmodifiedEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExtendedDynamicState3FeaturesEXT) {
	StructureClassHeader(PhysicalDeviceExtendedDynamicState3FeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExtendedDynamicState3FeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExtendedDynamicState3PropertiesEXT) {
	StructureClassHeader(PhysicalDeviceExtendedDynamicState3PropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExtendedDynamicState3PropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ColorBlendEquationEXT) {
	StructureClassHeader_NoSType(ColorBlendEquationEXT);
	DefineSetter_Copy(SrcColorBlendFactor, VkBlendFactor, srcColorBlendFactor);
	DefineSetter_Copy(DstColorBlendFactor, VkBlendFactor, dstColorBlendFactor);
	DefineSetter_Copy(ColorBlendOp, VkBlendOp, colorBlendOp);
	DefineSetter_Copy(SrcAlphaBlendFactor, VkBlendFactor, srcAlphaBlendFactor);
	DefineSetter_Copy(DstAlphaBlendFactor, VkBlendFactor, dstAlphaBlendFactor);
	DefineSetter_Copy(AlphaBlendOp, VkBlendOp, alphaBlendOp);
};
VK_ENCAPSULATION_STRUCTURE_END(ColorBlendEquationEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ColorBlendAdvancedEXT) {
	StructureClassHeader_NoSType(ColorBlendAdvancedEXT);
	DefineSetter_Copy(AdvancedBlendOp, VkBlendOp, advancedBlendOp);
	DefineSetter_Copy(SrcPremultiplied, VkBool32, srcPremultiplied);
	DefineSetter_Copy(DstPremultiplied, VkBool32, dstPremultiplied);
	DefineSetter_Copy(BlendOverlap, VkBlendOverlapEXT, blendOverlap);
	DefineSetter_Copy(ClampResults, VkBool32, clampResults);
};
VK_ENCAPSULATION_STRUCTURE_END(ColorBlendAdvancedEXT)

inline void CmdSetDepthClampEnableEXT(VkBool32 depthClampEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthClampEnableEXT(ThreadContext::CommandBuffer(), depthClampEnable);
}

inline void CmdSetPolygonModeEXT(VkPolygonMode polygonMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetPolygonModeEXT(ThreadContext::CommandBuffer(), polygonMode);
}

inline void CmdSetRasterizationSamplesEXT(VkSampleCountFlagBits rasterizationSamples) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRasterizationSamplesEXT(ThreadContext::CommandBuffer(), rasterizationSamples);
}

inline void CmdSetSampleMaskEXT(VkSampleCountFlagBits samples, ArrayRef<const VkSampleMask> sampleMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetSampleMaskEXT(ThreadContext::CommandBuffer(), samples, sampleMask);
}

inline void CmdSetAlphaToCoverageEnableEXT(VkBool32 alphaToCoverageEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetAlphaToCoverageEnableEXT(ThreadContext::CommandBuffer(), alphaToCoverageEnable);
}

inline void CmdSetAlphaToOneEnableEXT(VkBool32 alphaToOneEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetAlphaToOneEnableEXT(ThreadContext::CommandBuffer(), alphaToOneEnable);
}

inline void CmdSetLogicOpEnableEXT(VkBool32 logicOpEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLogicOpEnableEXT(ThreadContext::CommandBuffer(), logicOpEnable);
}

inline void CmdSetColorBlendEnableEXT(uint32_t firstAttachment, ArrayRef<const VkBool32> colorBlendEnables) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetColorBlendEnableEXT(ThreadContext::CommandBuffer(), firstAttachment, colorBlendEnables.size(), colorBlendEnables);
}

inline void CmdSetColorBlendEquationEXT(uint32_t firstAttachment, ArrayRef<const VkColorBlendEquationEXT> colorBlendEquations) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetColorBlendEquationEXT(ThreadContext::CommandBuffer(), firstAttachment, colorBlendEquations.size(), colorBlendEquations);
}

inline void CmdSetColorWriteMaskEXT(uint32_t firstAttachment, ArrayRef<const VkColorComponentFlags> colorWriteMasks) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetColorWriteMaskEXT(ThreadContext::CommandBuffer(), firstAttachment, colorWriteMasks.size(), colorWriteMasks);
}

inline void CmdSetTessellationDomainOriginEXT(VkTessellationDomainOrigin domainOrigin) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetTessellationDomainOriginEXT(ThreadContext::CommandBuffer(), domainOrigin);
}

inline void CmdSetRasterizationStreamEXT(uint32_t rasterizationStream) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRasterizationStreamEXT(ThreadContext::CommandBuffer(), rasterizationStream);
}

inline void CmdSetConservativeRasterizationModeEXT(VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetConservativeRasterizationModeEXT(ThreadContext::CommandBuffer(), conservativeRasterizationMode);
}

inline void CmdSetExtraPrimitiveOverestimationSizeEXT(float extraPrimitiveOverestimationSize) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetExtraPrimitiveOverestimationSizeEXT(ThreadContext::CommandBuffer(), extraPrimitiveOverestimationSize);
}

inline void CmdSetDepthClipEnableEXT(VkBool32 depthClipEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthClipEnableEXT(ThreadContext::CommandBuffer(), depthClipEnable);
}

inline void CmdSetSampleLocationsEnableEXT(VkBool32 sampleLocationsEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetSampleLocationsEnableEXT(ThreadContext::CommandBuffer(), sampleLocationsEnable);
}

inline void CmdSetColorBlendAdvancedEXT(uint32_t firstAttachment, ArrayRef<const VkColorBlendAdvancedEXT> colorBlendAdvanced) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetColorBlendAdvancedEXT(ThreadContext::CommandBuffer(), firstAttachment, colorBlendAdvanced.size(), colorBlendAdvanced);
}

inline void CmdSetProvokingVertexModeEXT(VkProvokingVertexModeEXT provokingVertexMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetProvokingVertexModeEXT(ThreadContext::CommandBuffer(), provokingVertexMode);
}

inline void CmdSetLineRasterizationModeEXT(VkLineRasterizationModeEXT lineRasterizationMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLineRasterizationModeEXT(ThreadContext::CommandBuffer(), lineRasterizationMode);
}

inline void CmdSetLineStippleEnableEXT(VkBool32 stippledLineEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetLineStippleEnableEXT(ThreadContext::CommandBuffer(), stippledLineEnable);
}

inline void CmdSetDepthClipNegativeOneToOneEXT(VkBool32 negativeOneToOne) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthClipNegativeOneToOneEXT(ThreadContext::CommandBuffer(), negativeOneToOne);
}

inline void CmdSetViewportWScalingEnableNV(VkBool32 viewportWScalingEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetViewportWScalingEnableNV(ThreadContext::CommandBuffer(), viewportWScalingEnable);
}

inline void CmdSetViewportSwizzleNV(uint32_t firstViewport, ArrayRef<const VkViewportSwizzleNV> viewportSwizzles) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetViewportSwizzleNV(ThreadContext::CommandBuffer(), firstViewport, viewportSwizzles.size(), viewportSwizzles);
}

inline void CmdSetCoverageToColorEnableNV(VkBool32 coverageToColorEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCoverageToColorEnableNV(ThreadContext::CommandBuffer(), coverageToColorEnable);
}

inline void CmdSetCoverageToColorLocationNV(uint32_t coverageToColorLocation) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCoverageToColorLocationNV(ThreadContext::CommandBuffer(), coverageToColorLocation);
}

inline void CmdSetCoverageModulationModeNV(VkCoverageModulationModeNV coverageModulationMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCoverageModulationModeNV(ThreadContext::CommandBuffer(), coverageModulationMode);
}

inline void CmdSetCoverageModulationTableEnableNV(VkBool32 coverageModulationTableEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCoverageModulationTableEnableNV(ThreadContext::CommandBuffer(), coverageModulationTableEnable);
}

inline void CmdSetCoverageModulationTableNV(ArrayRef<const float> coverageModulationTable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCoverageModulationTableNV(ThreadContext::CommandBuffer(), coverageModulationTable.size(), coverageModulationTable);
}

inline void CmdSetShadingRateImageEnableNV(VkBool32 shadingRateImageEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetShadingRateImageEnableNV(ThreadContext::CommandBuffer(), shadingRateImageEnable);
}

inline void CmdSetRepresentativeFragmentTestEnableNV(VkBool32 representativeFragmentTestEnable) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRepresentativeFragmentTestEnableNV(ThreadContext::CommandBuffer(), representativeFragmentTestEnable);
}

inline void CmdSetCoverageReductionModeNV(VkCoverageReductionModeNV coverageReductionMode) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetCoverageReductionModeNV(ThreadContext::CommandBuffer(), coverageReductionMode);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceSubpassMergeFeedbackFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceSubpassMergeFeedbackFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceSubpassMergeFeedbackFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassCreationControlEXT) {
	StructureClassHeader(RenderPassCreationControlEXT);
	DefineSetter_Copy(DisallowMerging, VkBool32, disallowMerging);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassCreationControlEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(RenderPassCreationFeedbackInfoEXT) {
	StructureClassHeader_NoSType(RenderPassCreationFeedbackInfoEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassCreationFeedbackInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassCreationFeedbackCreateInfoEXT) {
	StructureClassHeader(RenderPassCreationFeedbackCreateInfoEXT);
	DefineSetter_Ref(RenderPassFeedback, VkRenderPassCreationFeedbackInfoEXT, renderPassFeedback);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassCreationFeedbackCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(RenderPassSubpassFeedbackInfoEXT) {
	StructureClassHeader_NoSType(RenderPassSubpassFeedbackInfoEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassSubpassFeedbackInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderPassSubpassFeedbackCreateInfoEXT) {
	StructureClassHeader(RenderPassSubpassFeedbackCreateInfoEXT);
	DefineSetter_Ref(SubpassFeedback, VkRenderPassSubpassFeedbackInfoEXT, subpassFeedback);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderPassSubpassFeedbackCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DirectDriverLoadingInfoLUNARG) {
	StructureClassHeader(DirectDriverLoadingInfoLUNARG);
	DefineSetter_Copy(Flags, VkDirectDriverLoadingFlagsLUNARG, flags);
	DefineSetter_Copy(FnGetInstanceProcAddr, PFN_vkGetInstanceProcAddrLUNARG, pfnGetInstanceProcAddr);
};
VK_ENCAPSULATION_STRUCTURE_END(DirectDriverLoadingInfoLUNARG)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DirectDriverLoadingListLUNARG) {
	StructureClassHeader(DirectDriverLoadingListLUNARG);
	DefineSetter_Copy(Mode, VkDirectDriverLoadingModeLUNARG, mode);
	DefineSetter_Copy(DriverCount, uint32_t, driverCount);
	DefineSetter_ArrayRef(Drivers, const VkDirectDriverLoadingInfoLUNARG, drivers, driverCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DirectDriverLoadingListLUNARG)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorDescriptionARM) {
	StructureClassHeader(TensorDescriptionARM);
	DefineSetter_Copy(Tiling, VkTensorTilingARM, tiling);
	DefineSetter_Copy(Format, VkFormat, format);
	DefineSetter_Copy(DimensionCount, uint32_t, dimensionCount);
	DefineSetter_ArrayRef(Dimensions, const int64_t, dimensions, dimensionCount);
	DefineSetter_ArrayRefIgnoreC(Strides, const int64_t, strides);
	DefineSetter_Copy(Usage, VkTensorUsageFlagsARM, usage);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorDescriptionARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorCreateInfoARM) {
	StructureClassHeader(TensorCreateInfoARM);
	DefineSetter_Copy(Flags, VkTensorCreateFlagsARM, flags);
	DefineSetter_Ref(Description, const VkTensorDescriptionARM, description);
	DefineSetter_Copy(SharingMode, VkSharingMode, sharingMode);
	DefineSetter_ArrayRef(QueueFamilyIndices, const uint32_t, queueFamilyIndices, queueFamilyIndexCount, sharingMode = VkSharingMode(bool(queueFamilyIndices)));
};
VK_ENCAPSULATION_STRUCTURE_END(TensorCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorViewCreateInfoARM) {
	StructureClassHeader(TensorViewCreateInfoARM);
	DefineSetter_Copy(Flags, VkTensorViewCreateFlagsARM, flags);
	DefineSetter_Copy(Tensor, VkTensorARM, tensor);
	DefineSetter_Copy(Format, VkFormat, format);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorViewCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorMemoryRequirementsInfoARM) {
	StructureClassHeader(TensorMemoryRequirementsInfoARM);
	DefineSetter_Copy(Tensor, VkTensorARM, tensor);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorMemoryRequirementsInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindTensorMemoryInfoARM) {
	StructureClassHeader(BindTensorMemoryInfoARM);
	DefineSetter_Copy(Tensor, VkTensorARM, tensor);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(BindTensorMemoryInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteDescriptorSetTensorARM) {
	StructureClassHeader(WriteDescriptorSetTensorARM);
	DefineSetter_Copy(TensorViewCount, uint32_t, tensorViewCount);
	DefineSetter_ArrayRef(TensorViews, const VkTensorViewARM, tensorViews, tensorViewCount);
};
VK_ENCAPSULATION_STRUCTURE_END(WriteDescriptorSetTensorARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorFormatPropertiesARM) {
	StructureClassHeader(TensorFormatPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorFormatPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTensorPropertiesARM) {
	StructureClassHeader(PhysicalDeviceTensorPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTensorPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorMemoryBarrierARM) {
	StructureClassHeader(TensorMemoryBarrierARM, .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED, .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED);
	DefineSetter_Copy(SrcStageMask, VkPipelineStageFlags2, srcStageMask);
	DefineSetter_Copy(SrcAccessMask, VkAccessFlags2, srcAccessMask);
	DefineSetter_Copy(DstStageMask, VkPipelineStageFlags2, dstStageMask);
	DefineSetter_Copy(DstAccessMask, VkAccessFlags2, dstAccessMask);
	DefineSetter_Copy(SrcQueueFamilyIndex, uint32_t, srcQueueFamilyIndex);
	DefineSetter_Copy(DstQueueFamilyIndex, uint32_t, dstQueueFamilyIndex);
	DefineSetter_Copy(Tensor, VkTensorARM, tensor);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorMemoryBarrierARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorDependencyInfoARM) {
	StructureClassHeader(TensorDependencyInfoARM);
	DefineSetter_Copy(TensorMemoryBarrierCount, uint32_t, tensorMemoryBarrierCount);
	DefineSetter_ArrayRef(TensorMemoryBarriers, const VkTensorMemoryBarrierARM, tensorMemoryBarriers, tensorMemoryBarrierCount);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorDependencyInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTensorFeaturesARM) {
	StructureClassHeader(PhysicalDeviceTensorFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTensorFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DeviceTensorMemoryRequirementsARM) {
	StructureClassHeader(DeviceTensorMemoryRequirementsARM);
	DefineSetter_Ref(CreateInfo, const VkTensorCreateInfoARM, createInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(DeviceTensorMemoryRequirementsARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorCopyARM) {
	StructureClassHeader(TensorCopyARM);
	DefineSetter_Copy(DimensionCount, uint32_t, dimensionCount);
	DefineSetter_ArrayRef(SrcOffset, const uint64_t, srcOffset, dimensionCount);
	DefineSetter_ArrayRef(DstOffset, const uint64_t, dstOffset, dimensionCount);
	DefineSetter_ArrayRef(Extent, const uint64_t, extent, dimensionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorCopyARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyTensorInfoARM) {
	StructureClassHeader(CopyTensorInfoARM);
	DefineSetter_Copy(SrcTensor, VkTensorARM, srcTensor);
	DefineSetter_Copy(DstTensor, VkTensorARM, dstTensor);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkTensorCopyARM, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyTensorInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MemoryDedicatedAllocateInfoTensorARM) {
	StructureClassHeader(MemoryDedicatedAllocateInfoTensorARM);
	DefineSetter_Copy(Tensor, VkTensorARM, tensor);
};
VK_ENCAPSULATION_STRUCTURE_END(MemoryDedicatedAllocateInfoTensorARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalTensorInfoARM) {
	StructureClassHeader(PhysicalDeviceExternalTensorInfoARM);
	DefineSetter_Copy(Flags, VkTensorCreateFlagsARM, flags);
	DefineSetter_Ref(Description, const VkTensorDescriptionARM, description);
	DefineSetter_Copy(HandleType, VkExternalMemoryHandleTypeFlagBits, handleType);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalTensorInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalTensorPropertiesARM) {
	StructureClassHeader(ExternalTensorPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalTensorPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalMemoryTensorCreateInfoARM) {
	StructureClassHeader(ExternalMemoryTensorCreateInfoARM);
	DefineSetter_Copy(HandleTypes, VkExternalMemoryHandleTypeFlags, handleTypes);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalMemoryTensorCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorBufferTensorFeaturesARM) {
	StructureClassHeader(PhysicalDeviceDescriptorBufferTensorFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorBufferTensorFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorBufferTensorPropertiesARM) {
	StructureClassHeader(PhysicalDeviceDescriptorBufferTensorPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorBufferTensorPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DescriptorGetTensorInfoARM) {
	StructureClassHeader(DescriptorGetTensorInfoARM);
	DefineSetter_Copy(TensorView, VkTensorViewARM, tensorView);
};
VK_ENCAPSULATION_STRUCTURE_END(DescriptorGetTensorInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorCaptureDescriptorDataInfoARM) {
	StructureClassHeader(TensorCaptureDescriptorDataInfoARM);
	DefineSetter_Copy(Tensor, VkTensorARM, tensor);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorCaptureDescriptorDataInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TensorViewCaptureDescriptorDataInfoARM) {
	StructureClassHeader(TensorViewCaptureDescriptorDataInfoARM);
	DefineSetter_Copy(TensorView, VkTensorViewARM, tensorView);
};
VK_ENCAPSULATION_STRUCTURE_END(TensorViewCaptureDescriptorDataInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(FrameBoundaryTensorsARM) {
	StructureClassHeader(FrameBoundaryTensorsARM);
	DefineSetter_Copy(TensorCount, uint32_t, tensorCount);
	DefineSetter_ArrayRef(Tensors, const VkTensorARM, tensors, tensorCount);
};
VK_ENCAPSULATION_STRUCTURE_END(FrameBoundaryTensorsARM)

inline VkResult CreateTensorARM(const VkTensorCreateInfoARM& createInfo, HandleRef<VkTensorARM> tensor) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateTensorARM(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &tensor);
}
DefineRaiiFunction_ResultL(VkResult, CreateTensorARM, TensorCreateInfoARM, HandleRef<VkTensorARM>, tensor);

inline void DestroyTensorARM(HandleRef<VkTensorARM> tensor, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyTensorARM(DeviceContext::Device(), tensor, &allocator);
	tensor = VK_NULL_HANDLE;
}

inline VkResult CreateTensorViewARM(const VkTensorViewCreateInfoARM& createInfo, HandleRef<VkTensorViewARM> view) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateTensorViewARM(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &view);
}
DefineRaiiFunction_ResultL(VkResult, CreateTensorViewARM, TensorViewCreateInfoARM, HandleRef<VkTensorViewARM>, view);

inline void DestroyTensorViewARM(HandleRef<VkTensorViewARM> tensorView, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyTensorViewARM(DeviceContext::Device(), tensorView, &allocator);
	tensorView = VK_NULL_HANDLE;
}

inline void GetTensorMemoryRequirementsARM(const VkTensorMemoryRequirementsInfoARM& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetTensorMemoryRequirementsARM(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetTensorMemoryRequirementsARM, TensorMemoryRequirementsInfoARM, VkMemoryRequirements2&, memoryRequirements);

inline VkResult BindTensorMemoryARM(ArrayRef<const VkBindTensorMemoryInfoARM> bindInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindTensorMemoryARM(DeviceContext::Device(), bindInfos.size(), bindInfos);
}
DefineRaiiFunction_Result(VkResult, BindTensorMemoryARM, BindTensorMemoryInfoARM);

inline void GetDeviceTensorMemoryRequirementsARM(const VkDeviceTensorMemoryRequirementsARM& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceTensorMemoryRequirementsARM(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetDeviceTensorMemoryRequirementsARM, DeviceTensorMemoryRequirementsARM, VkMemoryRequirements2&, memoryRequirements);

inline void CmdCopyTensorARM(const VkCopyTensorInfoARM& copyTensorInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyTensorARM(ThreadContext::CommandBuffer(), &copyTensorInfo);
}
DefineRaiiFunction(CmdCopyTensorARM, CopyTensorInfoARM);

inline void GetPhysicalDeviceExternalTensorPropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalTensorInfoARM& externalTensorInfo, VkExternalTensorPropertiesARM& externalTensorProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceExternalTensorPropertiesARM(physicalDevice, &externalTensorInfo, &externalTensorProperties);
}
inline void GetPhysicalDeviceExternalTensorPropertiesARM(const VkPhysicalDeviceExternalTensorInfoARM& externalTensorInfo, VkExternalTensorPropertiesARM& externalTensorProperties) {
	GetPhysicalDeviceExternalTensorPropertiesARM(DeviceContext::PhysicalDevice(), externalTensorInfo, externalTensorProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceExternalTensorPropertiesARM, PhysicalDeviceExternalTensorInfoARM, VkExternalTensorPropertiesARM&, externalTensorProperties);

inline VkResult GetTensorOpaqueCaptureDescriptorDataARM(const VkTensorCaptureDescriptorDataInfoARM& info, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetTensorOpaqueCaptureDescriptorDataARM(DeviceContext::Device(), &info, data);
}
DefineRaiiFunction_ResultL(VkResult, GetTensorOpaqueCaptureDescriptorDataARM, TensorCaptureDescriptorDataInfoARM, ArrayRef<void>, data);
inline VkResult GetTensorOpaqueCaptureDescriptorDataARM(const VkTensorCaptureDescriptorDataInfoARM& info, IsNotRangeOrPointer auto& data) {
	return GetTensorOpaqueCaptureDescriptorDataARM(info, { 0, &data });
}
DefineRaiiFunction_ResultL(VkResult, GetTensorOpaqueCaptureDescriptorDataARM, TensorCaptureDescriptorDataInfoARM, IsNotRangeOrPointer auto&, data);

inline VkResult GetTensorViewOpaqueCaptureDescriptorDataARM(const VkTensorViewCaptureDescriptorDataInfoARM& info, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetTensorViewOpaqueCaptureDescriptorDataARM(DeviceContext::Device(), &info, data);
}
DefineRaiiFunction_ResultL(VkResult, GetTensorViewOpaqueCaptureDescriptorDataARM, TensorViewCaptureDescriptorDataInfoARM, ArrayRef<void>, data);
inline VkResult GetTensorViewOpaqueCaptureDescriptorDataARM(const VkTensorViewCaptureDescriptorDataInfoARM& info, IsNotRangeOrPointer auto& data) {
	return GetTensorViewOpaqueCaptureDescriptorDataARM(info, { 0, &data });
}
DefineRaiiFunction_ResultL(VkResult, GetTensorViewOpaqueCaptureDescriptorDataARM, TensorViewCaptureDescriptorDataInfoARM, IsNotRangeOrPointer auto&, data);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderModuleIdentifierFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderModuleIdentifierFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderModuleIdentifierFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderModuleIdentifierPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceShaderModuleIdentifierPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderModuleIdentifierPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineShaderStageModuleIdentifierCreateInfoEXT) {
	StructureClassHeader(PipelineShaderStageModuleIdentifierCreateInfoEXT);
	DefineSetter_Copy(IdentifierSize, uint32_t, identifierSize);
	DefineSetter_ArrayRef(Identifier, const uint8_t, identifier, identifierSize);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineShaderStageModuleIdentifierCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ShaderModuleIdentifierEXT) {
	StructureClassHeader(ShaderModuleIdentifierEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(ShaderModuleIdentifierEXT)

inline void GetShaderModuleIdentifierEXT(VkShaderModule shaderModule, VkShaderModuleIdentifierEXT& identifier) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetShaderModuleIdentifierEXT(DeviceContext::Device(), shaderModule, &identifier);
}

inline void GetShaderModuleCreateInfoIdentifierEXT(const VkShaderModuleCreateInfo& createInfo, VkShaderModuleIdentifierEXT& identifier) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetShaderModuleCreateInfoIdentifierEXT(DeviceContext::Device(), &createInfo, &identifier);
}
DefineRaiiFunction_L(GetShaderModuleCreateInfoIdentifierEXT, ShaderModuleCreateInfo, VkShaderModuleIdentifierEXT&, identifier);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceOpticalFlowFeaturesNV) {
	StructureClassHeader(PhysicalDeviceOpticalFlowFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceOpticalFlowFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceOpticalFlowPropertiesNV) {
	StructureClassHeader(PhysicalDeviceOpticalFlowPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceOpticalFlowPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(OpticalFlowImageFormatInfoNV) {
	StructureClassHeader(OpticalFlowImageFormatInfoNV);
	DefineSetter_Copy(Usage, VkOpticalFlowUsageFlagsNV, usage);
};
VK_ENCAPSULATION_STRUCTURE_END(OpticalFlowImageFormatInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(OpticalFlowImageFormatPropertiesNV) {
	StructureClassHeader(OpticalFlowImageFormatPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(OpticalFlowImageFormatPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(OpticalFlowSessionCreateInfoNV) {
	StructureClassHeader(OpticalFlowSessionCreateInfoNV);
	DefineSetter_Copy(Width, uint32_t, width);
	DefineSetter_Copy(Height, uint32_t, height);
	DefineSetter_Copy(ImageFormat, VkFormat, imageFormat);
	DefineSetter_Copy(FlowVectorFormat, VkFormat, flowVectorFormat);
	DefineSetter_Copy(CostFormat, VkFormat, costFormat);
	DefineSetter_Copy(OutputGridSize, VkOpticalFlowGridSizeFlagsNV, outputGridSize);
	DefineSetter_Copy(HintGridSize, VkOpticalFlowGridSizeFlagsNV, hintGridSize);
	DefineSetter_Copy(PerformanceLevel, VkOpticalFlowPerformanceLevelNV, performanceLevel);
	DefineSetter_Copy(Flags, VkOpticalFlowSessionCreateFlagsNV, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(OpticalFlowSessionCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(OpticalFlowSessionCreatePrivateDataInfoNV) {
	StructureClassHeader(OpticalFlowSessionCreatePrivateDataInfoNV);
	DefineSetter_Copy(Id, uint32_t, id);
	DefineSetter_Copy(Size, uint32_t, size);
	DefineSetter_ArrayRef(PrivateData, const void, privateData, size);
};
VK_ENCAPSULATION_STRUCTURE_END(OpticalFlowSessionCreatePrivateDataInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(OpticalFlowExecuteInfoNV) {
	StructureClassHeader(OpticalFlowExecuteInfoNV);
	DefineSetter_Copy(Flags, VkOpticalFlowExecuteFlagsNV, flags);
	DefineSetter_Copy(RegionCount, uint32_t, regionCount);
	DefineSetter_ArrayRef(Regions, const VkRect2D, regions, regionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(OpticalFlowExecuteInfoNV)

inline VkResult GetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV& opticalFlowImageFormatInfo, uint32_t& formatCount, ArrayRef<VkOpticalFlowImageFormatPropertiesNV> imageFormatProperties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, &opticalFlowImageFormatInfo, &formatCount, imageFormatProperties);
}
inline VkResult GetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV& opticalFlowImageFormatInfo, IsDynamicArray<VkOpticalFlowImageFormatPropertiesNV> auto& imageFormatProperties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, opticalFlowImageFormatInfo, count);
	if (result == VK_SUCCESS)
		imageFormatProperties.resize(count),
		result = GetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, opticalFlowImageFormatInfo, count, imageFormatProperties);
	return result;
}
inline VkResult GetPhysicalDeviceOpticalFlowImageFormatsNV(const VkOpticalFlowImageFormatInfoNV& opticalFlowImageFormatInfo, uint32_t& formatCount, ArrayRef<VkOpticalFlowImageFormatPropertiesNV> imageFormatProperties = {}) {
	return GetPhysicalDeviceOpticalFlowImageFormatsNV(DeviceContext::PhysicalDevice(), opticalFlowImageFormatInfo, formatCount, imageFormatProperties);
}
inline VkResult GetPhysicalDeviceOpticalFlowImageFormatsNV(const VkOpticalFlowImageFormatInfoNV& opticalFlowImageFormatInfo, IsDynamicArray<VkOpticalFlowImageFormatPropertiesNV> auto& imageFormatProperties) {
	return GetPhysicalDeviceOpticalFlowImageFormatsNV(DeviceContext::PhysicalDevice(), opticalFlowImageFormatInfo, imageFormatProperties);
}
DefineRaiiFunction_ResultL(VkResult, GetPhysicalDeviceOpticalFlowImageFormatsNV, OpticalFlowImageFormatInfoNV, IsDynamicArray<VkOpticalFlowImageFormatPropertiesNV> auto&, imageFormatProperties);

inline VkResult CreateOpticalFlowSessionNV(const VkOpticalFlowSessionCreateInfoNV& createInfo, HandleRef<VkOpticalFlowSessionNV> session) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateOpticalFlowSessionNV(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &session);
}
DefineRaiiFunction_ResultL(VkResult, CreateOpticalFlowSessionNV, OpticalFlowSessionCreateInfoNV, HandleRef<VkOpticalFlowSessionNV>, session);

inline void DestroyOpticalFlowSessionNV(HandleRef<VkOpticalFlowSessionNV> session, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyOpticalFlowSessionNV(DeviceContext::Device(), session, &allocator);
	session = VK_NULL_HANDLE;
}

inline VkResult BindOpticalFlowSessionImageNV(VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindOpticalFlowSessionImageNV(DeviceContext::Device(), session, bindingPoint, view, layout);
}

inline void CmdOpticalFlowExecuteNV(VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV& executeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdOpticalFlowExecuteNV(ThreadContext::CommandBuffer(), session, &executeInfo);
}
DefineRaiiFunction_R(CmdOpticalFlowExecuteNV, VkOpticalFlowSessionNV, session, OpticalFlowExecuteInfoNV);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLegacyDitheringFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceLegacyDitheringFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLegacyDitheringFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceAntiLagFeaturesAMD) {
	StructureClassHeader(PhysicalDeviceAntiLagFeaturesAMD);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceAntiLagFeaturesAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AntiLagPresentationInfoAMD) {
	StructureClassHeader(AntiLagPresentationInfoAMD);
	DefineSetter_Copy(Stage, VkAntiLagStageAMD, stage);
	DefineSetter_Copy(FrameIndex, uint64_t, frameIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(AntiLagPresentationInfoAMD)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AntiLagDataAMD) {
	StructureClassHeader(AntiLagDataAMD);
	DefineSetter_Copy(Mode, VkAntiLagModeAMD, mode);
	DefineSetter_Copy(MaxFPS, uint32_t, maxFPS);
	DefineSetter_Ref(PresentationInfo, const VkAntiLagPresentationInfoAMD, presentationInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(AntiLagDataAMD)

inline void AntiLagUpdateAMD(const VkAntiLagDataAMD& data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkAntiLagUpdateAMD(DeviceContext::Device(), &data);
}
DefineRaiiFunction(AntiLagUpdateAMD, AntiLagDataAMD);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderObjectFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderObjectFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderObjectFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderObjectPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceShaderObjectPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderObjectPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ShaderCreateInfoEXT) {
	StructureClassHeader(ShaderCreateInfoEXT, .pName = "main");
	DefineSetter_Copy(Flags, VkShaderCreateFlagsEXT, flags);
	DefineSetter_Copy(Stage, VkShaderStageFlagBits, stage);
	DefineSetter_Copy(NextStage, VkShaderStageFlags, nextStage);
	DefineSetter_Copy(CodeType, VkShaderCodeTypeEXT, codeType);
	DefineSetter_Copy(CodeSize, size_t, codeSize);
	DefineSetter_ArrayRef(Code, const void, code, codeSize);
	DefineSetter_ArrayRefIgnoreC(Name, const char, name);
	DefineSetter_Copy(SetLayoutCount, uint32_t, setLayoutCount);
	DefineSetter_ArrayRef(SetLayouts, const VkDescriptorSetLayout, setLayouts, setLayoutCount);
	DefineSetter_Copy(PushConstantRangeCount, uint32_t, pushConstantRangeCount);
	DefineSetter_ArrayRef(PushConstantRanges, const VkPushConstantRange, pushConstantRanges, pushConstantRangeCount);
	DefineSetter_Ref(SpecializationInfo, const VkSpecializationInfo, specializationInfo);
};
VK_ENCAPSULATION_STRUCTURE_END(ShaderCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DepthClampRangeEXT) {
	StructureClassHeader_NoSType(DepthClampRangeEXT);
	DefineSetter_Copy(MinDepthClamp, float, minDepthClamp);
	DefineSetter_Copy(MaxDepthClamp, float, maxDepthClamp);
};
VK_ENCAPSULATION_STRUCTURE_END(DepthClampRangeEXT)

inline VkResult CreateShadersEXT(ArrayRef<const VkShaderCreateInfoEXT> createInfos, HandleArrayRef<VkShaderEXT> shaders) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateShadersEXT(DeviceContext::Device(), createInfos.size(), createInfos, ThreadContext::PAllocator(), shaders);
}
DefineRaiiFunction_ResultL(VkResult, CreateShadersEXT, ShaderCreateInfoEXT, HandleRef<VkShaderEXT>, shader);

inline void DestroyShaderEXT(HandleRef<VkShaderEXT> shader, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyShaderEXT(DeviceContext::Device(), shader, &allocator);
}

inline VkResult GetShaderBinaryDataEXT(VkShaderEXT shader, size_t& dataSize, ArrayRef<void> data = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetShaderBinaryDataEXT(DeviceContext::Device(), shader, &dataSize, data);
}
inline VkResult GetShaderBinaryDataEXT(VkShaderEXT shader, size_t& dataSize, IsNotRangeOrPointer auto& data) {
	return GetShaderBinaryDataEXT(shader, dataSize, { 0, &data });
}
inline VkResult GetShaderBinaryDataEXT(VkShaderEXT shader, IsDynamicByteArray auto& data) {
	size_t size = 0;
	VkResult result = GetShaderBinaryDataEXT(shader, size);
	if (result == VK_SUCCESS)
		data.resize(size),
		result = GetShaderBinaryDataEXT(shader, size, data);
	return result;
}

inline void CmdBindShadersEXT(ArrayRef<const VkShaderStageFlagBits> stages, ArrayRef<const VkShaderEXT> shaders) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindShadersEXT(ThreadContext::CommandBuffer(), stages.size(), stages, shaders);
}

inline void CmdSetDepthClampRangeEXT(VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT& depthClampRange) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetDepthClampRangeEXT(ThreadContext::CommandBuffer(), depthClampMode, &depthClampRange);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTilePropertiesFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceTilePropertiesFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTilePropertiesFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TilePropertiesQCOM) {
	StructureClassHeader(TilePropertiesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(TilePropertiesQCOM)

inline VkResult GetFramebufferTilePropertiesQCOM(VkFramebuffer framebuffer, uint32_t& propertiesCount, ArrayRef<VkTilePropertiesQCOM> properties = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetFramebufferTilePropertiesQCOM(DeviceContext::Device(), framebuffer, &propertiesCount, properties);
}
inline VkResult GetFramebufferTilePropertiesQCOM(VkFramebuffer framebuffer, IsDynamicArray<VkTilePropertiesQCOM> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetFramebufferTilePropertiesQCOM(framebuffer, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetFramebufferTilePropertiesQCOM(framebuffer, count, properties);
	return result;
}

inline VkResult GetDynamicRenderingTilePropertiesQCOM(const VkRenderingInfo& renderingInfo, VkTilePropertiesQCOM& properties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDynamicRenderingTilePropertiesQCOM(DeviceContext::Device(), &renderingInfo, &properties);
}
DefineRaiiFunction_ResultL(VkResult, GetDynamicRenderingTilePropertiesQCOM, RenderingInfo, VkTilePropertiesQCOM&, properties);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceAmigoProfilingFeaturesSEC) {
	StructureClassHeader(PhysicalDeviceAmigoProfilingFeaturesSEC);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceAmigoProfilingFeaturesSEC)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AmigoProfilingSubmitInfoSEC) {
	StructureClassHeader(AmigoProfilingSubmitInfoSEC);
	DefineSetter_Copy(FirstDrawTimestamp, uint64_t, firstDrawTimestamp);
	DefineSetter_Copy(SwapBufferTimestamp, uint64_t, swapBufferTimestamp);
};
VK_ENCAPSULATION_STRUCTURE_END(AmigoProfilingSubmitInfoSEC)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingInvocationReorderPropertiesNV) {
	StructureClassHeader(PhysicalDeviceRayTracingInvocationReorderPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingInvocationReorderPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingInvocationReorderFeaturesNV) {
	StructureClassHeader(PhysicalDeviceRayTracingInvocationReorderFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingInvocationReorderFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeVectorPropertiesNV) {
	StructureClassHeader(PhysicalDeviceCooperativeVectorPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeVectorPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeVectorFeaturesNV) {
	StructureClassHeader(PhysicalDeviceCooperativeVectorFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeVectorFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CooperativeVectorPropertiesNV) {
	StructureClassHeader(CooperativeVectorPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(CooperativeVectorPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ConvertCooperativeVectorMatrixInfoNV) {
	StructureClassHeader(ConvertCooperativeVectorMatrixInfoNV);
	DefineSetter_Copy(SrcSize, size_t, srcSize);
	DefineSetter_Copy(SrcData, VkDeviceOrHostAddressConstKHR, srcData);
	DefineSetter_Ref(DstSize, size_t, dstSize);
	DefineSetter_Copy(DstData, VkDeviceOrHostAddressKHR, dstData);
	DefineSetter_Copy(SrcComponentType, VkComponentTypeKHR, srcComponentType);
	DefineSetter_Copy(DstComponentType, VkComponentTypeKHR, dstComponentType);
	DefineSetter_Copy(NumRows, uint32_t, numRows);
	DefineSetter_Copy(NumColumns, uint32_t, numColumns);
	DefineSetter_Copy(SrcLayout, VkCooperativeVectorMatrixLayoutNV, srcLayout);
	DefineSetter_Copy(SrcStride, size_t, srcStride);
	DefineSetter_Copy(DstLayout, VkCooperativeVectorMatrixLayoutNV, dstLayout);
	DefineSetter_Copy(DstStride, size_t, dstStride);
};
VK_ENCAPSULATION_STRUCTURE_END(ConvertCooperativeVectorMatrixInfoNV)

inline VkResult GetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkCooperativeVectorPropertiesNV> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceCooperativeVectorPropertiesNV(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice physicalDevice, IsDynamicArray<VkCooperativeVectorPropertiesNV> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceCooperativeVectorPropertiesNV(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceCooperativeVectorPropertiesNV(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceCooperativeVectorPropertiesNV(uint32_t& propertyCount, ArrayRef<VkCooperativeVectorPropertiesNV> properties = {}) {
	return GetPhysicalDeviceCooperativeVectorPropertiesNV(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeVectorPropertiesNV(IsDynamicArray<VkCooperativeVectorPropertiesNV> auto& properties) {
	return GetPhysicalDeviceCooperativeVectorPropertiesNV(DeviceContext::PhysicalDevice(), properties);
}

inline VkResult ConvertCooperativeVectorMatrixNV(const VkConvertCooperativeVectorMatrixInfoNV& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkConvertCooperativeVectorMatrixNV(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkResult, ConvertCooperativeVectorMatrixNV, ConvertCooperativeVectorMatrixInfoNV);

inline void CmdConvertCooperativeVectorMatrixNV(ArrayRef<const VkConvertCooperativeVectorMatrixInfoNV> infos) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdConvertCooperativeVectorMatrixNV(ThreadContext::CommandBuffer(), infos.size(), infos);
}
DefineRaiiFunction(CmdConvertCooperativeVectorMatrixNV, ConvertCooperativeVectorMatrixInfoNV);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV) {
	StructureClassHeader(PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExtendedSparseAddressSpacePropertiesNV) {
	StructureClassHeader(PhysicalDeviceExtendedSparseAddressSpacePropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExtendedSparseAddressSpacePropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLegacyVertexAttributesFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceLegacyVertexAttributesFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLegacyVertexAttributesFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLegacyVertexAttributesPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceLegacyVertexAttributesPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLegacyVertexAttributesPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(LayerSettingEXT) {
	StructureClassHeader_NoSType(LayerSettingEXT);
	DefineSetter_ArrayRefIgnoreC(LayerName, const char, layerName);
	DefineSetter_ArrayRefIgnoreC(SettingName, const char, settingName);
	DefineSetter_Copy(Type, VkLayerSettingTypeEXT, type);
	DefineSetter_Copy(ValueCount, uint32_t, valueCount);
	DefineSetter_ArrayRef(Values, const void, values, valueCount);
	_&  Values(const IsNotRangeOrPointer auto& value) &  { return Values({ 1, &value }); }
	_&& Values(const IsNotRangeOrPointer auto& value) && { return std::move(Values(value)); }
	_&  Values(const char*& value) &  { return Values({ 1, &value }); }
	_&& Values(const char*& value) && { return std::move(Values(value)); }
	_&  Values(const char8_t*& value) &  { return Values({ 1, &value }); }
	_&& Values(const char8_t*& value) && { return std::move(Values(value)); }
	_&  Values(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(LayerSettingEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(LayerSettingsCreateInfoEXT) {
	StructureClassHeader(LayerSettingsCreateInfoEXT);
	DefineSetter_Copy(SettingCount, uint32_t, settingCount);
	DefineSetter_ArrayRef(Settings, const VkLayerSettingEXT, settings, settingCount);
};
VK_ENCAPSULATION_STRUCTURE_END(LayerSettingsCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderCoreBuiltinsFeaturesARM) {
	StructureClassHeader(PhysicalDeviceShaderCoreBuiltinsFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderCoreBuiltinsFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderCoreBuiltinsPropertiesARM) {
	StructureClassHeader(PhysicalDeviceShaderCoreBuiltinsPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderCoreBuiltinsPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT) {
	StructureClassHeader(PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(LatencySleepModeInfoNV) {
	StructureClassHeader(LatencySleepModeInfoNV);
	DefineSetter_Copy(LowLatencyMode, VkBool32, lowLatencyMode);
	DefineSetter_Copy(LowLatencyBoost, VkBool32, lowLatencyBoost);
	DefineSetter_Copy(MinimumIntervalUs, uint32_t, minimumIntervalUs);
};
VK_ENCAPSULATION_STRUCTURE_END(LatencySleepModeInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(LatencySleepInfoNV) {
	StructureClassHeader(LatencySleepInfoNV);
	DefineSetter_Copy(SignalSemaphore, VkSemaphore, signalSemaphore);
	DefineSetter_Copy(Value, uint64_t, value);
};
VK_ENCAPSULATION_STRUCTURE_END(LatencySleepInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SetLatencyMarkerInfoNV) {
	StructureClassHeader(SetLatencyMarkerInfoNV);
	DefineSetter_Copy(PresentID, uint64_t, presentID);
	DefineSetter_Copy(Marker, VkLatencyMarkerNV, marker);
};
VK_ENCAPSULATION_STRUCTURE_END(SetLatencyMarkerInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(LatencyTimingsFrameReportNV) {
	StructureClassHeader(LatencyTimingsFrameReportNV);
};
VK_ENCAPSULATION_STRUCTURE_END(LatencyTimingsFrameReportNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GetLatencyMarkerInfoNV) {
	StructureClassHeader(GetLatencyMarkerInfoNV);
	DefineSetter_ArrayRefIgnoreC(Timings, VkLatencyTimingsFrameReportNV, timings);
};
VK_ENCAPSULATION_STRUCTURE_END(GetLatencyMarkerInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(LatencySubmissionPresentIdNV) {
	StructureClassHeader(LatencySubmissionPresentIdNV);
	DefineSetter_Copy(PresentID, uint64_t, presentID);
};
VK_ENCAPSULATION_STRUCTURE_END(LatencySubmissionPresentIdNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SwapchainLatencyCreateInfoNV) {
	StructureClassHeader(SwapchainLatencyCreateInfoNV);
	DefineSetter_Copy(LatencyModeEnable, VkBool32, latencyModeEnable);
};
VK_ENCAPSULATION_STRUCTURE_END(SwapchainLatencyCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(OutOfBandQueueTypeInfoNV) {
	StructureClassHeader(OutOfBandQueueTypeInfoNV);
	DefineSetter_Copy(QueueType, VkOutOfBandQueueTypeNV, queueType);
};
VK_ENCAPSULATION_STRUCTURE_END(OutOfBandQueueTypeInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(LatencySurfaceCapabilitiesNV) {
	StructureClassHeader(LatencySurfaceCapabilitiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(LatencySurfaceCapabilitiesNV)

inline VkResult SetLatencySleepModeNV(VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV& sleepModeInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkSetLatencySleepModeNV(DeviceContext::Device(), swapchain, &sleepModeInfo);
}
DefineRaiiFunction_ResultR(VkResult, SetLatencySleepModeNV, VkSwapchainKHR, swapchain, LatencySleepModeInfoNV);

inline VkResult LatencySleepNV(VkSwapchainKHR swapchain, const VkLatencySleepInfoNV& sleepInfo) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkLatencySleepNV(DeviceContext::Device(), swapchain, &sleepInfo);
}
DefineRaiiFunction_ResultR(VkResult, LatencySleepNV, VkSwapchainKHR, swapchain, LatencySleepInfoNV);

inline void SetLatencyMarkerNV(VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV& latencyMarkerInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkSetLatencyMarkerNV(DeviceContext::Device(), swapchain, &latencyMarkerInfo);
}
DefineRaiiFunction_R(SetLatencyMarkerNV, VkSwapchainKHR, swapchain, SetLatencyMarkerInfoNV);

inline void GetLatencyTimingsNV(VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV& latencyMarkerInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetLatencyTimingsNV(DeviceContext::Device(), swapchain, &latencyMarkerInfo);
}

inline void QueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV& queueTypeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkQueueNotifyOutOfBandNV(queue, &queueTypeInfo);
}
DefineRaiiFunction_R(QueueNotifyOutOfBandNV, VkQueue, queue, OutOfBandQueueTypeInfoNV);
inline void QueueNotifyOutOfBandNV(const VkOutOfBandQueueTypeInfoNV& queueTypeInfo) {
	QueueNotifyOutOfBandNV(ThreadContext::Queue(), queueTypeInfo);
}
DefineRaiiFunction(QueueNotifyOutOfBandNV, OutOfBandQueueTypeInfoNV);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDataGraphFeaturesARM) {
	StructureClassHeader(PhysicalDeviceDataGraphFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDataGraphFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineConstantARM) {
	StructureClassHeader(DataGraphPipelineConstantARM);
	DefineSetter_Copy(Id, uint32_t, id);
	DefineSetter_ArrayRefIgnoreC(ConstantData, const void, constantData);
	_&  ConstantData(const IsNotRangeOrPointer auto& constantData) &  { pConstantData = &constantData; return *this; }
	_&& ConstantData(const IsNotRangeOrPointer auto& constantData) && { return std::move(ConstantData(constantData)); }
	_&  ConstantData(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineConstantARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineResourceInfoARM) {
	StructureClassHeader(DataGraphPipelineResourceInfoARM);
	DefineSetter_Copy(DescriptorSet, uint32_t, descriptorSet);
	DefineSetter_Copy(Binding, uint32_t, binding);
	DefineSetter_Copy(ArrayElement, uint32_t, arrayElement);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineResourceInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineCompilerControlCreateInfoARM) {
	StructureClassHeader(DataGraphPipelineCompilerControlCreateInfoARM);
	DefineSetter_ArrayRefIgnoreC(VendorOptions, const char, vendorOptions);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineCompilerControlCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineCreateInfoARM) {
	StructureClassHeader(DataGraphPipelineCreateInfoARM);
	DefineSetter_Copy(Flags, VkPipelineCreateFlags2KHR, flags);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(ResourceInfoCount, uint32_t, resourceInfoCount);
	DefineSetter_ArrayRef(ResourceInfos, const VkDataGraphPipelineResourceInfoARM, resourceInfos, resourceInfoCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineShaderModuleCreateInfoARM) {
	StructureClassHeader(DataGraphPipelineShaderModuleCreateInfoARM, .pName = "main");
	DefineSetter_Copy(Module, VkShaderModule, module);
	DefineSetter_ArrayRefIgnoreC(Name, const char, name);
	DefineSetter_Ref(SpecializationInfo, const VkSpecializationInfo, specializationInfo);
	DefineSetter_Copy(ConstantCount, uint32_t, constantCount);
	DefineSetter_ArrayRef(Constants, const VkDataGraphPipelineConstantARM, constants, constantCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineShaderModuleCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineSessionCreateInfoARM) {
	StructureClassHeader(DataGraphPipelineSessionCreateInfoARM);
	DefineSetter_Copy(Flags, VkDataGraphPipelineSessionCreateFlagsARM, flags);
	DefineSetter_Copy(DataGraphPipeline, VkPipeline, dataGraphPipeline);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineSessionCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineSessionBindPointRequirementsInfoARM) {
	StructureClassHeader(DataGraphPipelineSessionBindPointRequirementsInfoARM);
	DefineSetter_Copy(Session, VkDataGraphPipelineSessionARM, session);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineSessionBindPointRequirementsInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineSessionBindPointRequirementARM) {
	StructureClassHeader(DataGraphPipelineSessionBindPointRequirementARM);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineSessionBindPointRequirementARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineSessionMemoryRequirementsInfoARM) {
	StructureClassHeader(DataGraphPipelineSessionMemoryRequirementsInfoARM);
	DefineSetter_Copy(Session, VkDataGraphPipelineSessionARM, session);
	DefineSetter_Copy(BindPoint, VkDataGraphPipelineSessionBindPointARM, bindPoint);
	DefineSetter_Copy(ObjectIndex, uint32_t, objectIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineSessionMemoryRequirementsInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BindDataGraphPipelineSessionMemoryInfoARM) {
	StructureClassHeader(BindDataGraphPipelineSessionMemoryInfoARM);
	DefineSetter_Copy(Session, VkDataGraphPipelineSessionARM, session);
	DefineSetter_Copy(BindPoint, VkDataGraphPipelineSessionBindPointARM, bindPoint);
	DefineSetter_Copy(ObjectIndex, uint32_t, objectIndex);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
	DefineSetter_Copy(MemoryOffset, VkDeviceSize, memoryOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(BindDataGraphPipelineSessionMemoryInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineInfoARM) {
	StructureClassHeader(DataGraphPipelineInfoARM);
	DefineSetter_Copy(DataGraphPipeline, VkPipeline, dataGraphPipeline);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelinePropertyQueryResultARM) {
	StructureClassHeader(DataGraphPipelinePropertyQueryResultARM);
	DefineSetter_ArrayRefIgnoreC(Data, void, data);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelinePropertyQueryResultARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineIdentifierCreateInfoARM) {
	StructureClassHeader(DataGraphPipelineIdentifierCreateInfoARM);
	DefineSetter_Copy(IdentifierSize, uint32_t, identifierSize);
	DefineSetter_ArrayRef(Identifier, const uint8_t, identifier, identifierSize);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineIdentifierCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineDispatchInfoARM) {
	StructureClassHeader(DataGraphPipelineDispatchInfoARM);
	DefineSetter_Copy(Flags, VkDataGraphPipelineDispatchFlagsARM, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineDispatchInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PhysicalDeviceDataGraphProcessingEngineARM) {
	StructureClassHeader_NoSType(PhysicalDeviceDataGraphProcessingEngineARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDataGraphProcessingEngineARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PhysicalDeviceDataGraphOperationSupportARM) {
	StructureClassHeader_NoSType(PhysicalDeviceDataGraphOperationSupportARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDataGraphOperationSupportARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyDataGraphPropertiesARM) {
	StructureClassHeader(QueueFamilyDataGraphPropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyDataGraphPropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphProcessingEngineCreateInfoARM) {
	StructureClassHeader(DataGraphProcessingEngineCreateInfoARM);
	DefineSetter_Copy(ProcessingEngineCount, uint32_t, processingEngineCount);
	DefineSetter_ArrayRef(ProcessingEngines, VkPhysicalDeviceDataGraphProcessingEngineARM, processingEngines, processingEngineCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphProcessingEngineCreateInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM) {
	StructureClassHeader(PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM);
	DefineSetter_Copy(QueueFamilyIndex, uint32_t, queueFamilyIndex);
	DefineSetter_Copy(EngineType, VkPhysicalDeviceDataGraphProcessingEngineTypeARM, engineType);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(QueueFamilyDataGraphProcessingEnginePropertiesARM) {
	StructureClassHeader(QueueFamilyDataGraphProcessingEnginePropertiesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(QueueFamilyDataGraphProcessingEnginePropertiesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM) {
	StructureClassHeader(DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM);
	DefineSetter_Copy(Dimension, uint32_t, dimension);
	DefineSetter_Copy(ZeroCount, uint32_t, zeroCount);
	DefineSetter_Copy(GroupSize, uint32_t, groupSize);
};
VK_ENCAPSULATION_STRUCTURE_END(DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM)

inline VkResult CreateDataGraphPipelinesARM(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, ArrayRef<const VkDataGraphPipelineCreateInfoARM> createInfos, HandleArrayRef<VkPipeline> pipelines) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateDataGraphPipelinesARM(DeviceContext::Device(), deferredOperation, pipelineCache, createInfos.size(), createInfos, ThreadContext::PAllocator(), pipelines);
}

inline VkResult CreateDataGraphPipelineSessionARM(const VkDataGraphPipelineSessionCreateInfoARM& createInfo, HandleRef<VkDataGraphPipelineSessionARM> session) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateDataGraphPipelineSessionARM(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &session);
}
DefineRaiiFunction_ResultL(VkResult, CreateDataGraphPipelineSessionARM, DataGraphPipelineSessionCreateInfoARM, HandleRef<VkDataGraphPipelineSessionARM>, session);

inline VkResult GetDataGraphPipelineSessionBindPointRequirementsARM(const VkDataGraphPipelineSessionBindPointRequirementsInfoARM info, uint32_t& bindPointRequirementCount, ArrayRef<VkDataGraphPipelineSessionBindPointRequirementARM> bindPointRequirements = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDataGraphPipelineSessionBindPointRequirementsARM(DeviceContext::Device(), &info, &bindPointRequirementCount, bindPointRequirements);
}
inline VkResult GetDataGraphPipelineSessionBindPointRequirementsARM(const VkDataGraphPipelineSessionBindPointRequirementsInfoARM info, IsDynamicArray<VkDataGraphPipelineSessionBindPointRequirementARM> auto& bindPointRequirements) {
	uint32_t count = 0;
	VkResult result = GetDataGraphPipelineSessionBindPointRequirementsARM(info, count);
	if (result == VK_SUCCESS)
		bindPointRequirements.resize(count),
		result = GetDataGraphPipelineSessionBindPointRequirementsARM(info, count, bindPointRequirements);
	return result;
}
DefineRaiiFunction_ResultL(VkResult, GetDataGraphPipelineSessionBindPointRequirementsARM, DataGraphPipelineSessionBindPointRequirementsInfoARM, IsDynamicArray<VkDataGraphPipelineSessionBindPointRequirementARM> auto&, bindPointRequirements);

inline void GetDataGraphPipelineSessionMemoryRequirementsARM(const VkDataGraphPipelineSessionMemoryRequirementsInfoARM& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDataGraphPipelineSessionMemoryRequirementsARM(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetDataGraphPipelineSessionMemoryRequirementsARM, DataGraphPipelineSessionMemoryRequirementsInfoARM, VkMemoryRequirements2&, memoryRequirements);

inline VkResult BindDataGraphPipelineSessionMemoryARM(ArrayRef<const VkBindDataGraphPipelineSessionMemoryInfoARM> bindInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBindDataGraphPipelineSessionMemoryARM(DeviceContext::Device(), bindInfos.size(), bindInfos);
}
DefineRaiiFunction_Result(VkResult, BindDataGraphPipelineSessionMemoryARM, BindDataGraphPipelineSessionMemoryInfoARM);

inline void DestroyDataGraphPipelineSessionARM(HandleRef<VkDataGraphPipelineSessionARM> session, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyDataGraphPipelineSessionARM(DeviceContext::Device(), session, &allocator);
	session = VK_NULL_HANDLE;
}

inline void CmdDispatchDataGraphARM(VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDispatchDataGraphARM(ThreadContext::CommandBuffer(), session, &info);
}
DefineRaiiFunction_R(CmdDispatchDataGraphARM, VkDataGraphPipelineSessionARM, session, DataGraphPipelineDispatchInfoARM);

inline VkResult GetDataGraphPipelineAvailablePropertiesARM(const VkDataGraphPipelineInfoARM& pipelineInfo, uint32_t& propertiesCount, ArrayRef<VkDataGraphPipelinePropertyARM> properties = {}) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDataGraphPipelineAvailablePropertiesARM(DeviceContext::Device(), &pipelineInfo, &propertiesCount, properties);
}
inline VkResult GetDataGraphPipelineAvailablePropertiesARM(const VkDataGraphPipelineInfoARM& pipelineInfo, IsDynamicArray<VkDataGraphPipelinePropertyARM> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetDataGraphPipelineAvailablePropertiesARM(pipelineInfo, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetDataGraphPipelineAvailablePropertiesARM(pipelineInfo, count, properties);
	return result;
}
DefineRaiiFunction_ResultL(VkResult, GetDataGraphPipelineAvailablePropertiesARM, DataGraphPipelineInfoARM, IsDynamicArray<VkDataGraphPipelinePropertyARM> auto&, properties);

inline VkResult GetDataGraphPipelinePropertiesARM(const VkDataGraphPipelineInfoARM& pipelineInfo, ArrayRef<VkDataGraphPipelinePropertyQueryResultARM> properties) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDataGraphPipelinePropertiesARM(DeviceContext::Device(), &pipelineInfo, properties.size(), properties);
}
DefineRaiiFunction_ResultL(VkResult, GetDataGraphPipelinePropertiesARM, DataGraphPipelineInfoARM, ArrayRef<VkDataGraphPipelinePropertyQueryResultARM>, properties);

inline VkResult GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t& queueFamilyDataGraphPropertyCount, ArrayRef<VkQueueFamilyDataGraphPropertiesARM> queueFamilyDataGraphProperties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(physicalDevice, queueFamilyIndex, &queueFamilyDataGraphPropertyCount, queueFamilyDataGraphProperties);
}
inline VkResult GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IsDynamicArray<VkQueueFamilyDataGraphPropertiesARM> auto& queueFamilyDataGraphProperties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(physicalDevice, queueFamilyIndex, count);
	if (result == VK_SUCCESS)
		queueFamilyDataGraphProperties.resize(count),
		result = GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(physicalDevice, queueFamilyIndex, count, queueFamilyDataGraphProperties);
	return result;
}
inline VkResult GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(uint32_t queueFamilyIndex, uint32_t& queueFamilyDataGraphPropertyCount, ArrayRef<VkQueueFamilyDataGraphPropertiesARM> queueFamilyDataGraphProperties = {}) {
	return GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(DeviceContext::PhysicalDevice(), queueFamilyIndex, queueFamilyDataGraphPropertyCount, queueFamilyDataGraphProperties);
}
inline VkResult GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(uint32_t queueFamilyIndex, IsDynamicArray<VkQueueFamilyDataGraphPropertiesARM> auto& queueFamilyDataGraphProperties) {
	return GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(DeviceContext::PhysicalDevice(), queueFamilyIndex, queueFamilyDataGraphProperties);
}

inline void GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM& queueFamilyDataGraphProcessingEngineInfo, VkQueueFamilyDataGraphProcessingEnginePropertiesARM& queueFamilyDataGraphProcessingEngineProperties) {
	VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(physicalDevice, &queueFamilyDataGraphProcessingEngineInfo, &queueFamilyDataGraphProcessingEngineProperties);
}
inline void GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM& queueFamilyDataGraphProcessingEngineInfo, VkQueueFamilyDataGraphProcessingEnginePropertiesARM& queueFamilyDataGraphProcessingEngineProperties) {
	GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(DeviceContext::PhysicalDevice(), queueFamilyDataGraphProcessingEngineInfo, queueFamilyDataGraphProcessingEngineProperties);
}
DefineRaiiFunction_L(GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM, PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM, VkQueueFamilyDataGraphProcessingEnginePropertiesARM&, queueFamilyDataGraphProcessingEngineProperties);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM) {
	StructureClassHeader(MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM);
	DefineSetter_Copy(PerViewRenderAreaCount, uint32_t, perViewRenderAreaCount);
	DefineSetter_ArrayRef(PerViewRenderAreas, const VkRect2D, perViewRenderAreas, perViewRenderAreaCount);
};
VK_ENCAPSULATION_STRUCTURE_END(MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePerStageDescriptorSetFeaturesNV) {
	StructureClassHeader(PhysicalDevicePerStageDescriptorSetFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePerStageDescriptorSetFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageProcessing2FeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceImageProcessing2FeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageProcessing2FeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageProcessing2PropertiesQCOM) {
	StructureClassHeader(PhysicalDeviceImageProcessing2PropertiesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageProcessing2PropertiesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerBlockMatchWindowCreateInfoQCOM) {
	StructureClassHeader(SamplerBlockMatchWindowCreateInfoQCOM);
	DefineSetter_Copy(WindowExtent, VkExtent2D, windowExtent);
	DefineSetter_Copy(WindowCompareMode, VkBlockMatchWindowCompareModeQCOM, windowCompareMode);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerBlockMatchWindowCreateInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCubicWeightsFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceCubicWeightsFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCubicWeightsFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerCubicWeightsCreateInfoQCOM) {
	StructureClassHeader(SamplerCubicWeightsCreateInfoQCOM);
	DefineSetter_Copy(CubicWeights, VkCubicFilterWeightsQCOM, cubicWeights);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerCubicWeightsCreateInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BlitImageCubicWeightsInfoQCOM) {
	StructureClassHeader(BlitImageCubicWeightsInfoQCOM);
	DefineSetter_Copy(CubicWeights, VkCubicFilterWeightsQCOM, cubicWeights);
};
VK_ENCAPSULATION_STRUCTURE_END(BlitImageCubicWeightsInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceYcbcrDegammaFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceYcbcrDegammaFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceYcbcrDegammaFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM) {
	StructureClassHeader(SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM);
	DefineSetter_Copy(EnableYDegamma, VkBool32, enableYDegamma);
	DefineSetter_Copy(EnableCbCrDegamma, VkBool32, enableCbCrDegamma);
};
VK_ENCAPSULATION_STRUCTURE_END(SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCubicClampFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceCubicClampFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCubicClampFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT)

inline void CmdSetAttachmentFeedbackLoopEnableEXT(VkImageAspectFlags aspectMask) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetAttachmentFeedbackLoopEnableEXT(ThreadContext::CommandBuffer(), aspectMask);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceLayeredDriverPropertiesMSFT) {
	StructureClassHeader(PhysicalDeviceLayeredDriverPropertiesMSFT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceLayeredDriverPropertiesMSFT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDescriptorPoolOverallocationFeaturesNV) {
	StructureClassHeader(PhysicalDeviceDescriptorPoolOverallocationFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDescriptorPoolOverallocationFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTileMemoryHeapFeaturesQCOM) {
	StructureClassHeader(PhysicalDeviceTileMemoryHeapFeaturesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTileMemoryHeapFeaturesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceTileMemoryHeapPropertiesQCOM) {
	StructureClassHeader(PhysicalDeviceTileMemoryHeapPropertiesQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceTileMemoryHeapPropertiesQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TileMemoryRequirementsQCOM) {
	StructureClassHeader(TileMemoryRequirementsQCOM);
};
VK_ENCAPSULATION_STRUCTURE_END(TileMemoryRequirementsQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TileMemoryBindInfoQCOM) {
	StructureClassHeader(TileMemoryBindInfoQCOM);
	DefineSetter_Copy(Memory, VkDeviceMemory, memory);
};
VK_ENCAPSULATION_STRUCTURE_END(TileMemoryBindInfoQCOM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(TileMemorySizeInfoQCOM) {
	StructureClassHeader(TileMemorySizeInfoQCOM);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(TileMemorySizeInfoQCOM)

inline void CmdBindTileMemoryQCOM(const VkTileMemoryBindInfoQCOM& tileMemoryBindInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBindTileMemoryQCOM(ThreadContext::CommandBuffer(), &tileMemoryBindInfo);
}
DefineRaiiFunction(CmdBindTileMemoryQCOM, TileMemoryBindInfoQCOM);

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplaySurfaceStereoCreateInfoNV) {
	StructureClassHeader(DisplaySurfaceStereoCreateInfoNV);
	DefineSetter_Copy(StereoType, VkDisplaySurfaceStereoTypeNV, stereoType);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplaySurfaceStereoCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(DisplayModeStereoPropertiesNV) {
	StructureClassHeader(DisplayModeStereoPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(DisplayModeStereoPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRawAccessChainsFeaturesNV) {
	StructureClassHeader(PhysicalDeviceRawAccessChainsFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRawAccessChainsFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalComputeQueueDeviceCreateInfoNV) {
	StructureClassHeader(ExternalComputeQueueDeviceCreateInfoNV);
	DefineSetter_Copy(ReservedExternalQueues, uint32_t, reservedExternalQueues);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalComputeQueueDeviceCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalComputeQueueCreateInfoNV) {
	StructureClassHeader(ExternalComputeQueueCreateInfoNV);
	DefineSetter_Copy(PreferredQueue, VkQueue, preferredQueue);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalComputeQueueCreateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ExternalComputeQueueDataParamsNV) {
	StructureClassHeader(ExternalComputeQueueDataParamsNV);
	DefineSetter_Copy(DeviceIndex, uint32_t, deviceIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(ExternalComputeQueueDataParamsNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceExternalComputeQueuePropertiesNV) {
	StructureClassHeader(PhysicalDeviceExternalComputeQueuePropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceExternalComputeQueuePropertiesNV)

inline VkResult CreateExternalComputeQueueNV(const VkExternalComputeQueueCreateInfoNV& createInfo, HandleRef<VkExternalComputeQueueNV> externalQueue) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateExternalComputeQueueNV(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &externalQueue);
}
DefineRaiiFunction_ResultL(VkResult, CreateExternalComputeQueueNV, ExternalComputeQueueCreateInfoNV, HandleRef<VkExternalComputeQueueNV>, externalQueue);

inline void DestroyExternalComputeQueueNV(HandleRef<VkExternalComputeQueueNV> externalQueue, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyExternalComputeQueueNV(DeviceContext::Device(), externalQueue, &allocator);
}

inline void GetExternalComputeQueueDataNV(VkExternalComputeQueueNV externalQueue, VkExternalComputeQueueDataParamsNV& params, ArrayRef<void> data) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetExternalComputeQueueDataNV(externalQueue, &params, data);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCommandBufferInheritanceFeaturesNV) {
	StructureClassHeader(PhysicalDeviceCommandBufferInheritanceFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCommandBufferInheritanceFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV) {
	StructureClassHeader(PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderReplicatedCompositesFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderReplicatedCompositesFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderReplicatedCompositesFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceShaderFloat8FeaturesEXT) {
	StructureClassHeader(PhysicalDeviceShaderFloat8FeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceShaderFloat8FeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingValidationFeaturesNV) {
	StructureClassHeader(PhysicalDeviceRayTracingValidationFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingValidationFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceClusterAccelerationStructureFeaturesNV) {
	StructureClassHeader(PhysicalDeviceClusterAccelerationStructureFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceClusterAccelerationStructureFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceClusterAccelerationStructurePropertiesNV) {
	StructureClassHeader(PhysicalDeviceClusterAccelerationStructurePropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceClusterAccelerationStructurePropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ClusterAccelerationStructureClustersBottomLevelInputNV) {
	StructureClassHeader(ClusterAccelerationStructureClustersBottomLevelInputNV);
	DefineSetter_Copy(MaxTotalClusterCount, uint32_t, maxTotalClusterCount);
	DefineSetter_Copy(MaxClusterCountPerAccelerationStructure, uint32_t, maxClusterCountPerAccelerationStructure);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureClustersBottomLevelInputNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ClusterAccelerationStructureTriangleClusterInputNV) {
	StructureClassHeader(ClusterAccelerationStructureTriangleClusterInputNV);
	DefineSetter_Copy(VertexFormat, VkFormat, vertexFormat);
	DefineSetter_Copy(MaxGeometryIndexValue, uint32_t, maxGeometryIndexValue);
	DefineSetter_Copy(MaxClusterUniqueGeometryCount, uint32_t, maxClusterUniqueGeometryCount);
	DefineSetter_Copy(MaxClusterTriangleCount, uint32_t, maxClusterTriangleCount);
	DefineSetter_Copy(MaxClusterVertexCount, uint32_t, maxClusterVertexCount);
	DefineSetter_Copy(MaxTotalTriangleCount, uint32_t, maxTotalTriangleCount);
	DefineSetter_Copy(MaxTotalVertexCount, uint32_t, maxTotalVertexCount);
	DefineSetter_Copy(MinPositionTruncateBitCount, uint32_t, minPositionTruncateBitCount);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureTriangleClusterInputNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ClusterAccelerationStructureMoveObjectsInputNV) {
	StructureClassHeader(ClusterAccelerationStructureMoveObjectsInputNV);
	DefineSetter_Copy(Type, VkClusterAccelerationStructureTypeNV, type);
	DefineSetter_Copy(NoMoveOverlap, VkBool32, noMoveOverlap);
	DefineSetter_Copy(MaxMovedBytes, VkDeviceSize, maxMovedBytes);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureMoveObjectsInputNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(ClusterAccelerationStructureOpInputNV) {
	StructureClassHeader_UnionWrapper(ClusterAccelerationStructureOpInputNV);
	union {
		VkClusterAccelerationStructureClustersBottomLevelInputNV* pClustersBottomLevel;
		VkClusterAccelerationStructureTriangleClusterInputNV*     pTriangleClusters;
		VkClusterAccelerationStructureMoveObjectsInputNV*         pMoveObjects;
	};
	Structure(VkClusterAccelerationStructureClustersBottomLevelInputNV& clustersBottomLevel) : pClustersBottomLevel(&clustersBottomLevel) {}
	Structure(VkClusterAccelerationStructureTriangleClusterInputNV& triangleClusters) : pTriangleClusters(&triangleClusters) {}
	Structure(VkClusterAccelerationStructureMoveObjectsInputNV& moveObjects) : pMoveObjects(&moveObjects) {}
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureOpInputNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ClusterAccelerationStructureInputInfoNV) {
	StructureClassHeader(ClusterAccelerationStructureInputInfoNV);
	DefineSetter_Copy(MaxAccelerationStructureCount, uint32_t, maxAccelerationStructureCount);
	DefineSetter_Copy(Flags, VkBuildAccelerationStructureFlagsKHR, flags);
	DefineSetter_Copy(OpType, VkClusterAccelerationStructureOpTypeNV, opType);
	DefineSetter_Copy(OpMode, VkClusterAccelerationStructureOpModeNV, opMode);
	DefineSetter_Copy(OpInput, VkClusterAccelerationStructureOpInputNV, opInput);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureInputInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(StridedDeviceAddressRegionKHR) {
	StructureClassHeader_NoSType(StridedDeviceAddressRegionKHR);
	DefineSetter_Copy(DeviceAddress, VkDeviceAddress, deviceAddress);
	DefineSetter_Copy(Stride, VkDeviceSize, stride);
	DefineSetter_Copy(Size, VkDeviceSize, size);
};
VK_ENCAPSULATION_STRUCTURE_END(StridedDeviceAddressRegionKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ClusterAccelerationStructureCommandsInfoNV) {
	StructureClassHeader(ClusterAccelerationStructureCommandsInfoNV);
	DefineSetter_Copy(Input, VkClusterAccelerationStructureInputInfoNV, input);
	DefineSetter_Copy(DstImplicitData, VkDeviceAddress, dstImplicitData);
	DefineSetter_Copy(ScratchData, VkDeviceAddress, scratchData);
	DefineSetter_Copy(DstAddressesArray, VkStridedDeviceAddressRegionKHR, dstAddressesArray);
	DefineSetter_Copy(DstSizesArray, VkStridedDeviceAddressRegionKHR, dstSizesArray);
	DefineSetter_Copy(SrcInfosArray, VkStridedDeviceAddressRegionKHR, srcInfosArray);
	DefineSetter_Copy(SrcInfosCount, VkDeviceAddress, srcInfosCount);
	DefineSetter_Copy(AddressResolutionFlags, VkClusterAccelerationStructureAddressResolutionFlagsNV, addressResolutionFlags);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureCommandsInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(StridedDeviceAddressNV) {
	StructureClassHeader_NoSType(StridedDeviceAddressNV);
	DefineSetter_Copy(StartAddress, VkDeviceAddress, startAddress);
	DefineSetter_Copy(StrideInBytes, VkDeviceSize, strideInBytes);
};
VK_ENCAPSULATION_STRUCTURE_END(StridedDeviceAddressNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV) {
	StructureClassHeader_NoSType(ClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV);
	DefineSetter_Copy(GeometryIndex, uint32_t, geometryIndex);
	DefineSetter_Copy(Reserved, uint32_t, reserved);
	DefineSetter_Copy(GeometryFlags, uint32_t, geometryFlags);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClusterAccelerationStructureMoveObjectsInfoNV) {
	StructureClassHeader_NoSType(ClusterAccelerationStructureMoveObjectsInfoNV);
	DefineSetter_Copy(SrcAccelerationStructure, VkDeviceAddress, srcAccelerationStructure);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureMoveObjectsInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClusterAccelerationStructureBuildClustersBottomLevelInfoNV) {
	StructureClassHeader_NoSType(ClusterAccelerationStructureBuildClustersBottomLevelInfoNV);
	DefineSetter_Copy(ClusterReferencesCount, uint32_t, clusterReferencesCount);
	DefineSetter_Copy(ClusterReferencesStride, uint32_t, clusterReferencesStride);
	DefineSetter_Copy(ClusterReferences, VkDeviceAddress, clusterReferences);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureBuildClustersBottomLevelInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClusterAccelerationStructureBuildTriangleClusterInfoNV) {
	StructureClassHeader_NoSType(ClusterAccelerationStructureBuildTriangleClusterInfoNV);
	DefineSetter_Copy(ClusterID, uint32_t, clusterID);
	DefineSetter_Copy(ClusterFlags, VkClusterAccelerationStructureClusterFlagsNV, clusterFlags);
	DefineSetter_Copy(TriangleCount, uint32_t, triangleCount);
	DefineSetter_Copy(VertexCount, uint32_t, vertexCount);
	DefineSetter_Copy(PositionTruncateBitCount, uint32_t, positionTruncateBitCount);
	DefineSetter_Copy(IndexType, uint32_t, indexType);
	DefineSetter_Copy(OpacityMicromapIndexType, uint32_t, opacityMicromapIndexType);
	DefineSetter_Copy(BaseGeometryIndexAndGeometryFlags, VkClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV, baseGeometryIndexAndGeometryFlags);
	DefineSetter_Copy(IndexBufferStride, uint16_t, indexBufferStride);
	DefineSetter_Copy(VertexBufferStride, uint16_t, vertexBufferStride);
	DefineSetter_Copy(GeometryIndexAndFlagsBufferStride, uint16_t, geometryIndexAndFlagsBufferStride);
	DefineSetter_Copy(OpacityMicromapIndexBufferStride, uint16_t, opacityMicromapIndexBufferStride);
	DefineSetter_Copy(IndexBuffer, VkDeviceAddress, indexBuffer);
	DefineSetter_Copy(VertexBuffer, VkDeviceAddress, vertexBuffer);
	DefineSetter_Copy(GeometryIndexAndFlagsBuffer, VkDeviceAddress, geometryIndexAndFlagsBuffer);
	DefineSetter_Copy(OpacityMicromapArray, VkDeviceAddress, opacityMicromapArray);
	DefineSetter_Copy(OpacityMicromapIndexBuffer, VkDeviceAddress, opacityMicromapIndexBuffer);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureBuildTriangleClusterInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV) {
	StructureClassHeader_NoSType(ClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV);
	DefineSetter_Copy(ClusterID, uint32_t, clusterID);
	DefineSetter_Copy(ClusterFlags, VkClusterAccelerationStructureClusterFlagsNV, clusterFlags);
	DefineSetter_Copy(TriangleCount, uint32_t, triangleCount);
	DefineSetter_Copy(VertexCount, uint32_t, vertexCount);
	DefineSetter_Copy(PositionTruncateBitCount, uint32_t, positionTruncateBitCount);
	DefineSetter_Copy(IndexType, uint32_t, indexType);
	DefineSetter_Copy(OpacityMicromapIndexType, uint32_t, opacityMicromapIndexType);
	DefineSetter_Copy(BaseGeometryIndexAndGeometryFlags, VkClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV, baseGeometryIndexAndGeometryFlags);
	DefineSetter_Copy(IndexBufferStride, uint16_t, indexBufferStride);
	DefineSetter_Copy(VertexBufferStride, uint16_t, vertexBufferStride);
	DefineSetter_Copy(GeometryIndexAndFlagsBufferStride, uint16_t, geometryIndexAndFlagsBufferStride);
	DefineSetter_Copy(OpacityMicromapIndexBufferStride, uint16_t, opacityMicromapIndexBufferStride);
	DefineSetter_Copy(IndexBuffer, VkDeviceAddress, indexBuffer);
	DefineSetter_Copy(VertexBuffer, VkDeviceAddress, vertexBuffer);
	DefineSetter_Copy(GeometryIndexAndFlagsBuffer, VkDeviceAddress, geometryIndexAndFlagsBuffer);
	DefineSetter_Copy(OpacityMicromapArray, VkDeviceAddress, opacityMicromapArray);
	DefineSetter_Copy(OpacityMicromapIndexBuffer, VkDeviceAddress, opacityMicromapIndexBuffer);
	DefineSetter_Copy(InstantiationBoundingBoxLimit, VkDeviceAddress, instantiationBoundingBoxLimit);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClusterAccelerationStructureInstantiateClusterInfoNV) {
	StructureClassHeader_NoSType(ClusterAccelerationStructureInstantiateClusterInfoNV);
	DefineSetter_Copy(ClusterIdOffset, uint32_t, clusterIdOffset);
	DefineSetter_Copy(GeometryIndexOffset, uint32_t, geometryIndexOffset);
	DefineSetter_Copy(Reserved, uint32_t, reserved);
	DefineSetter_Copy(ClusterTemplateAddress, VkDeviceAddress, clusterTemplateAddress);
	DefineSetter_Copy(VertexBuffer, VkStridedDeviceAddressNV, vertexBuffer);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureInstantiateClusterInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(ClusterAccelerationStructureGetTemplateIndicesInfoNV) {
	StructureClassHeader_NoSType(ClusterAccelerationStructureGetTemplateIndicesInfoNV);
	DefineSetter_Copy(ClusterTemplateAddress, VkDeviceAddress, clusterTemplateAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(ClusterAccelerationStructureGetTemplateIndicesInfoNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureBuildSizesInfoKHR) {
	StructureClassHeader(AccelerationStructureBuildSizesInfoKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureBuildSizesInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RayTracingPipelineClusterAccelerationStructureCreateInfoNV) {
	StructureClassHeader(RayTracingPipelineClusterAccelerationStructureCreateInfoNV);
	DefineSetter_Copy(AllowClusterAccelerationStructure, VkBool32, allowClusterAccelerationStructure);
};
VK_ENCAPSULATION_STRUCTURE_END(RayTracingPipelineClusterAccelerationStructureCreateInfoNV)

inline void GetClusterAccelerationStructureBuildSizesNV(const VkClusterAccelerationStructureInputInfoNV& info, VkAccelerationStructureBuildSizesInfoKHR& sizeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetClusterAccelerationStructureBuildSizesNV(DeviceContext::Device(), &info, &sizeInfo);
}
DefineRaiiFunction_L(GetClusterAccelerationStructureBuildSizesNV, ClusterAccelerationStructureInputInfoNV, VkAccelerationStructureBuildSizesInfoKHR&, sizeInfo);

inline void CmdBuildClusterAccelerationStructureIndirectNV(const VkClusterAccelerationStructureCommandsInfoNV& commandInfos) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBuildClusterAccelerationStructureIndirectNV(ThreadContext::CommandBuffer(), &commandInfos);
}
DefineRaiiFunction(CmdBuildClusterAccelerationStructureIndirectNV, ClusterAccelerationStructureCommandsInfoNV);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePartitionedAccelerationStructureFeaturesNV) {
	StructureClassHeader(PhysicalDevicePartitionedAccelerationStructureFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePartitionedAccelerationStructureFeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePartitionedAccelerationStructurePropertiesNV) {
	StructureClassHeader(PhysicalDevicePartitionedAccelerationStructurePropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePartitionedAccelerationStructurePropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PartitionedAccelerationStructureFlagsNV) {
	StructureClassHeader_NoSType(PartitionedAccelerationStructureFlagsNV);
	DefineSetter_Copy(EnablePartitionTranslation, VkBool32, enablePartitionTranslation);
};
VK_ENCAPSULATION_STRUCTURE_END(PartitionedAccelerationStructureFlagsNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BuildPartitionedAccelerationStructureIndirectCommandNV) {
	StructureClassHeader_NoSType(BuildPartitionedAccelerationStructureIndirectCommandNV);
	DefineSetter_Copy(OpType, VkPartitionedAccelerationStructureOpTypeNV, opType);
	DefineSetter_Copy(ArgCount, uint32_t, argCount);
	DefineSetter_Copy(ArgData, VkStridedDeviceAddressNV, argData);
};
VK_ENCAPSULATION_STRUCTURE_END(BuildPartitionedAccelerationStructureIndirectCommandNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PartitionedAccelerationStructureWriteInstanceDataNV) {
	StructureClassHeader_NoSType(PartitionedAccelerationStructureWriteInstanceDataNV);
	DefineSetter_Copy(Transform, VkTransformMatrixKHR, transform);
	// float explicitAABB[6];
	DefineSetter_ArrayCopy(ExplicitAABB, float, explicitAABB);
	DefineSetter_Copy(InstanceID, uint32_t, instanceID);
	DefineSetter_Copy(InstanceMask, uint32_t, instanceMask);
	DefineSetter_Copy(InstanceContributionToHitGroupIndex, uint32_t, instanceContributionToHitGroupIndex);
	DefineSetter_Copy(InstanceFlags, VkPartitionedAccelerationStructureInstanceFlagsNV, instanceFlags);
	DefineSetter_Copy(InstanceIndex, uint32_t, instanceIndex);
	DefineSetter_Copy(PartitionIndex, uint32_t, partitionIndex);
	DefineSetter_Copy(AccelerationStructure, VkDeviceAddress, accelerationStructure);
};
VK_ENCAPSULATION_STRUCTURE_END(PartitionedAccelerationStructureWriteInstanceDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PartitionedAccelerationStructureUpdateInstanceDataNV) {
	StructureClassHeader_NoSType(PartitionedAccelerationStructureUpdateInstanceDataNV);
	DefineSetter_Copy(InstanceIndex, uint32_t, instanceIndex);
	DefineSetter_Copy(InstanceContributionToHitGroupIndex, uint32_t, instanceContributionToHitGroupIndex);
	DefineSetter_Copy(AccelerationStructure, VkDeviceAddress, accelerationStructure);
};
VK_ENCAPSULATION_STRUCTURE_END(PartitionedAccelerationStructureUpdateInstanceDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(PartitionedAccelerationStructureWritePartitionTranslationDataNV) {
	StructureClassHeader_NoSType(PartitionedAccelerationStructureWritePartitionTranslationDataNV);
	DefineSetter_Copy(PartitionIndex, uint32_t, partitionIndex);
	// float partitionTranslation[3];
	DefineSetter_ArrayCopy(PartitionTranslation, float, partitionTranslation);
};
VK_ENCAPSULATION_STRUCTURE_END(PartitionedAccelerationStructureWritePartitionTranslationDataNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteDescriptorSetPartitionedAccelerationStructureNV) {
	StructureClassHeader(WriteDescriptorSetPartitionedAccelerationStructureNV);
	DefineSetter_Copy(AccelerationStructureCount, uint32_t, accelerationStructureCount);
	DefineSetter_ArrayRef(AccelerationStructures, const VkDeviceAddress, accelerationStructures, accelerationStructureCount);
};
VK_ENCAPSULATION_STRUCTURE_END(WriteDescriptorSetPartitionedAccelerationStructureNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PartitionedAccelerationStructureInstancesInputNV) {
	StructureClassHeader(PartitionedAccelerationStructureInstancesInputNV);
	DefineSetter_Copy(Flags, VkBuildAccelerationStructureFlagsKHR, flags);
	DefineSetter_Copy(InstanceCount, uint32_t, instanceCount);
	DefineSetter_Copy(MaxInstancePerPartitionCount, uint32_t, maxInstancePerPartitionCount);
	DefineSetter_Copy(PartitionCount, uint32_t, partitionCount);
	DefineSetter_Copy(MaxInstanceInGlobalPartitionCount, uint32_t, maxInstanceInGlobalPartitionCount);
};
VK_ENCAPSULATION_STRUCTURE_END(PartitionedAccelerationStructureInstancesInputNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(BuildPartitionedAccelerationStructureInfoNV) {
	StructureClassHeader(BuildPartitionedAccelerationStructureInfoNV);
	DefineSetter_Copy(Input, VkPartitionedAccelerationStructureInstancesInputNV, input);
	DefineSetter_Copy(SrcAccelerationStructureData, VkDeviceAddress, srcAccelerationStructureData);
	DefineSetter_Copy(DstAccelerationStructureData, VkDeviceAddress, dstAccelerationStructureData);
	DefineSetter_Copy(ScratchData, VkDeviceAddress, scratchData);
	DefineSetter_Copy(SrcInfos, VkDeviceAddress, srcInfos);
	DefineSetter_Copy(SrcInfosCount, VkDeviceAddress, srcInfosCount);
};
VK_ENCAPSULATION_STRUCTURE_END(BuildPartitionedAccelerationStructureInfoNV)

inline void GetPartitionedAccelerationStructuresBuildSizesNV(const VkPartitionedAccelerationStructureInstancesInputNV& info, VkAccelerationStructureBuildSizesInfoKHR& sizeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetPartitionedAccelerationStructuresBuildSizesNV(DeviceContext::Device(), &info, &sizeInfo);
}
DefineRaiiFunction_L(GetPartitionedAccelerationStructuresBuildSizesNV, PartitionedAccelerationStructureInstancesInputNV, VkAccelerationStructureBuildSizesInfoKHR&, sizeInfo);

inline void CmdBuildPartitionedAccelerationStructuresNV(const VkBuildPartitionedAccelerationStructureInfoNV& buildInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBuildPartitionedAccelerationStructuresNV(ThreadContext::CommandBuffer(), &buildInfo);
}
DefineRaiiFunction(CmdBuildPartitionedAccelerationStructuresNV, BuildPartitionedAccelerationStructureInfoNV);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeneratedCommandsMemoryRequirementsInfoEXT) {
	StructureClassHeader(GeneratedCommandsMemoryRequirementsInfoEXT);
	DefineSetter_Copy(IndirectExecutionSet, VkIndirectExecutionSetEXT, indirectExecutionSet);
	DefineSetter_Copy(IndirectCommandsLayout, VkIndirectCommandsLayoutEXT, indirectCommandsLayout);
	DefineSetter_Copy(MaxSequenceCount, uint32_t, maxSequenceCount);
	DefineSetter_Copy(MaxDrawCount, uint32_t, maxDrawCount);
};
VK_ENCAPSULATION_STRUCTURE_END(GeneratedCommandsMemoryRequirementsInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectExecutionSetPipelineInfoEXT) {
	StructureClassHeader(IndirectExecutionSetPipelineInfoEXT);
	DefineSetter_Copy(InitialPipeline, VkPipeline, initialPipeline);
	DefineSetter_Copy(MaxPipelineCount, uint32_t, maxPipelineCount);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectExecutionSetPipelineInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectExecutionSetShaderLayoutInfoEXT) {
	StructureClassHeader(IndirectExecutionSetShaderLayoutInfoEXT);
	DefineSetter_Copy(SetLayoutCount, uint32_t, setLayoutCount);
	DefineSetter_ArrayRef(SetLayouts, const VkDescriptorSetLayout, setLayouts, setLayoutCount);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectExecutionSetShaderLayoutInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectExecutionSetShaderInfoEXT) {
	StructureClassHeader(IndirectExecutionSetShaderInfoEXT);
	DefineSetter_Copy(ShaderCount, uint32_t, shaderCount);
	DefineSetter_ArrayRef(InitialShaders, const VkShaderEXT, initialShaders, shaderCount);
	DefineSetter_ArrayRefIgnoreC(SetLayoutInfos, const VkIndirectExecutionSetShaderLayoutInfoEXT, setLayoutInfos);
	DefineSetter_Copy(MaxShaderCount, uint32_t, maxShaderCount);
	DefineSetter_Copy(PushConstantRangeCount, uint32_t, pushConstantRangeCount);
	DefineSetter_ArrayRef(PushConstantRanges, const VkPushConstantRange, pushConstantRanges, pushConstantRangeCount);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectExecutionSetShaderInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(IndirectExecutionSetInfoEXT) {
	union {
		const VkIndirectExecutionSetPipelineInfoEXT* pPipelineInfo;
		const VkIndirectExecutionSetShaderInfoEXT*   pShaderInfo;
	};
	Structure(OptionalRef<const VkIndirectExecutionSetPipelineInfoEXT> pipelineInfo) : pPipelineInfo(&pipelineInfo) {}
	Structure(OptionalRef<const VkIndirectExecutionSetShaderInfoEXT> shaderInfo) : pShaderInfo(&shaderInfo) {}
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectExecutionSetInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectExecutionSetCreateInfoEXT) {
	StructureClassHeader(IndirectExecutionSetCreateInfoEXT);
	DefineSetter_Copy(Type, VkIndirectExecutionSetInfoTypeEXT, type);
	DefineSetter_Copy(Info, VkIndirectExecutionSetInfoEXT, info);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectExecutionSetCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeneratedCommandsInfoEXT) {
	StructureClassHeader(GeneratedCommandsInfoEXT);
	DefineSetter_Copy(ShaderStages, VkShaderStageFlags, shaderStages);
	DefineSetter_Copy(IndirectExecutionSet, VkIndirectExecutionSetEXT, indirectExecutionSet);
	DefineSetter_Copy(IndirectCommandsLayout, VkIndirectCommandsLayoutEXT, indirectCommandsLayout);
	DefineSetter_Copy(IndirectAddress, VkDeviceAddress, indirectAddress);
	DefineSetter_Copy(IndirectAddressSize, VkDeviceSize, indirectAddressSize);
	DefineSetter_Copy(PreprocessAddress, VkDeviceAddress, preprocessAddress);
	DefineSetter_Copy(PreprocessSize, VkDeviceSize, preprocessSize);
	DefineSetter_Copy(MaxSequenceCount, uint32_t, maxSequenceCount);
	DefineSetter_Copy(SequenceCountAddress, VkDeviceAddress, sequenceCountAddress);
	DefineSetter_Copy(MaxDrawCount, uint32_t, maxDrawCount);
};
VK_ENCAPSULATION_STRUCTURE_END(GeneratedCommandsInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteIndirectExecutionSetPipelineEXT) {
	StructureClassHeader(WriteIndirectExecutionSetPipelineEXT);
	DefineSetter_Copy(Index, uint32_t, index);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
};
VK_ENCAPSULATION_STRUCTURE_END(WriteIndirectExecutionSetPipelineEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(IndirectCommandsPushConstantTokenEXT) {
	StructureClassHeader_NoSType(IndirectCommandsPushConstantTokenEXT);
	DefineSetter_Copy(UpdateRange, VkPushConstantRange, updateRange);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsPushConstantTokenEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(IndirectCommandsVertexBufferTokenEXT) {
	StructureClassHeader_NoSType(IndirectCommandsVertexBufferTokenEXT);
	DefineSetter_Copy(VertexBindingUnit, uint32_t, vertexBindingUnit);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsVertexBufferTokenEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(IndirectCommandsIndexBufferTokenEXT) {
	StructureClassHeader_NoSType(IndirectCommandsIndexBufferTokenEXT);
	DefineSetter_Copy(Mode, VkIndirectCommandsInputModeFlagBitsEXT, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsIndexBufferTokenEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(IndirectCommandsExecutionSetTokenEXT) {
	StructureClassHeader_NoSType(IndirectCommandsExecutionSetTokenEXT);
	DefineSetter_Copy(Type, VkIndirectExecutionSetInfoTypeEXT, type);
	DefineSetter_Copy(ShaderStages, VkShaderStageFlags, shaderStages);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsExecutionSetTokenEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(IndirectCommandsTokenDataEXT) {
	union {
		const VkIndirectCommandsPushConstantTokenEXT* pPushConstant;
		const VkIndirectCommandsVertexBufferTokenEXT* pVertexBuffer;
		const VkIndirectCommandsIndexBufferTokenEXT*  pIndexBuffer;
		const VkIndirectCommandsExecutionSetTokenEXT* pExecutionSet;
	};
	Structure(OptionalRef<const VkIndirectCommandsPushConstantTokenEXT> pushConstant) : pPushConstant(&pushConstant) {}
	Structure(OptionalRef<const VkIndirectCommandsVertexBufferTokenEXT> vertexBuffer) : pVertexBuffer(&vertexBuffer) {}
	Structure(OptionalRef<const VkIndirectCommandsIndexBufferTokenEXT> indexBuffer) : pIndexBuffer(&indexBuffer) {}
	Structure(OptionalRef<const VkIndirectCommandsExecutionSetTokenEXT> executionSet) : pExecutionSet(&executionSet) {}
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsTokenDataEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectCommandsLayoutTokenEXT) {
	StructureClassHeader(IndirectCommandsLayoutTokenEXT);
	DefineSetter_Copy(Type, VkIndirectCommandsTokenTypeEXT, type);
	DefineSetter_Copy(Data, VkIndirectCommandsTokenDataEXT, data);
	DefineSetter_Copy(Offset, uint32_t, offset);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsLayoutTokenEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(IndirectCommandsLayoutCreateInfoEXT) {
	StructureClassHeader(IndirectCommandsLayoutCreateInfoEXT);
	DefineSetter_Copy(Flags, VkIndirectCommandsLayoutUsageFlagsEXT, flags);
	DefineSetter_Copy(ShaderStages, VkShaderStageFlags, shaderStages);
	DefineSetter_Copy(IndirectStride, uint32_t, indirectStride);
	DefineSetter_Copy(PipelineLayout, VkPipelineLayout, pipelineLayout);
	DefineSetter_Copy(TokenCount, uint32_t, tokenCount);
	DefineSetter_ArrayRef(Tokens, const VkIndirectCommandsLayoutTokenEXT, tokens, tokenCount);
};
VK_ENCAPSULATION_STRUCTURE_END(IndirectCommandsLayoutCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DrawIndirectCountIndirectCommandEXT) {
	StructureClassHeader_NoSType(DrawIndirectCountIndirectCommandEXT);
	DefineSetter_Copy(BufferAddress, VkDeviceAddress, bufferAddress);
	DefineSetter_Copy(Stride, uint32_t, stride);
	DefineSetter_Copy(CommandCount, uint32_t, commandCount);
};
VK_ENCAPSULATION_STRUCTURE_END(DrawIndirectCountIndirectCommandEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BindVertexBufferIndirectCommandEXT) {
	StructureClassHeader_NoSType(BindVertexBufferIndirectCommandEXT);
	DefineSetter_Copy(BufferAddress, VkDeviceAddress, bufferAddress);
	DefineSetter_Copy(Size, uint32_t, size);
	DefineSetter_Copy(Stride, uint32_t, stride);
};
VK_ENCAPSULATION_STRUCTURE_END(BindVertexBufferIndirectCommandEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(BindIndexBufferIndirectCommandEXT) {
	StructureClassHeader_NoSType(BindIndexBufferIndirectCommandEXT);
	DefineSetter_Copy(BufferAddress, VkDeviceAddress, bufferAddress);
	DefineSetter_Copy(Size, uint32_t, size);
	DefineSetter_Copy(IndexType, VkIndexType, indexType);
};
VK_ENCAPSULATION_STRUCTURE_END(BindIndexBufferIndirectCommandEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeneratedCommandsPipelineInfoEXT) {
	StructureClassHeader(GeneratedCommandsPipelineInfoEXT);
	DefineSetter_Copy(Pipeline, VkPipeline, pipeline);
};
VK_ENCAPSULATION_STRUCTURE_END(GeneratedCommandsPipelineInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(GeneratedCommandsShaderInfoEXT) {
	StructureClassHeader(GeneratedCommandsShaderInfoEXT);
	DefineSetter_Copy(ShaderCount, uint32_t, shaderCount);
	DefineSetter_ArrayRef(Shaders, const VkShaderEXT, shaders, shaderCount);
};
VK_ENCAPSULATION_STRUCTURE_END(GeneratedCommandsShaderInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteIndirectExecutionSetShaderEXT) {
	StructureClassHeader(WriteIndirectExecutionSetShaderEXT);
	DefineSetter_Copy(Index, uint32_t, index);
	DefineSetter_Copy(Shader, VkShaderEXT, shader);
};
VK_ENCAPSULATION_STRUCTURE_END(WriteIndirectExecutionSetShaderEXT)

inline void GetGeneratedCommandsMemoryRequirementsEXT(const VkGeneratedCommandsMemoryRequirementsInfoEXT& info, VkMemoryRequirements2& memoryRequirements) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetGeneratedCommandsMemoryRequirementsEXT(DeviceContext::Device(), &info, &memoryRequirements);
}
DefineRaiiFunction_L(GetGeneratedCommandsMemoryRequirementsEXT, GeneratedCommandsMemoryRequirementsInfoEXT, VkMemoryRequirements2&, memoryRequirements);

inline void CmdPreprocessGeneratedCommandsEXT(const VkGeneratedCommandsInfoEXT& generatedCommandsInfo, VkCommandBuffer stateCommandBuffer) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdPreprocessGeneratedCommandsEXT(ThreadContext::CommandBuffer(), &generatedCommandsInfo, stateCommandBuffer);
}
DefineRaiiFunction_L(CmdPreprocessGeneratedCommandsEXT, GeneratedCommandsInfoEXT, VkCommandBuffer, stateCommandBuffer);

inline void CmdExecuteGeneratedCommandsEXT(VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT& generatedCommandsInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdExecuteGeneratedCommandsEXT(ThreadContext::CommandBuffer(), isPreprocessed, &generatedCommandsInfo);
}
DefineRaiiFunction_R(CmdExecuteGeneratedCommandsEXT, VkBool32, isPreprocessed, GeneratedCommandsInfoEXT);

inline VkResult CreateIndirectCommandsLayoutEXT(const VkIndirectCommandsLayoutCreateInfoEXT& createInfo, HandleRef<VkIndirectCommandsLayoutEXT> indirectCommandsLayout) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateIndirectCommandsLayoutEXT(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &indirectCommandsLayout);
}
DefineRaiiFunction_ResultL(VkResult, CreateIndirectCommandsLayoutEXT, IndirectCommandsLayoutCreateInfoEXT, HandleRef<VkIndirectCommandsLayoutEXT>, indirectCommandsLayout);

inline void DestroyIndirectCommandsLayoutEXT(HandleRef<VkIndirectCommandsLayoutEXT> indirectCommandsLayout, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyIndirectCommandsLayoutEXT(DeviceContext::Device(), indirectCommandsLayout, &allocator);
	indirectCommandsLayout = VK_NULL_HANDLE;
}

inline VkResult CreateIndirectExecutionSetEXT(const VkIndirectExecutionSetCreateInfoEXT& createInfo, HandleRef<VkIndirectExecutionSetEXT> indirectExecutionSet) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateIndirectExecutionSetEXT(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &indirectExecutionSet);
}
DefineRaiiFunction_ResultL(VkResult, CreateIndirectExecutionSetEXT, IndirectExecutionSetCreateInfoEXT, HandleRef<VkIndirectExecutionSetEXT>, indirectExecutionSet);

inline void DestroyIndirectExecutionSetEXT(HandleRef<VkIndirectExecutionSetEXT> indirectExecutionSet, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyIndirectExecutionSetEXT(DeviceContext::Device(), indirectExecutionSet, &allocator);
	indirectExecutionSet = VK_NULL_HANDLE;
}

inline void UpdateIndirectExecutionSetPipelineEXT(VkIndirectExecutionSetEXT indirectExecutionSet, ArrayRef<const VkWriteIndirectExecutionSetPipelineEXT> executionSetWrites) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkUpdateIndirectExecutionSetPipelineEXT(DeviceContext::Device(), indirectExecutionSet, executionSetWrites.size(), executionSetWrites);
}
DefineRaiiFunction_R(UpdateIndirectExecutionSetPipelineEXT, VkIndirectExecutionSetEXT, indirectExecutionSet, WriteIndirectExecutionSetPipelineEXT);

inline void UpdateIndirectExecutionSetShaderEXT(VkIndirectExecutionSetEXT indirectExecutionSet, ArrayRef<const VkWriteIndirectExecutionSetShaderEXT> executionSetWrites) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkUpdateIndirectExecutionSetShaderEXT(DeviceContext::Device(), indirectExecutionSet, executionSetWrites.size(), executionSetWrites);
}
DefineRaiiFunction_R(UpdateIndirectExecutionSetShaderEXT, VkIndirectExecutionSetEXT, indirectExecutionSet, WriteIndirectExecutionSetShaderEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageAlignmentControlFeaturesMESA) {
	StructureClassHeader(PhysicalDeviceImageAlignmentControlFeaturesMESA);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageAlignmentControlFeaturesMESA)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceImageAlignmentControlPropertiesMESA) {
	StructureClassHeader(PhysicalDeviceImageAlignmentControlPropertiesMESA);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceImageAlignmentControlPropertiesMESA)

VK_ENCAPSULATION_STRUCTURE_BEGIN(ImageAlignmentControlCreateInfoMESA) {
	StructureClassHeader(ImageAlignmentControlCreateInfoMESA);
	DefineSetter_Copy(MaximumRequestedAlignment, uint32_t, maximumRequestedAlignment);
};
VK_ENCAPSULATION_STRUCTURE_END(ImageAlignmentControlCreateInfoMESA)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceDepthClampControlFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceDepthClampControlFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceDepthClampControlFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineViewportDepthClampControlCreateInfoEXT) {
	StructureClassHeader(PipelineViewportDepthClampControlCreateInfoEXT);
	DefineSetter_Copy(DepthClampMode, VkDepthClampModeEXT, depthClampMode);
	DefineSetter_Ref(DepthClampRange, const VkDepthClampRangeEXT, depthClampRange);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineViewportDepthClampControlCreateInfoEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceHdrVividFeaturesHUAWEI) {
	StructureClassHeader(PhysicalDeviceHdrVividFeaturesHUAWEI);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceHdrVividFeaturesHUAWEI)

VK_ENCAPSULATION_STRUCTURE_BEGIN(HdrVividDynamicMetadataHUAWEI) {
	StructureClassHeader(HdrVividDynamicMetadataHUAWEI);
	DefineSetter_Copy(DynamicMetadataSize, size_t, dynamicMetadataSize);
	DefineSetter_ArrayRef(DynamicMetadata, const void, dynamicMetadata, dynamicMetadataSize);
};
VK_ENCAPSULATION_STRUCTURE_END(HdrVividDynamicMetadataHUAWEI)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CooperativeMatrixFlexibleDimensionsPropertiesNV) {
	StructureClassHeader(CooperativeMatrixFlexibleDimensionsPropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(CooperativeMatrixFlexibleDimensionsPropertiesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeMatrix2FeaturesNV) {
	StructureClassHeader(PhysicalDeviceCooperativeMatrix2FeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeMatrix2FeaturesNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceCooperativeMatrix2PropertiesNV) {
	StructureClassHeader(PhysicalDeviceCooperativeMatrix2PropertiesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceCooperativeMatrix2PropertiesNV)

inline VkResult GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t& propertyCount, ArrayRef<VkCooperativeMatrixFlexibleDimensionsPropertiesNV> properties = {}) {
	return VK_ENCAPSULATION_INSTANCE_DISPATCH vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(physicalDevice, &propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice physicalDevice, IsDynamicArray<VkCooperativeMatrixFlexibleDimensionsPropertiesNV> auto& properties) {
	uint32_t count = 0;
	VkResult result = GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(physicalDevice, count);
	if (result == VK_SUCCESS)
		properties.resize(count),
		result = GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(physicalDevice, count, properties);
	return result;
}
inline VkResult GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(uint32_t& propertyCount, ArrayRef<VkCooperativeMatrixFlexibleDimensionsPropertiesNV> properties = {}) {
	return GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(DeviceContext::PhysicalDevice(), propertyCount, properties);
}
inline VkResult GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(IsDynamicArray<VkCooperativeMatrixFlexibleDimensionsPropertiesNV> auto& properties) {
	return GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(DeviceContext::PhysicalDevice(), properties);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineOpacityMicromapFeaturesARM) {
	StructureClassHeader(PhysicalDevicePipelineOpacityMicromapFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineOpacityMicromapFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceVertexAttributeRobustnessFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceVertexAttributeRobustnessFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceVertexAttributeRobustnessFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFormatPackFeaturesARM) {
	StructureClassHeader(PhysicalDeviceFormatPackFeaturesARM);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFormatPackFeaturesARM)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE) {
	StructureClassHeader(PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PipelineFragmentDensityMapLayeredCreateInfoVALVE) {
	StructureClassHeader(PipelineFragmentDensityMapLayeredCreateInfoVALVE);
	DefineSetter_Copy(MaxFragmentDensityMapLayers, uint32_t, maxFragmentDensityMapLayers);
};
VK_ENCAPSULATION_STRUCTURE_END(PipelineFragmentDensityMapLayeredCreateInfoVALVE)

#ifdef VK_ENABLE_BETA_EXTENSIONS

VK_ENCAPSULATION_STRUCTURE_BEGIN(SetPresentConfigNV) {
	StructureClassHeader(SetPresentConfigNV);
	DefineSetter_Copy(NumFramesPerBatch, uint32_t, numFramesPerBatch);
	DefineSetter_Copy(PresentConfigFeedback, uint32_t, presentConfigFeedback);
};
VK_ENCAPSULATION_STRUCTURE_END(SetPresentConfigNV)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePresentMeteringFeaturesNV) {
	StructureClassHeader(PhysicalDevicePresentMeteringFeaturesNV);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePresentMeteringFeaturesNV)

#endif

VK_ENCAPSULATION_STRUCTURE_BEGIN(RenderingEndInfoEXT) {
	StructureClassHeader(RenderingEndInfoEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(RenderingEndInfoEXT)

inline void CmdEndRendering2EXT(const VkRenderingEndInfoEXT& renderingEndInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdEndRendering2EXT(ThreadContext::CommandBuffer(), &renderingEndInfo);
}
DefineRaiiFunction(CmdEndRendering2EXT, RenderingEndInfoEXT);

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC) {
	StructureClassHeader(PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(AccelerationStructureBuildRangeInfoKHR) {
	StructureClassHeader_NoSType(AccelerationStructureBuildRangeInfoKHR);
	DefineSetter_Copy(PrimitiveCount, uint32_t, primitiveCount);
	DefineSetter_Copy(PrimitiveOffset, uint32_t, primitiveOffset);
	DefineSetter_Copy(FirstVertex, uint32_t, firstVertex);
	DefineSetter_Copy(TransformOffset, uint32_t, transformOffset);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureBuildRangeInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureGeometryTrianglesDataKHR) {
	StructureClassHeader(AccelerationStructureGeometryTrianglesDataKHR);
	DefineSetter_Copy(VertexFormat, VkFormat, vertexFormat);
	DefineSetter_Copy(VertexData, VkDeviceOrHostAddressConstKHR, vertexData);
	DefineSetter_Copy(VertexStride, VkDeviceSize, vertexStride);
	DefineSetter_Copy(MaxVertex, uint32_t, maxVertex);
	DefineSetter_Copy(IndexType, VkIndexType, indexType);
	DefineSetter_Copy(IndexData, VkDeviceOrHostAddressConstKHR, indexData);
	DefineSetter_Copy(TransformData, VkDeviceOrHostAddressConstKHR, transformData);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometryTrianglesDataKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureGeometryAabbsDataKHR) {
	StructureClassHeader(AccelerationStructureGeometryAabbsDataKHR);
	DefineSetter_Copy(Data, VkDeviceOrHostAddressConstKHR, data);
	DefineSetter_Copy(Stride, VkDeviceSize, stride);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometryAabbsDataKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureGeometryInstancesDataKHR) {
	StructureClassHeader(AccelerationStructureGeometryInstancesDataKHR);
	DefineSetter_Copy(ArrayOfPointers, VkBool32, arrayOfPointers);
	DefineSetter_Copy(Data, VkDeviceOrHostAddressConstKHR, data);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometryInstancesDataKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_UNION_WRAPPER(AccelerationStructureGeometryDataKHR) {
	union {
		VkAccelerationStructureGeometryTrianglesDataKHR triangles;
		VkAccelerationStructureGeometryAabbsDataKHR     aabbs;
		VkAccelerationStructureGeometryInstancesDataKHR instances;
	};
	Structure(const VkAccelerationStructureGeometryTrianglesDataKHR& triangles) : triangles(triangles) {}
	Structure(const VkAccelerationStructureGeometryAabbsDataKHR& aabbs) : aabbs(aabbs) {}
	Structure(const VkAccelerationStructureGeometryInstancesDataKHR& instances) : instances(instances) {}
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometryDataKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureGeometryKHR) {
	StructureClassHeader(AccelerationStructureGeometryKHR);
	DefineSetter_Copy(GeometryType, VkGeometryTypeKHR, geometryType);
	DefineSetter_Copy(Geometry, VkAccelerationStructureGeometryDataKHR, geometry);
	DefineSetter_Copy(Flags, VkGeometryFlagsKHR, flags);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureGeometryKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureBuildGeometryInfoKHR) {
	StructureClassHeader(AccelerationStructureBuildGeometryInfoKHR);
	DefineSetter_Copy(Type, VkAccelerationStructureTypeKHR, type);
	DefineSetter_Copy(Flags, VkBuildAccelerationStructureFlagsKHR, flags);
	DefineSetter_Copy(Mode, VkBuildAccelerationStructureModeKHR, mode);
	DefineSetter_Copy(SrcAccelerationStructure, VkAccelerationStructureKHR, srcAccelerationStructure);
	DefineSetter_Copy(DstAccelerationStructure, VkAccelerationStructureKHR, dstAccelerationStructure);
	DefineSetter_Copy(GeometryCount, uint32_t, geometryCount);
	DefineSetter_ArrayRef(Geometries, const VkAccelerationStructureGeometryKHR, geometries, geometryCount);
	_&  Geometries(std::pair<uint32_t, const VkAccelerationStructureGeometryKHR* const*> geometries) &  { geometryCount = geometries.first; ppGeometries = geometries.second; return *this; }
	_&& Geometries(std::pair<uint32_t, const VkAccelerationStructureGeometryKHR* const*> geometries) && { return std::move(Geometries(geometries)); }
	_&  Geometries(std::pair<const VkAccelerationStructureGeometryKHR* const*, uint32_t> geometries) &  { geometryCount = geometries.second; ppGeometries = geometries.first; return *this; }
	_&& Geometries(std::pair<const VkAccelerationStructureGeometryKHR* const*, uint32_t> geometries) && { return std::move(Geometries(geometries)); }
	DefineSetter_Copy(ScratchData, VkDeviceOrHostAddressKHR, scratchData);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureBuildGeometryInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureCreateInfoKHR) {
	StructureClassHeader(AccelerationStructureCreateInfoKHR);
	DefineSetter_Copy(CreateFlags, VkAccelerationStructureCreateFlagsKHR, createFlags);
	DefineSetter_Copy(Buffer, VkBuffer, buffer);
	DefineSetter_Copy(Offset, VkDeviceSize, offset);
	DefineSetter_Copy(Size, VkDeviceSize, size);
	DefineSetter_Copy(Type, VkAccelerationStructureTypeKHR, type);
	DefineSetter_Copy(DeviceAddress, VkDeviceAddress, deviceAddress);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(WriteDescriptorSetAccelerationStructureKHR) {
	StructureClassHeader(WriteDescriptorSetAccelerationStructureKHR);
	DefineSetter_Copy(AccelerationStructureCount, uint32_t, accelerationStructureCount);
	DefineSetter_ArrayRef(AccelerationStructures, const VkAccelerationStructureKHR, accelerationStructures, accelerationStructureCount);
};
VK_ENCAPSULATION_STRUCTURE_END(WriteDescriptorSetAccelerationStructureKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceAccelerationStructureFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceAccelerationStructureFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceAccelerationStructureFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceAccelerationStructurePropertiesKHR) {
	StructureClassHeader(PhysicalDeviceAccelerationStructurePropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceAccelerationStructurePropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureDeviceAddressInfoKHR) {
	StructureClassHeader(AccelerationStructureDeviceAddressInfoKHR);
	DefineSetter_Copy(AccelerationStructure, VkAccelerationStructureKHR, accelerationStructure);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureDeviceAddressInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(AccelerationStructureVersionInfoKHR) {
	StructureClassHeader(AccelerationStructureVersionInfoKHR);
	DefineSetter_ArrayRefIgnoreC(VersionData, const uint8_t, version);
};
VK_ENCAPSULATION_STRUCTURE_END(AccelerationStructureVersionInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyAccelerationStructureToMemoryInfoKHR) {
	StructureClassHeader(CopyAccelerationStructureToMemoryInfoKHR);
	DefineSetter_Copy(Src, VkAccelerationStructureKHR, src);
	DefineSetter_Copy(Dst, VkDeviceOrHostAddressKHR, dst);
	DefineSetter_Copy(Mode, VkCopyAccelerationStructureModeKHR, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyAccelerationStructureToMemoryInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyMemoryToAccelerationStructureInfoKHR) {
	StructureClassHeader(CopyMemoryToAccelerationStructureInfoKHR);
	DefineSetter_Copy(Src, VkDeviceOrHostAddressConstKHR, src);
	DefineSetter_Copy(Dst, VkAccelerationStructureKHR, dst);
	DefineSetter_Copy(Mode, VkCopyAccelerationStructureModeKHR, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyMemoryToAccelerationStructureInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(CopyAccelerationStructureInfoKHR) {
	StructureClassHeader(CopyAccelerationStructureInfoKHR);
	DefineSetter_Copy(Src, VkAccelerationStructureKHR, src);
	DefineSetter_Copy(Dst, VkAccelerationStructureKHR, dst);
	DefineSetter_Copy(Mode, VkCopyAccelerationStructureModeKHR, mode);
};
VK_ENCAPSULATION_STRUCTURE_END(CopyAccelerationStructureInfoKHR)

inline VkResult CreateAccelerationStructureKHR(const VkAccelerationStructureCreateInfoKHR& createInfo, HandleRef<VkAccelerationStructureKHR> accelerationStructure) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateAccelerationStructureKHR(DeviceContext::Device(), &createInfo, ThreadContext::PAllocator(), &accelerationStructure);
}
DefineRaiiFunction_ResultL(VkResult, CreateAccelerationStructureKHR, AccelerationStructureCreateInfoKHR, HandleRef<VkAccelerationStructureKHR>, accelerationStructure);

inline void DestroyAccelerationStructureKHR(HandleRef<VkAccelerationStructureKHR> accelerationStructure, OptionalRef<const VkAllocationCallbacks> allocator = ThreadContext::Allocator()) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkDestroyAccelerationStructureKHR(DeviceContext::Device(), accelerationStructure, &allocator);
	accelerationStructure = VK_NULL_HANDLE;
}

inline void CmdBuildAccelerationStructuresKHR(ArrayRef<const VkAccelerationStructureBuildGeometryInfoKHR> infos, ArrayRef<const VkAccelerationStructureBuildRangeInfoKHR* const> buildRangeInfos) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBuildAccelerationStructuresKHR(ThreadContext::CommandBuffer(), infos.size(), infos, buildRangeInfos);
}
DefineRaiiFunction_L(CmdBuildAccelerationStructuresKHR, AccelerationStructureBuildGeometryInfoKHR, const VkAccelerationStructureBuildRangeInfoKHR* const&, pBuildRangeInfos);

inline void CmdBuildAccelerationStructuresIndirectKHR(ArrayRef<const VkAccelerationStructureBuildGeometryInfoKHR> infos, ArrayRef<const VkDeviceAddress> indirectDeviceAddresses, ArrayRef<const uint32_t> indirectStrides, ArrayRef<const uint32_t* const> maxPrimitiveCounts) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdBuildAccelerationStructuresIndirectKHR(ThreadContext::CommandBuffer(), infos.size(), infos, indirectDeviceAddresses, indirectStrides, maxPrimitiveCounts);
}

inline VkResult BuildAccelerationStructuresKHR(VkDeferredOperationKHR deferredOperation, ArrayRef<const VkAccelerationStructureBuildGeometryInfoKHR> infos, ArrayRef<const VkAccelerationStructureBuildRangeInfoKHR* const> buildRangeInfos) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkBuildAccelerationStructuresKHR(DeviceContext::Device(), deferredOperation, infos.size(), infos, buildRangeInfos);
}

inline VkResult CopyAccelerationStructureKHR(VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyAccelerationStructureKHR(DeviceContext::Device(), deferredOperation, &info);
}
DefineRaiiFunction_ResultR(VkResult, CopyAccelerationStructureKHR, VkDeferredOperationKHR, deferredOperation, CopyAccelerationStructureInfoKHR);

inline VkResult CopyAccelerationStructureToMemoryKHR(VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyAccelerationStructureToMemoryKHR(DeviceContext::Device(), deferredOperation, &info);
}
DefineRaiiFunction_ResultR(VkResult, CopyAccelerationStructureToMemoryKHR, VkDeferredOperationKHR, deferredOperation, CopyAccelerationStructureToMemoryInfoKHR);

inline VkResult CopyMemoryToAccelerationStructureKHR(VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCopyMemoryToAccelerationStructureKHR(DeviceContext::Device(), deferredOperation, &info);
}
DefineRaiiFunction_ResultR(VkResult, CopyMemoryToAccelerationStructureKHR, VkDeferredOperationKHR, deferredOperation, CopyMemoryToAccelerationStructureInfoKHR);

inline VkResult WriteAccelerationStructuresPropertiesKHR(ArrayRef<const VkAccelerationStructureKHR> accelerationStructures, VkQueryType queryType, ArrayRef<void> data, size_t stride) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkWriteAccelerationStructuresPropertiesKHR(DeviceContext::Device(), accelerationStructures.size(), accelerationStructures, queryType, data.size(), data, stride);
}
inline VkResult WriteAccelerationStructuresPropertiesKHR(ArrayRef<const VkAccelerationStructureKHR> accelerationStructures, VkQueryType queryType, IsNotRangeOrPointer auto& data, size_t stride) {
	return WriteAccelerationStructuresPropertiesKHR(accelerationStructures, queryType, { sizeof *&data, &data }, stride);
}

inline void CmdCopyAccelerationStructureKHR(const VkCopyAccelerationStructureInfoKHR& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyAccelerationStructureKHR(ThreadContext::CommandBuffer(), &info);
}
DefineRaiiFunction(CmdCopyAccelerationStructureKHR, CopyAccelerationStructureInfoKHR);

inline void CmdCopyAccelerationStructureToMemoryKHR(const VkCopyAccelerationStructureToMemoryInfoKHR& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyAccelerationStructureToMemoryKHR(ThreadContext::CommandBuffer(), &info);
}
DefineRaiiFunction(CmdCopyAccelerationStructureToMemoryKHR, CopyAccelerationStructureToMemoryInfoKHR);

inline void CmdCopyMemoryToAccelerationStructureKHR(const VkCopyMemoryToAccelerationStructureInfoKHR& info) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdCopyMemoryToAccelerationStructureKHR(ThreadContext::CommandBuffer(), &info);
}
DefineRaiiFunction(CmdCopyMemoryToAccelerationStructureKHR, CopyMemoryToAccelerationStructureInfoKHR);

inline VkDeviceAddress GetAccelerationStructureDeviceAddressKHR(const VkAccelerationStructureDeviceAddressInfoKHR& info) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetAccelerationStructureDeviceAddressKHR(DeviceContext::Device(), &info);
}
DefineRaiiFunction_Result(VkDeviceAddress, GetAccelerationStructureDeviceAddressKHR, AccelerationStructureDeviceAddressInfoKHR);

inline void CmdWriteAccelerationStructuresPropertiesKHR(ArrayRef<const VkAccelerationStructureKHR> accelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdWriteAccelerationStructuresPropertiesKHR(ThreadContext::CommandBuffer(), accelerationStructures.size(), accelerationStructures, queryType, queryPool, firstQuery);
}

inline void GetDeviceAccelerationStructureCompatibilityKHR(const VkAccelerationStructureVersionInfoKHR& versionInfo, VkAccelerationStructureCompatibilityKHR& compatibility) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetDeviceAccelerationStructureCompatibilityKHR(DeviceContext::Device(), &versionInfo, &compatibility);
}
DefineRaiiFunction_L(GetDeviceAccelerationStructureCompatibilityKHR, AccelerationStructureVersionInfoKHR, VkAccelerationStructureCompatibilityKHR&, compatibility);

inline void GetAccelerationStructureBuildSizesKHR(VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR& buildInfo, ArrayRef<const uint32_t> maxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR& sizeInfo) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkGetAccelerationStructureBuildSizesKHR(DeviceContext::Device(), buildType, &buildInfo, maxPrimitiveCounts, &sizeInfo);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(RayTracingShaderGroupCreateInfoKHR) {
	StructureClassHeader(RayTracingShaderGroupCreateInfoKHR);
	DefineSetter_Copy(Type, VkRayTracingShaderGroupTypeKHR, type);
	DefineSetter_Copy(GeneralShader, uint32_t, generalShader);
	DefineSetter_Copy(ClosestHitShader, uint32_t, closestHitShader);
	DefineSetter_Copy(AnyHitShader, uint32_t, anyHitShader);
	DefineSetter_Copy(IntersectionShader, uint32_t, intersectionShader);
	DefineSetter_ArrayRefIgnoreC(ShaderGroupCaptureReplayHandle, const void, shaderGroupCaptureReplayHandle);
	_&  ShaderGroupCaptureReplayHandle(const IsNotRangeOrPointer auto& shaderGroupCaptureReplayHandle) &  { pShaderGroupCaptureReplayHandle = &shaderGroupCaptureReplayHandle; return *this; }
	_&& ShaderGroupCaptureReplayHandle(const IsNotRangeOrPointer auto& shaderGroupCaptureReplayHandle) && { return std::move(ShaderGroupCaptureReplayHandle(shaderGroupCaptureReplayHandle)); }
	_&  ShaderGroupCaptureReplayHandle(IsNotRangeOrPointer auto&&) requires(!forTemporaryUsage) = delete;
};
VK_ENCAPSULATION_STRUCTURE_END(RayTracingShaderGroupCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RayTracingPipelineInterfaceCreateInfoKHR) {
	StructureClassHeader(RayTracingPipelineInterfaceCreateInfoKHR);
	DefineSetter_Copy(MaxPipelineRayPayloadSize, uint32_t, maxPipelineRayPayloadSize);
	DefineSetter_Copy(MaxPipelineRayHitAttributeSize, uint32_t, maxPipelineRayHitAttributeSize);
};
VK_ENCAPSULATION_STRUCTURE_END(RayTracingPipelineInterfaceCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(RayTracingPipelineCreateInfoKHR) {
	StructureClassHeader(RayTracingPipelineCreateInfoKHR, .basePipelineIndex = -1);
	DefineSetter_Copy(Flags, VkPipelineCreateFlags, flags);
	DefineSetter_Copy(StageCount, uint32_t, stageCount);
	DefineSetter_ArrayRef(Stages, const VkPipelineShaderStageCreateInfo, stages, stageCount);
	DefineSetter_Copy(GroupCount, uint32_t, groupCount);
	DefineSetter_ArrayRef(Groups, const VkRayTracingShaderGroupCreateInfoKHR, groups, groupCount);
	DefineSetter_Copy(MaxPipelineRayRecursionDepth, uint32_t, maxPipelineRayRecursionDepth);
	DefineSetter_Ref(LibraryInfo, const VkPipelineLibraryCreateInfoKHR, libraryInfo);
	DefineSetter_Ref(LibraryInterface, const VkRayTracingPipelineInterfaceCreateInfoKHR, libraryInterface);
	DefineSetter_Ref(DynamicState, const VkPipelineDynamicStateCreateInfo, dynamicState);
	DefineSetter_Copy(Layout, VkPipelineLayout, layout);
	DefineSetter_Copy(BasePipelineHandle, VkPipeline, basePipelineHandle);
	DefineSetter_Copy(BasePipelineIndex, int32_t, basePipelineIndex);
};
VK_ENCAPSULATION_STRUCTURE_END(RayTracingPipelineCreateInfoKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingPipelineFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceRayTracingPipelineFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingPipelineFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayTracingPipelinePropertiesKHR) {
	StructureClassHeader(PhysicalDeviceRayTracingPipelinePropertiesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayTracingPipelinePropertiesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(TraceRaysIndirectCommandKHR) {
	StructureClassHeader_NoSType(TraceRaysIndirectCommandKHR);
	DefineSetter_Copy(Width, uint32_t, width);
	DefineSetter_Copy(Height, uint32_t, height);
	DefineSetter_Copy(Depth, uint32_t, depth);
};
VK_ENCAPSULATION_STRUCTURE_END(TraceRaysIndirectCommandKHR)

inline void CmdTraceRaysKHR(const VkStridedDeviceAddressRegionKHR& raygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR& missShaderBindingTable, const VkStridedDeviceAddressRegionKHR& hitShaderBindingTable, const VkStridedDeviceAddressRegionKHR& callableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdTraceRaysKHR(ThreadContext::CommandBuffer(), &raygenShaderBindingTable, &missShaderBindingTable, &hitShaderBindingTable, &callableShaderBindingTable, width, height, depth);
}

inline VkResult CreateRayTracingPipelinesKHR(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, ArrayRef<const VkRayTracingPipelineCreateInfoKHR> createInfos, HandleArrayRef<VkPipeline> pipelines) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkCreateRayTracingPipelinesKHR(DeviceContext::Device(), deferredOperation, pipelineCache, createInfos.size(), createInfos, ThreadContext::PAllocator(), pipelines);
}

inline VkResult GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, ArrayRef<void> data) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(DeviceContext::Device(), pipeline, firstGroup, groupCount, data.size(), data);
}
inline VkResult GetRayTracingCaptureReplayShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, IsNotRangeOrPointer auto& data) {
	return GetRayTracingCaptureReplayShaderGroupHandlesKHR(pipeline, firstGroup, { sizeof *&data, &data });
}

inline void CmdTraceRaysIndirectKHR(const VkStridedDeviceAddressRegionKHR& raygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR& missShaderBindingTable, const VkStridedDeviceAddressRegionKHR& hitShaderBindingTable, const VkStridedDeviceAddressRegionKHR& callableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdTraceRaysIndirectKHR(ThreadContext::CommandBuffer(), &raygenShaderBindingTable, &missShaderBindingTable, &hitShaderBindingTable, &callableShaderBindingTable, indirectDeviceAddress);
}

inline VkDeviceSize GetRayTracingShaderGroupStackSizeKHR(VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) {
	return VK_ENCAPSULATION_DEVICE_DISPATCH vkGetRayTracingShaderGroupStackSizeKHR(DeviceContext::Device(), pipeline, group, groupShader);
}

inline void CmdSetRayTracingPipelineStackSizeKHR(uint32_t pipelineStackSize) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdSetRayTracingPipelineStackSizeKHR(ThreadContext::CommandBuffer(), pipelineStackSize);
}

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceRayQueryFeaturesKHR) {
	StructureClassHeader(PhysicalDeviceRayQueryFeaturesKHR);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceRayQueryFeaturesKHR)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMeshShaderFeaturesEXT) {
	StructureClassHeader(PhysicalDeviceMeshShaderFeaturesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMeshShaderFeaturesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN(PhysicalDeviceMeshShaderPropertiesEXT) {
	StructureClassHeader(PhysicalDeviceMeshShaderPropertiesEXT);
};
VK_ENCAPSULATION_STRUCTURE_END(PhysicalDeviceMeshShaderPropertiesEXT)

VK_ENCAPSULATION_STRUCTURE_BEGIN_NO_STYPE(DrawMeshTasksIndirectCommandEXT) {
	StructureClassHeader_NoSType(DrawMeshTasksIndirectCommandEXT);
	DefineSetter_Copy(GroupCountX, uint32_t, groupCountX);
	DefineSetter_Copy(GroupCountY, uint32_t, groupCountY);
	DefineSetter_Copy(GroupCountZ, uint32_t, groupCountZ);
};
VK_ENCAPSULATION_STRUCTURE_END(DrawMeshTasksIndirectCommandEXT)

inline void CmdDrawMeshTasksEXT(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMeshTasksEXT(ThreadContext::CommandBuffer(), groupCountX, groupCountY, groupCountZ);
}

inline void CmdDrawMeshTasksIndirectEXT(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMeshTasksIndirectEXT(ThreadContext::CommandBuffer(), buffer, offset, drawCount, stride);
}

inline void CmdDrawMeshTasksIndirectCountEXT(VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
	VK_ENCAPSULATION_DEVICE_DISPATCH vkCmdDrawMeshTasksIndirectCountEXT(ThreadContext::CommandBuffer(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VK_ENCAPSULATION_TYPE_ALIAS(Buffer, VkBuffer)
VK_ENCAPSULATION_TYPE_ALIAS(Image, VkImage)
VK_ENCAPSULATION_TYPE_ALIAS(Instance, VkInstance)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevice, VkPhysicalDevice)
VK_ENCAPSULATION_TYPE_ALIAS(Device, VkDevice)
VK_ENCAPSULATION_TYPE_ALIAS(Queue, VkQueue)
VK_ENCAPSULATION_TYPE_ALIAS(Semaphore, VkSemaphore)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBuffer, VkCommandBuffer)
VK_ENCAPSULATION_TYPE_ALIAS(Fence, VkFence)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceMemory, VkDeviceMemory)
VK_ENCAPSULATION_TYPE_ALIAS(Event, VkEvent)
VK_ENCAPSULATION_TYPE_ALIAS(QueryPool, VkQueryPool)
VK_ENCAPSULATION_TYPE_ALIAS(BufferView, VkBufferView)
VK_ENCAPSULATION_TYPE_ALIAS(ImageView, VkImageView)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderModule, VkShaderModule)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCache, VkPipelineCache)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineLayout, VkPipelineLayout)
VK_ENCAPSULATION_TYPE_ALIAS(Pipeline, VkPipeline)
VK_ENCAPSULATION_TYPE_ALIAS(RenderPass, VkRenderPass)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSetLayout, VkDescriptorSetLayout)
VK_ENCAPSULATION_TYPE_ALIAS(Sampler, VkSampler)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSet, VkDescriptorSet)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorPool, VkDescriptorPool)
VK_ENCAPSULATION_TYPE_ALIAS(Framebuffer, VkFramebuffer)
VK_ENCAPSULATION_TYPE_ALIAS(CommandPool, VkCommandPool)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrConversion, VkSamplerYcbcrConversion)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplate, VkDescriptorUpdateTemplate)
VK_ENCAPSULATION_TYPE_ALIAS(PrivateDataSlot, VkPrivateDataSlot)
VK_ENCAPSULATION_TYPE_ALIAS(SurfaceKHR, VkSurfaceKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SwapchainKHR, VkSwapchainKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DisplayKHR, VkDisplayKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DisplayModeKHR, VkDisplayModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoSessionKHR, VkVideoSessionKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoSessionParametersKHR, VkVideoSessionParametersKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DeferredOperationKHR, VkDeferredOperationKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineBinaryKHR, VkPipelineBinaryKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DebugReportCallbackEXT, VkDebugReportCallbackEXT)
VK_ENCAPSULATION_TYPE_ALIAS(CuModuleNVX, VkCuModuleNVX)
VK_ENCAPSULATION_TYPE_ALIAS(CuFunctionNVX, VkCuFunctionNVX)
VK_ENCAPSULATION_TYPE_ALIAS(DebugUtilsMessengerEXT, VkDebugUtilsMessengerEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ValidationCacheEXT, VkValidationCacheEXT)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureNV, VkAccelerationStructureNV)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceConfigurationINTEL, VkPerformanceConfigurationINTEL)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsLayoutNV, VkIndirectCommandsLayoutNV)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureKHR, VkAccelerationStructureKHR)
VK_ENCAPSULATION_TYPE_ALIAS(MicromapEXT, VkMicromapEXT)
VK_ENCAPSULATION_TYPE_ALIAS(TensorARM, VkTensorARM)
VK_ENCAPSULATION_TYPE_ALIAS(TensorViewARM, VkTensorViewARM)
VK_ENCAPSULATION_TYPE_ALIAS(OpticalFlowSessionNV, VkOpticalFlowSessionNV)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderEXT, VkShaderEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelineSessionARM, VkDataGraphPipelineSessionARM)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalComputeQueueNV, VkExternalComputeQueueNV)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectExecutionSetEXT, VkIndirectExecutionSetEXT)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsLayoutEXT, VkIndirectCommandsLayoutEXT)

VK_ENCAPSULATION_TYPE_ALIAS(Result, VkResult)
VK_ENCAPSULATION_TYPE_ALIAS(StructureType, VkStructureType)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCacheHeaderVersion, VkPipelineCacheHeaderVersion)
VK_ENCAPSULATION_TYPE_ALIAS(ImageLayout, VkImageLayout)
VK_ENCAPSULATION_TYPE_ALIAS(ObjectType, VkObjectType)
VK_ENCAPSULATION_TYPE_ALIAS(VendorId, VkVendorId)
VK_ENCAPSULATION_TYPE_ALIAS(SystemAllocationScope, VkSystemAllocationScope)
VK_ENCAPSULATION_TYPE_ALIAS(InternalAllocationType, VkInternalAllocationType)
VK_ENCAPSULATION_TYPE_ALIAS(Format, VkFormat)
VK_ENCAPSULATION_TYPE_ALIAS(ImageTiling, VkImageTiling)
VK_ENCAPSULATION_TYPE_ALIAS(ImageType, VkImageType)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceType, VkPhysicalDeviceType)
VK_ENCAPSULATION_TYPE_ALIAS(QueryType, VkQueryType)
VK_ENCAPSULATION_TYPE_ALIAS(SharingMode, VkSharingMode)
VK_ENCAPSULATION_TYPE_ALIAS(ComponentSwizzle, VkComponentSwizzle)
VK_ENCAPSULATION_TYPE_ALIAS(ImageViewType, VkImageViewType)
VK_ENCAPSULATION_TYPE_ALIAS(BlendFactor, VkBlendFactor)
VK_ENCAPSULATION_TYPE_ALIAS(BlendOp, VkBlendOp)
VK_ENCAPSULATION_TYPE_ALIAS(CompareOp, VkCompareOp)
VK_ENCAPSULATION_TYPE_ALIAS(DynamicState, VkDynamicState)
VK_ENCAPSULATION_TYPE_ALIAS(FrontFace, VkFrontFace)
VK_ENCAPSULATION_TYPE_ALIAS(VertexInputRate, VkVertexInputRate)
VK_ENCAPSULATION_TYPE_ALIAS(PrimitiveTopology, VkPrimitiveTopology)
VK_ENCAPSULATION_TYPE_ALIAS(PolygonMode, VkPolygonMode)
VK_ENCAPSULATION_TYPE_ALIAS(StencilOp, VkStencilOp)
VK_ENCAPSULATION_TYPE_ALIAS(LogicOp, VkLogicOp)
VK_ENCAPSULATION_TYPE_ALIAS(BorderColor, VkBorderColor)
VK_ENCAPSULATION_TYPE_ALIAS(Filter, VkFilter)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerAddressMode, VkSamplerAddressMode)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerMipmapMode, VkSamplerMipmapMode)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorType, VkDescriptorType)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentLoadOp, VkAttachmentLoadOp)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentStoreOp, VkAttachmentStoreOp)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineBindPoint, VkPipelineBindPoint)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBufferLevel, VkCommandBufferLevel)
VK_ENCAPSULATION_TYPE_ALIAS(IndexType, VkIndexType)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassContents, VkSubpassContents)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlagBits, VkAccessFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ImageAspectFlagBits, VkImageAspectFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(FormatFeatureFlagBits, VkFormatFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ImageCreateFlagBits, VkImageCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SampleCountFlagBits, VkSampleCountFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ImageUsageFlagBits, VkImageUsageFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(InstanceCreateFlagBits, VkInstanceCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryHeapFlagBits, VkMemoryHeapFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryPropertyFlagBits, VkMemoryPropertyFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(QueueFlagBits, VkQueueFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceQueueCreateFlagBits, VkDeviceQueueCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineStageFlagBits, VkPipelineStageFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryMapFlagBits, VkMemoryMapFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SparseMemoryBindFlagBits, VkSparseMemoryBindFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SparseImageFormatFlagBits, VkSparseImageFormatFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(FenceCreateFlagBits, VkFenceCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(EventCreateFlagBits, VkEventCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(QueryPipelineStatisticFlagBits, VkQueryPipelineStatisticFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(QueryPoolCreateFlagBits, VkQueryPoolCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(QueryResultFlagBits, VkQueryResultFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(BufferCreateFlagBits, VkBufferCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(BufferUsageFlagBits, VkBufferUsageFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ImageViewCreateFlagBits, VkImageViewCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCacheCreateFlagBits, VkPipelineCacheCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ColorComponentFlagBits, VkColorComponentFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreateFlagBits, VkPipelineCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineShaderStageCreateFlagBits, VkPipelineShaderStageCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderStageFlagBits, VkShaderStageFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(CullModeFlagBits, VkCullModeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineDepthStencilStateCreateFlagBits, VkPipelineDepthStencilStateCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineColorBlendStateCreateFlagBits, VkPipelineColorBlendStateCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineLayoutCreateFlagBits, VkPipelineLayoutCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerCreateFlagBits, VkSamplerCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorPoolCreateFlagBits, VkDescriptorPoolCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSetLayoutCreateFlagBits, VkDescriptorSetLayoutCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentDescriptionFlagBits, VkAttachmentDescriptionFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(DependencyFlagBits, VkDependencyFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(FramebufferCreateFlagBits, VkFramebufferCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(RenderPassCreateFlagBits, VkRenderPassCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassDescriptionFlagBits, VkSubpassDescriptionFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(CommandPoolCreateFlagBits, VkCommandPoolCreateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(CommandPoolResetFlagBits, VkCommandPoolResetFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBufferUsageFlagBits, VkCommandBufferUsageFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(QueryControlFlagBits, VkQueryControlFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBufferResetFlagBits, VkCommandBufferResetFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(StencilFaceFlagBits, VkStencilFaceFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PointClippingBehavior, VkPointClippingBehavior)
VK_ENCAPSULATION_TYPE_ALIAS(TessellationDomainOrigin, VkTessellationDomainOrigin)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrModelConversion, VkSamplerYcbcrModelConversion)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrRange, VkSamplerYcbcrRange)
VK_ENCAPSULATION_TYPE_ALIAS(ChromaLocation, VkChromaLocation)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplateType, VkDescriptorUpdateTemplateType)
VK_ENCAPSULATION_TYPE_ALIAS(SubgroupFeatureFlagBits, VkSubgroupFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PeerMemoryFeatureFlagBits, VkPeerMemoryFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryAllocateFlagBits, VkMemoryAllocateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryHandleTypeFlagBits, VkExternalMemoryHandleTypeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryFeatureFlagBits, VkExternalMemoryFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceHandleTypeFlagBits, VkExternalFenceHandleTypeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceFeatureFlagBits, VkExternalFenceFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(FenceImportFlagBits, VkFenceImportFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreImportFlagBits, VkSemaphoreImportFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreHandleTypeFlagBits, VkExternalSemaphoreHandleTypeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreFeatureFlagBits, VkExternalSemaphoreFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(DriverId, VkDriverId)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderFloatControlsIndependence, VkShaderFloatControlsIndependence)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerReductionMode, VkSamplerReductionMode)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreType, VkSemaphoreType)
VK_ENCAPSULATION_TYPE_ALIAS(ResolveModeFlagBits, VkResolveModeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorBindingFlagBits, VkDescriptorBindingFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreWaitFlagBits, VkSemaphoreWaitFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreationFeedbackFlagBits, VkPipelineCreationFeedbackFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ToolPurposeFlagBits, VkToolPurposeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SubmitFlagBits, VkSubmitFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingFlagBits, VkRenderingFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRobustnessBufferBehavior, VkPipelineRobustnessBufferBehavior)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRobustnessImageBehavior, VkPipelineRobustnessImageBehavior)
VK_ENCAPSULATION_TYPE_ALIAS(QueueGlobalPriority, VkQueueGlobalPriority)
VK_ENCAPSULATION_TYPE_ALIAS(LineRasterizationMode, VkLineRasterizationMode)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryUnmapFlagBits, VkMemoryUnmapFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(HostImageCopyFlagBits, VkHostImageCopyFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PresentModeKHR, VkPresentModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(ColorSpaceKHR, VkColorSpaceKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SurfaceTransformFlagBitsKHR, VkSurfaceTransformFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(CompositeAlphaFlagBitsKHR, VkCompositeAlphaFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SwapchainCreateFlagBitsKHR, VkSwapchainCreateFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceGroupPresentModeFlagBitsKHR, VkDeviceGroupPresentModeFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DisplayPlaneAlphaFlagBitsKHR, VkDisplayPlaneAlphaFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(QueryResultStatusKHR, VkQueryResultStatusKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoCodecOperationFlagBitsKHR, VkVideoCodecOperationFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoChromaSubsamplingFlagBitsKHR, VkVideoChromaSubsamplingFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoComponentBitDepthFlagBitsKHR, VkVideoComponentBitDepthFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoCapabilityFlagBitsKHR, VkVideoCapabilityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoSessionCreateFlagBitsKHR, VkVideoSessionCreateFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoSessionParametersCreateFlagBitsKHR, VkVideoSessionParametersCreateFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoCodingControlFlagBitsKHR, VkVideoCodingControlFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoDecodeCapabilityFlagBitsKHR, VkVideoDecodeCapabilityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoDecodeUsageFlagBitsKHR, VkVideoDecodeUsageFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH264CapabilityFlagBitsKHR, VkVideoEncodeH264CapabilityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH264StdFlagBitsKHR, VkVideoEncodeH264StdFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH264RateControlFlagBitsKHR, VkVideoEncodeH264RateControlFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265CapabilityFlagBitsKHR, VkVideoEncodeH265CapabilityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265StdFlagBitsKHR, VkVideoEncodeH265StdFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265CtbSizeFlagBitsKHR, VkVideoEncodeH265CtbSizeFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265TransformBlockSizeFlagBitsKHR, VkVideoEncodeH265TransformBlockSizeFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265RateControlFlagBitsKHR, VkVideoEncodeH265RateControlFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoDecodeH264PictureLayoutFlagBitsKHR, VkVideoDecodeH264PictureLayoutFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceCounterUnitKHR, VkPerformanceCounterUnitKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceCounterScopeKHR, VkPerformanceCounterScopeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceCounterStorageKHR, VkPerformanceCounterStorageKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceCounterDescriptionFlagBitsKHR, VkPerformanceCounterDescriptionFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AcquireProfilingLockFlagBitsKHR, VkAcquireProfilingLockFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(FragmentShadingRateCombinerOpKHR, VkFragmentShadingRateCombinerOpKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineExecutableStatisticFormatKHR, VkPipelineExecutableStatisticFormatKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeTuningModeKHR, VkVideoEncodeTuningModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeFlagBitsKHR, VkVideoEncodeFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeCapabilityFlagBitsKHR, VkVideoEncodeCapabilityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRateControlModeFlagBitsKHR, VkVideoEncodeRateControlModeFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeFeedbackFlagBitsKHR, VkVideoEncodeFeedbackFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeUsageFlagBitsKHR, VkVideoEncodeUsageFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeContentFlagBitsKHR, VkVideoEncodeContentFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PresentScalingFlagBitsKHR, VkPresentScalingFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PresentGravityFlagBitsKHR, VkPresentGravityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(ComponentTypeKHR, VkComponentTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(ScopeKHR, VkScopeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1PredictionModeKHR, VkVideoEncodeAV1PredictionModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1RateControlGroupKHR, VkVideoEncodeAV1RateControlGroupKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1CapabilityFlagBitsKHR, VkVideoEncodeAV1CapabilityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1StdFlagBitsKHR, VkVideoEncodeAV1StdFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1SuperblockSizeFlagBitsKHR, VkVideoEncodeAV1SuperblockSizeFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1RateControlFlagBitsKHR, VkVideoEncodeAV1RateControlFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(TimeDomainKHR, VkTimeDomainKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AddressCopyFlagBitsKHR, VkAddressCopyFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeIntraRefreshModeFlagBitsKHR, VkVideoEncodeIntraRefreshModeFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceLayeredApiKHR, VkPhysicalDeviceLayeredApiKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DefaultVertexAttributeValueKHR, VkDefaultVertexAttributeValueKHR)
VK_ENCAPSULATION_TYPE_ALIAS(DebugReportObjectTypeEXT, VkDebugReportObjectTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DebugReportFlagBitsEXT, VkDebugReportFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(RasterizationOrderAMD, VkRasterizationOrderAMD)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderInfoTypeAMD, VkShaderInfoTypeAMD)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryHandleTypeFlagBitsNV, VkExternalMemoryHandleTypeFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryFeatureFlagBitsNV, VkExternalMemoryFeatureFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(ValidationCheckEXT, VkValidationCheckEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ConditionalRenderingFlagBitsEXT, VkConditionalRenderingFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(SurfaceCounterFlagBitsEXT, VkSurfaceCounterFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DisplayPowerStateEXT, VkDisplayPowerStateEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceEventTypeEXT, VkDeviceEventTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DisplayEventTypeEXT, VkDisplayEventTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ViewportCoordinateSwizzleNV, VkViewportCoordinateSwizzleNV)
VK_ENCAPSULATION_TYPE_ALIAS(DiscardRectangleModeEXT, VkDiscardRectangleModeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ConservativeRasterizationModeEXT, VkConservativeRasterizationModeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageSeverityFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DebugUtilsMessageTypeFlagBitsEXT, VkDebugUtilsMessageTypeFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(BlendOverlapEXT, VkBlendOverlapEXT)
VK_ENCAPSULATION_TYPE_ALIAS(CoverageModulationModeNV, VkCoverageModulationModeNV)
VK_ENCAPSULATION_TYPE_ALIAS(ValidationCacheHeaderVersionEXT, VkValidationCacheHeaderVersionEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ShadingRatePaletteEntryNV, VkShadingRatePaletteEntryNV)
VK_ENCAPSULATION_TYPE_ALIAS(CoarseSampleOrderTypeNV, VkCoarseSampleOrderTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(RayTracingShaderGroupTypeKHR, VkRayTracingShaderGroupTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryTypeKHR, VkGeometryTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureTypeKHR, VkAccelerationStructureTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(CopyAccelerationStructureModeKHR, VkCopyAccelerationStructureModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureMemoryRequirementsTypeNV, VkAccelerationStructureMemoryRequirementsTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryFlagBitsKHR, VkGeometryFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryInstanceFlagBitsKHR, VkGeometryInstanceFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(BuildAccelerationStructureFlagBitsKHR, VkBuildAccelerationStructureFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCompilerControlFlagBitsAMD, VkPipelineCompilerControlFlagBitsAMD)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryOverallocationBehaviorAMD, VkMemoryOverallocationBehaviorAMD)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceConfigurationTypeINTEL, VkPerformanceConfigurationTypeINTEL)
VK_ENCAPSULATION_TYPE_ALIAS(QueryPoolSamplingModeINTEL, VkQueryPoolSamplingModeINTEL)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceOverrideTypeINTEL, VkPerformanceOverrideTypeINTEL)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceParameterTypeINTEL, VkPerformanceParameterTypeINTEL)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceValueTypeINTEL, VkPerformanceValueTypeINTEL)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderCorePropertiesFlagBitsAMD, VkShaderCorePropertiesFlagBitsAMD)
VK_ENCAPSULATION_TYPE_ALIAS(ValidationFeatureEnableEXT, VkValidationFeatureEnableEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ValidationFeatureDisableEXT, VkValidationFeatureDisableEXT)
VK_ENCAPSULATION_TYPE_ALIAS(CoverageReductionModeNV, VkCoverageReductionModeNV)
VK_ENCAPSULATION_TYPE_ALIAS(ProvokingVertexModeEXT, VkProvokingVertexModeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsTokenTypeNV, VkIndirectCommandsTokenTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectStateFlagBitsNV, VkIndirectStateFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsLayoutUsageFlagBitsNV, VkIndirectCommandsLayoutUsageFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(DepthBiasRepresentationEXT, VkDepthBiasRepresentationEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceMemoryReportEventTypeEXT, VkDeviceMemoryReportEventTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceDiagnosticsConfigFlagBitsNV, VkDeviceDiagnosticsConfigFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(TileShadingRenderPassFlagBitsQCOM, VkTileShadingRenderPassFlagBitsQCOM)
VK_ENCAPSULATION_TYPE_ALIAS(GraphicsPipelineLibraryFlagBitsEXT, VkGraphicsPipelineLibraryFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(FragmentShadingRateTypeNV, VkFragmentShadingRateTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(FragmentShadingRateNV, VkFragmentShadingRateNV)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureMotionInstanceTypeNV, VkAccelerationStructureMotionInstanceTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(ImageCompressionFlagBitsEXT, VkImageCompressionFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ImageCompressionFixedRateFlagBitsEXT, VkImageCompressionFixedRateFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceFaultAddressTypeEXT, VkDeviceFaultAddressTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceFaultVendorBinaryHeaderVersionEXT, VkDeviceFaultVendorBinaryHeaderVersionEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceAddressBindingTypeEXT, VkDeviceAddressBindingTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceAddressBindingFlagBitsEXT, VkDeviceAddressBindingFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(FrameBoundaryFlagBitsEXT, VkFrameBoundaryFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRgbModelConversionFlagBitsVALVE, VkVideoEncodeRgbModelConversionFlagBitsVALVE)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRgbRangeCompressionFlagBitsVALVE, VkVideoEncodeRgbRangeCompressionFlagBitsVALVE)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRgbChromaOffsetFlagBitsVALVE, VkVideoEncodeRgbChromaOffsetFlagBitsVALVE)
VK_ENCAPSULATION_TYPE_ALIAS(MicromapTypeEXT, VkMicromapTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(BuildMicromapModeEXT, VkBuildMicromapModeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(CopyMicromapModeEXT, VkCopyMicromapModeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(OpacityMicromapFormatEXT, VkOpacityMicromapFormatEXT)
VK_ENCAPSULATION_TYPE_ALIAS(OpacityMicromapSpecialIndexEXT, VkOpacityMicromapSpecialIndexEXT)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureCompatibilityKHR, VkAccelerationStructureCompatibilityKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureBuildTypeKHR, VkAccelerationStructureBuildTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(BuildMicromapFlagBitsEXT, VkBuildMicromapFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(MicromapCreateFlagBitsEXT, VkMicromapCreateFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(RayTracingLssIndexingModeNV, VkRayTracingLssIndexingModeNV)
VK_ENCAPSULATION_TYPE_ALIAS(RayTracingLssPrimitiveEndCapsModeNV, VkRayTracingLssPrimitiveEndCapsModeNV)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassMergeStatusEXT, VkSubpassMergeStatusEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DirectDriverLoadingModeLUNARG, VkDirectDriverLoadingModeLUNARG)
VK_ENCAPSULATION_TYPE_ALIAS(TensorTilingARM, VkTensorTilingARM)
VK_ENCAPSULATION_TYPE_ALIAS(OpticalFlowPerformanceLevelNV, VkOpticalFlowPerformanceLevelNV)
VK_ENCAPSULATION_TYPE_ALIAS(OpticalFlowSessionBindingPointNV, VkOpticalFlowSessionBindingPointNV)
VK_ENCAPSULATION_TYPE_ALIAS(OpticalFlowGridSizeFlagBitsNV, VkOpticalFlowGridSizeFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(OpticalFlowUsageFlagBitsNV, VkOpticalFlowUsageFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(OpticalFlowSessionCreateFlagBitsNV, VkOpticalFlowSessionCreateFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(OpticalFlowExecuteFlagBitsNV, VkOpticalFlowExecuteFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(AntiLagModeAMD, VkAntiLagModeAMD)
VK_ENCAPSULATION_TYPE_ALIAS(AntiLagStageAMD, VkAntiLagStageAMD)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderCodeTypeEXT, VkShaderCodeTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DepthClampModeEXT, VkDepthClampModeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderCreateFlagBitsEXT, VkShaderCreateFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(RayTracingInvocationReorderModeNV, VkRayTracingInvocationReorderModeNV)
VK_ENCAPSULATION_TYPE_ALIAS(CooperativeVectorMatrixLayoutNV, VkCooperativeVectorMatrixLayoutNV)
VK_ENCAPSULATION_TYPE_ALIAS(LayerSettingTypeEXT, VkLayerSettingTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(LatencyMarkerNV, VkLatencyMarkerNV)
VK_ENCAPSULATION_TYPE_ALIAS(OutOfBandQueueTypeNV, VkOutOfBandQueueTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelineSessionBindPointARM, VkDataGraphPipelineSessionBindPointARM)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelineSessionBindPointTypeARM, VkDataGraphPipelineSessionBindPointTypeARM)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelinePropertyARM, VkDataGraphPipelinePropertyARM)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDataGraphProcessingEngineTypeARM, VkPhysicalDeviceDataGraphProcessingEngineTypeARM)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDataGraphOperationTypeARM, VkPhysicalDeviceDataGraphOperationTypeARM)
VK_ENCAPSULATION_TYPE_ALIAS(BlockMatchWindowCompareModeQCOM, VkBlockMatchWindowCompareModeQCOM)
VK_ENCAPSULATION_TYPE_ALIAS(CubicFilterWeightsQCOM, VkCubicFilterWeightsQCOM)
VK_ENCAPSULATION_TYPE_ALIAS(LayeredDriverUnderlyingApiMSFT, VkLayeredDriverUnderlyingApiMSFT)
VK_ENCAPSULATION_TYPE_ALIAS(DisplaySurfaceStereoTypeNV, VkDisplaySurfaceStereoTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureTypeNV, VkClusterAccelerationStructureTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureOpTypeNV, VkClusterAccelerationStructureOpTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureOpModeNV, VkClusterAccelerationStructureOpModeNV)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureAddressResolutionFlagBitsNV, VkClusterAccelerationStructureAddressResolutionFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureClusterFlagBitsNV, VkClusterAccelerationStructureClusterFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureGeometryFlagBitsNV, VkClusterAccelerationStructureGeometryFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureIndexFormatFlagBitsNV, VkClusterAccelerationStructureIndexFormatFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(PartitionedAccelerationStructureOpTypeNV, VkPartitionedAccelerationStructureOpTypeNV)
VK_ENCAPSULATION_TYPE_ALIAS(PartitionedAccelerationStructureInstanceFlagBitsNV, VkPartitionedAccelerationStructureInstanceFlagBitsNV)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectExecutionSetInfoTypeEXT, VkIndirectExecutionSetInfoTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsTokenTypeEXT, VkIndirectCommandsTokenTypeEXT)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsInputModeFlagBitsEXT, VkIndirectCommandsInputModeFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsLayoutUsageFlagBitsEXT, VkIndirectCommandsLayoutUsageFlagBitsEXT)
VK_ENCAPSULATION_TYPE_ALIAS(BuildAccelerationStructureModeKHR, VkBuildAccelerationStructureModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureCreateFlagBitsKHR, VkAccelerationStructureCreateFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderGroupShaderKHR, VkShaderGroupShaderKHR)

VK_ENCAPSULATION_TYPE_ALIAS(Bool32, uint32_t)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceAddress, uint64_t)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceSize, uint64_t)
VK_ENCAPSULATION_TYPE_ALIAS(Flags, uint32_t)
VK_ENCAPSULATION_TYPE_ALIAS(SampleMask, uint32_t)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ImageAspectFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(FormatFeatureFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ImageCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SampleCountFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ImageUsageFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(InstanceCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryHeapFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryPropertyFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(QueueFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceQueueCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineStageFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryMapFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SparseMemoryBindFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SparseImageFormatFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(FenceCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(EventCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(QueryPipelineStatisticFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(QueryPoolCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(QueryResultFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(BufferCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(BufferUsageFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(BufferViewCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ImageViewCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderModuleCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCacheCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ColorComponentFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineShaderStageCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(CullModeFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineVertexInputStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineInputAssemblyStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineTessellationStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineViewportStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRasterizationStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineMultisampleStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineDepthStencilStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineColorBlendStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineDynamicStateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineLayoutCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderStageFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorPoolCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorPoolResetFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSetLayoutCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentDescriptionFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DependencyFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(FramebufferCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(RenderPassCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassDescriptionFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(CommandPoolCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(CommandPoolResetFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBufferUsageFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(QueryControlFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBufferResetFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(StencilFaceFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SubgroupFeatureFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PeerMemoryFeatureFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryAllocateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(CommandPoolTrimFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplateCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryHandleTypeFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryFeatureFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceHandleTypeFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceFeatureFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(FenceImportFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreImportFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreHandleTypeFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreFeatureFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceVariablePointerFeatures, PhysicalDeviceVariablePointersFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderDrawParameterFeatures, PhysicalDeviceShaderDrawParametersFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(ResolveModeFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorBindingFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreWaitFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(Flags64, uint64_t)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreationFeedbackFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ToolPurposeFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PrivateDataSlotCreateFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineStageFlags2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineStageFlagBits2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlags2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlagBits2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(SubmitFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(FormatFeatureFlags2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(FormatFeatureFlagBits2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryUnmapFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreateFlags2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreateFlagBits2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(BufferUsageFlags2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(BufferUsageFlagBits2, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(HostImageCopyFlags, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(CompositeAlphaFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SurfaceTransformFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SwapchainCreateFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceGroupPresentModeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DisplayModeCreateFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DisplayPlaneAlphaFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DisplaySurfaceCreateFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoCodecOperationFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoChromaSubsamplingFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoComponentBitDepthFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoCapabilityFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoSessionCreateFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoSessionParametersCreateFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoBeginCodingFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEndCodingFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoCodingControlFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoDecodeCapabilityFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoDecodeUsageFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoDecodeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH264CapabilityFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH264StdFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH264RateControlFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265CapabilityFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265StdFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265CtbSizeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265TransformBlockSizeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeH265RateControlFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoDecodeH264PictureLayoutFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingFlagsKHR, RenderingFlags)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingFlagBitsKHR, RenderingFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingInfoKHR, RenderingInfo)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingAttachmentInfoKHR, RenderingAttachmentInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRenderingCreateInfoKHR, PipelineRenderingCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDynamicRenderingFeaturesKHR, PhysicalDeviceDynamicRenderingFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBufferInheritanceRenderingInfoKHR, CommandBufferInheritanceRenderingInfo)
VK_ENCAPSULATION_TYPE_ALIAS(RenderPassMultiviewCreateInfoKHR, RenderPassMultiviewCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMultiviewFeaturesKHR, PhysicalDeviceMultiviewFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMultiviewPropertiesKHR, PhysicalDeviceMultiviewProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceFeatures2KHR, PhysicalDeviceFeatures2)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceProperties2KHR, PhysicalDeviceProperties2)
VK_ENCAPSULATION_TYPE_ALIAS(FormatProperties2KHR, FormatProperties2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageFormatProperties2KHR, ImageFormatProperties2)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceImageFormatInfo2KHR, PhysicalDeviceImageFormatInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(QueueFamilyProperties2KHR, QueueFamilyProperties2)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMemoryProperties2KHR, PhysicalDeviceMemoryProperties2)
VK_ENCAPSULATION_TYPE_ALIAS(SparseImageFormatProperties2KHR, SparseImageFormatProperties2)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSparseImageFormatInfo2KHR, PhysicalDeviceSparseImageFormatInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(PeerMemoryFeatureFlagsKHR, PeerMemoryFeatureFlags)
VK_ENCAPSULATION_TYPE_ALIAS(PeerMemoryFeatureFlagBitsKHR, PeerMemoryFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryAllocateFlagsKHR, MemoryAllocateFlags)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryAllocateFlagBitsKHR, MemoryAllocateFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryAllocateFlagsInfoKHR, MemoryAllocateFlagsInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceGroupRenderPassBeginInfoKHR, DeviceGroupRenderPassBeginInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceGroupCommandBufferBeginInfoKHR, DeviceGroupCommandBufferBeginInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceGroupSubmitInfoKHR, DeviceGroupSubmitInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceGroupBindSparseInfoKHR, DeviceGroupBindSparseInfo)
VK_ENCAPSULATION_TYPE_ALIAS(BindBufferMemoryDeviceGroupInfoKHR, BindBufferMemoryDeviceGroupInfo)
VK_ENCAPSULATION_TYPE_ALIAS(BindImageMemoryDeviceGroupInfoKHR, BindImageMemoryDeviceGroupInfo)
VK_ENCAPSULATION_TYPE_ALIAS(CommandPoolTrimFlagsKHR, CommandPoolTrimFlags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceGroupPropertiesKHR, PhysicalDeviceGroupProperties)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceGroupDeviceCreateInfoKHR, DeviceGroupDeviceCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryHandleTypeFlagsKHR, ExternalMemoryHandleTypeFlags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryHandleTypeFlagBitsKHR, ExternalMemoryHandleTypeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryFeatureFlagsKHR, ExternalMemoryFeatureFlags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryFeatureFlagBitsKHR, ExternalMemoryFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryPropertiesKHR, ExternalMemoryProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceExternalImageFormatInfoKHR, PhysicalDeviceExternalImageFormatInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalImageFormatPropertiesKHR, ExternalImageFormatProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceExternalBufferInfoKHR, PhysicalDeviceExternalBufferInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalBufferPropertiesKHR, ExternalBufferProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceIDPropertiesKHR, PhysicalDeviceIDProperties)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryImageCreateInfoKHR, ExternalMemoryImageCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryBufferCreateInfoKHR, ExternalMemoryBufferCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExportMemoryAllocateInfoKHR, ExportMemoryAllocateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreHandleTypeFlagsKHR, ExternalSemaphoreHandleTypeFlags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreHandleTypeFlagBitsKHR, ExternalSemaphoreHandleTypeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreFeatureFlagsKHR, ExternalSemaphoreFeatureFlags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphoreFeatureFlagBitsKHR, ExternalSemaphoreFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceExternalSemaphoreInfoKHR, PhysicalDeviceExternalSemaphoreInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalSemaphorePropertiesKHR, ExternalSemaphoreProperties)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreImportFlagsKHR, SemaphoreImportFlags)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreImportFlagBitsKHR, SemaphoreImportFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExportSemaphoreCreateInfoKHR, ExportSemaphoreCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePushDescriptorPropertiesKHR, PhysicalDevicePushDescriptorProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderFloat16Int8FeaturesKHR, PhysicalDeviceShaderFloat16Int8Features)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceFloat16Int8FeaturesKHR, PhysicalDeviceShaderFloat16Int8Features)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevice16BitStorageFeaturesKHR, PhysicalDevice16BitStorageFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplateKHR, DescriptorUpdateTemplate)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplateTypeKHR, DescriptorUpdateTemplateType)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplateCreateFlagsKHR, DescriptorUpdateTemplateCreateFlags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplateEntryKHR, DescriptorUpdateTemplateEntry)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorUpdateTemplateCreateInfoKHR, DescriptorUpdateTemplateCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceImagelessFramebufferFeaturesKHR, PhysicalDeviceImagelessFramebufferFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(FramebufferAttachmentsCreateInfoKHR, FramebufferAttachmentsCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(FramebufferAttachmentImageInfoKHR, FramebufferAttachmentImageInfo)
VK_ENCAPSULATION_TYPE_ALIAS(RenderPassAttachmentBeginInfoKHR, RenderPassAttachmentBeginInfo)
VK_ENCAPSULATION_TYPE_ALIAS(RenderPassCreateInfo2KHR, RenderPassCreateInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentDescription2KHR, AttachmentDescription2)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentReference2KHR, AttachmentReference2)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassDescription2KHR, SubpassDescription2)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassDependency2KHR, SubpassDependency2)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassBeginInfoKHR, SubpassBeginInfo)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassEndInfoKHR, SubpassEndInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceHandleTypeFlagsKHR, ExternalFenceHandleTypeFlags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceHandleTypeFlagBitsKHR, ExternalFenceHandleTypeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceFeatureFlagsKHR, ExternalFenceFeatureFlags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFenceFeatureFlagBitsKHR, ExternalFenceFeatureFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceExternalFenceInfoKHR, PhysicalDeviceExternalFenceInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalFencePropertiesKHR, ExternalFenceProperties)
VK_ENCAPSULATION_TYPE_ALIAS(FenceImportFlagsKHR, FenceImportFlags)
VK_ENCAPSULATION_TYPE_ALIAS(FenceImportFlagBitsKHR, FenceImportFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ExportFenceCreateInfoKHR, ExportFenceCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PerformanceCounterDescriptionFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(AcquireProfilingLockFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PointClippingBehaviorKHR, PointClippingBehavior)
VK_ENCAPSULATION_TYPE_ALIAS(TessellationDomainOriginKHR, TessellationDomainOrigin)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePointClippingPropertiesKHR, PhysicalDevicePointClippingProperties)
VK_ENCAPSULATION_TYPE_ALIAS(RenderPassInputAttachmentAspectCreateInfoKHR, RenderPassInputAttachmentAspectCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(InputAttachmentAspectReferenceKHR, InputAttachmentAspectReference)
VK_ENCAPSULATION_TYPE_ALIAS(ImageViewUsageCreateInfoKHR, ImageViewUsageCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineTessellationDomainOriginStateCreateInfoKHR, PipelineTessellationDomainOriginStateCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceVariablePointerFeaturesKHR, PhysicalDeviceVariablePointersFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceVariablePointersFeaturesKHR, PhysicalDeviceVariablePointersFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryDedicatedRequirementsKHR, MemoryDedicatedRequirements)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryDedicatedAllocateInfoKHR, MemoryDedicatedAllocateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(BufferMemoryRequirementsInfo2KHR, BufferMemoryRequirementsInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageMemoryRequirementsInfo2KHR, ImageMemoryRequirementsInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageSparseMemoryRequirementsInfo2KHR, ImageSparseMemoryRequirementsInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryRequirements2KHR, MemoryRequirements2)
VK_ENCAPSULATION_TYPE_ALIAS(SparseImageMemoryRequirements2KHR, SparseImageMemoryRequirements2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageFormatListCreateInfoKHR, ImageFormatListCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrConversionKHR, SamplerYcbcrConversion)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrModelConversionKHR, SamplerYcbcrModelConversion)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrRangeKHR, SamplerYcbcrRange)
VK_ENCAPSULATION_TYPE_ALIAS(ChromaLocationKHR, ChromaLocation)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrConversionCreateInfoKHR, SamplerYcbcrConversionCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrConversionInfoKHR, SamplerYcbcrConversionInfo)
VK_ENCAPSULATION_TYPE_ALIAS(BindImagePlaneMemoryInfoKHR, BindImagePlaneMemoryInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ImagePlaneMemoryRequirementsInfoKHR, ImagePlaneMemoryRequirementsInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSamplerYcbcrConversionFeaturesKHR, PhysicalDeviceSamplerYcbcrConversionFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerYcbcrConversionImageFormatPropertiesKHR, SamplerYcbcrConversionImageFormatProperties)
VK_ENCAPSULATION_TYPE_ALIAS(BindBufferMemoryInfoKHR, BindBufferMemoryInfo)
VK_ENCAPSULATION_TYPE_ALIAS(BindImageMemoryInfoKHR, BindImageMemoryInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMaintenance3PropertiesKHR, PhysicalDeviceMaintenance3Properties)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSetLayoutSupportKHR, DescriptorSetLayoutSupport)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR, PhysicalDeviceShaderSubgroupExtendedTypesFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevice8BitStorageFeaturesKHR, PhysicalDevice8BitStorageFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderAtomicInt64FeaturesKHR, PhysicalDeviceShaderAtomicInt64Features)
VK_ENCAPSULATION_TYPE_ALIAS(QueueGlobalPriorityKHR, QueueGlobalPriority)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceQueueGlobalPriorityCreateInfoKHR, DeviceQueueGlobalPriorityCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceGlobalPriorityQueryFeaturesKHR, PhysicalDeviceGlobalPriorityQueryFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(QueueFamilyGlobalPriorityPropertiesKHR, QueueFamilyGlobalPriorityProperties)
VK_ENCAPSULATION_TYPE_ALIAS(DriverIdKHR, DriverId)
VK_ENCAPSULATION_TYPE_ALIAS(ConformanceVersionKHR, ConformanceVersion)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDriverPropertiesKHR, PhysicalDeviceDriverProperties)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderFloatControlsIndependenceKHR, ShaderFloatControlsIndependence)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceFloatControlsPropertiesKHR, PhysicalDeviceFloatControlsProperties)
VK_ENCAPSULATION_TYPE_ALIAS(ResolveModeFlagBitsKHR, ResolveModeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ResolveModeFlagsKHR, ResolveModeFlags)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassDescriptionDepthStencilResolveKHR, SubpassDescriptionDepthStencilResolve)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDepthStencilResolvePropertiesKHR, PhysicalDeviceDepthStencilResolveProperties)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreTypeKHR, SemaphoreType)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreWaitFlagBitsKHR, SemaphoreWaitFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreWaitFlagsKHR, SemaphoreWaitFlags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceTimelineSemaphoreFeaturesKHR, PhysicalDeviceTimelineSemaphoreFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceTimelineSemaphorePropertiesKHR, PhysicalDeviceTimelineSemaphoreProperties)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreTypeCreateInfoKHR, SemaphoreTypeCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(TimelineSemaphoreSubmitInfoKHR, TimelineSemaphoreSubmitInfo)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreWaitInfoKHR, SemaphoreWaitInfo)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreSignalInfoKHR, SemaphoreSignalInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceVulkanMemoryModelFeaturesKHR, PhysicalDeviceVulkanMemoryModelFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderTerminateInvocationFeaturesKHR, PhysicalDeviceShaderTerminateInvocationFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDynamicRenderingLocalReadFeaturesKHR, PhysicalDeviceDynamicRenderingLocalReadFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingAttachmentLocationInfoKHR, RenderingAttachmentLocationInfo)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingInputAttachmentIndexInfoKHR, RenderingInputAttachmentIndexInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR, PhysicalDeviceSeparateDepthStencilLayoutsFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentReferenceStencilLayoutKHR, AttachmentReferenceStencilLayout)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentDescriptionStencilLayoutKHR, AttachmentDescriptionStencilLayout)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceUniformBufferStandardLayoutFeaturesKHR, PhysicalDeviceUniformBufferStandardLayoutFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceBufferDeviceAddressFeaturesKHR, PhysicalDeviceBufferDeviceAddressFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(BufferDeviceAddressInfoKHR, BufferDeviceAddressInfo)
VK_ENCAPSULATION_TYPE_ALIAS(BufferOpaqueCaptureAddressCreateInfoKHR, BufferOpaqueCaptureAddressCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryOpaqueCaptureAddressAllocateInfoKHR, MemoryOpaqueCaptureAddressAllocateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceMemoryOpaqueCaptureAddressInfoKHR, DeviceMemoryOpaqueCaptureAddressInfo)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryUnmapFlagBitsKHR, MemoryUnmapFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryUnmapFlagsKHR, MemoryUnmapFlags)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryMapInfoKHR, MemoryMapInfo)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryUnmapInfoKHR, MemoryUnmapInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderIntegerDotProductFeaturesKHR, PhysicalDeviceShaderIntegerDotProductFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderIntegerDotProductPropertiesKHR, PhysicalDeviceShaderIntegerDotProductProperties)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeCapabilityFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRateControlModeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeFeedbackFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeUsageFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeContentFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRateControlFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineStageFlags2KHR, PipelineStageFlags2)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineStageFlagBits2KHR, PipelineStageFlagBits2)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlags2KHR, AccessFlags2)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlagBits2KHR, AccessFlagBits2)
VK_ENCAPSULATION_TYPE_ALIAS(SubmitFlagBitsKHR, SubmitFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(SubmitFlagsKHR, SubmitFlags)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryBarrier2KHR, MemoryBarrier2)
VK_ENCAPSULATION_TYPE_ALIAS(BufferMemoryBarrier2KHR, BufferMemoryBarrier2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageMemoryBarrier2KHR, ImageMemoryBarrier2)
VK_ENCAPSULATION_TYPE_ALIAS(DependencyInfoKHR, DependencyInfo)
VK_ENCAPSULATION_TYPE_ALIAS(SubmitInfo2KHR, SubmitInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(SemaphoreSubmitInfoKHR, SemaphoreSubmitInfo)
VK_ENCAPSULATION_TYPE_ALIAS(CommandBufferSubmitInfoKHR, CommandBufferSubmitInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSynchronization2FeaturesKHR, PhysicalDeviceSynchronization2Features)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR, PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(CopyBufferInfo2KHR, CopyBufferInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(CopyImageInfo2KHR, CopyImageInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(CopyBufferToImageInfo2KHR, CopyBufferToImageInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(CopyImageToBufferInfo2KHR, CopyImageToBufferInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(BlitImageInfo2KHR, BlitImageInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(ResolveImageInfo2KHR, ResolveImageInfo2)
VK_ENCAPSULATION_TYPE_ALIAS(BufferCopy2KHR, BufferCopy2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageCopy2KHR, ImageCopy2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageBlit2KHR, ImageBlit2)
VK_ENCAPSULATION_TYPE_ALIAS(BufferImageCopy2KHR, BufferImageCopy2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageResolve2KHR, ImageResolve2)
VK_ENCAPSULATION_TYPE_ALIAS(FormatFeatureFlags2KHR, FormatFeatureFlags2)
VK_ENCAPSULATION_TYPE_ALIAS(FormatFeatureFlagBits2KHR, FormatFeatureFlagBits2)
VK_ENCAPSULATION_TYPE_ALIAS(FormatProperties3KHR, FormatProperties3)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMaintenance4FeaturesKHR, PhysicalDeviceMaintenance4Features)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMaintenance4PropertiesKHR, PhysicalDeviceMaintenance4Properties)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceBufferMemoryRequirementsKHR, DeviceBufferMemoryRequirements)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceImageMemoryRequirementsKHR, DeviceImageMemoryRequirements)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderSubgroupRotateFeaturesKHR, PhysicalDeviceShaderSubgroupRotateFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreateFlags2KHR, PipelineCreateFlags2)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreateFlagBits2KHR, PipelineCreateFlagBits2)
VK_ENCAPSULATION_TYPE_ALIAS(BufferUsageFlags2KHR, BufferUsageFlags2)
VK_ENCAPSULATION_TYPE_ALIAS(BufferUsageFlagBits2KHR, BufferUsageFlagBits2)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMaintenance5FeaturesKHR, PhysicalDeviceMaintenance5Features)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMaintenance5PropertiesKHR, PhysicalDeviceMaintenance5Properties)
VK_ENCAPSULATION_TYPE_ALIAS(RenderingAreaInfoKHR, RenderingAreaInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceImageSubresourceInfoKHR, DeviceImageSubresourceInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ImageSubresource2KHR, ImageSubresource2)
VK_ENCAPSULATION_TYPE_ALIAS(SubresourceLayout2KHR, SubresourceLayout2)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreateFlags2CreateInfoKHR, PipelineCreateFlags2CreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(BufferUsageFlags2CreateInfoKHR, BufferUsageFlags2CreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PresentScalingFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PresentGravityFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1CapabilityFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1StdFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1SuperblockSizeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeAV1RateControlFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceVertexAttributeDivisorPropertiesKHR, PhysicalDeviceVertexAttributeDivisorProperties)
VK_ENCAPSULATION_TYPE_ALIAS(VertexInputBindingDivisorDescriptionKHR, VertexInputBindingDivisorDescription)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineVertexInputDivisorStateCreateInfoKHR, PipelineVertexInputDivisorStateCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceVertexAttributeDivisorFeaturesKHR, PhysicalDeviceVertexAttributeDivisorFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderFloatControls2FeaturesKHR, PhysicalDeviceShaderFloatControls2Features)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceIndexTypeUint8FeaturesKHR, PhysicalDeviceIndexTypeUint8Features)
VK_ENCAPSULATION_TYPE_ALIAS(LineRasterizationModeKHR, LineRasterizationMode)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceLineRasterizationFeaturesKHR, PhysicalDeviceLineRasterizationFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceLineRasterizationPropertiesKHR, PhysicalDeviceLineRasterizationProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRasterizationLineStateCreateInfoKHR, PipelineRasterizationLineStateCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderExpectAssumeFeaturesKHR, PhysicalDeviceShaderExpectAssumeFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMaintenance6FeaturesKHR, PhysicalDeviceMaintenance6Features)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMaintenance6PropertiesKHR, PhysicalDeviceMaintenance6Properties)
VK_ENCAPSULATION_TYPE_ALIAS(BindMemoryStatusKHR, BindMemoryStatus)
VK_ENCAPSULATION_TYPE_ALIAS(BindDescriptorSetsInfoKHR, BindDescriptorSetsInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PushConstantsInfoKHR, PushConstantsInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PushDescriptorSetInfoKHR, PushDescriptorSetInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PushDescriptorSetWithTemplateInfoKHR, PushDescriptorSetWithTemplateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(AddressCopyFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeIntraRefreshModeFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlags3KHR, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(AccessFlagBits3KHR, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(DebugReportFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRasterizationStateStreamCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryHandleTypeFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ExternalMemoryFeatureFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceTextureCompressionASTCHDRFeaturesEXT, PhysicalDeviceTextureCompressionASTCHDRFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRobustnessBufferBehaviorEXT, PipelineRobustnessBufferBehavior)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRobustnessImageBehaviorEXT, PipelineRobustnessImageBehavior)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePipelineRobustnessFeaturesEXT, PhysicalDevicePipelineRobustnessFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePipelineRobustnessPropertiesEXT, PhysicalDevicePipelineRobustnessProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRobustnessCreateInfoEXT, PipelineRobustnessCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ConditionalRenderingFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SurfaceCounterFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineViewportSwizzleStateCreateFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineDiscardRectangleStateCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRasterizationConservativeStateCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRasterizationDepthClipStateCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DebugUtilsMessengerCallbackDataFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DebugUtilsMessageTypeFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DebugUtilsMessageSeverityFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DebugUtilsMessengerCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerReductionModeEXT, SamplerReductionMode)
VK_ENCAPSULATION_TYPE_ALIAS(SamplerReductionModeCreateInfoEXT, SamplerReductionModeCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSamplerFilterMinmaxPropertiesEXT, PhysicalDeviceSamplerFilterMinmaxProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceInlineUniformBlockFeaturesEXT, PhysicalDeviceInlineUniformBlockFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceInlineUniformBlockPropertiesEXT, PhysicalDeviceInlineUniformBlockProperties)
VK_ENCAPSULATION_TYPE_ALIAS(WriteDescriptorSetInlineUniformBlockEXT, WriteDescriptorSetInlineUniformBlock)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorPoolInlineUniformBlockCreateInfoEXT, DescriptorPoolInlineUniformBlockCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCoverageToColorStateCreateFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCoverageModulationStateCreateFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(AttachmentSampleCountInfoNV, AttachmentSampleCountInfoAMD)
VK_ENCAPSULATION_TYPE_ALIAS(ValidationCacheCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorBindingFlagBitsEXT, DescriptorBindingFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorBindingFlagsEXT, DescriptorBindingFlags)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSetLayoutBindingFlagsCreateInfoEXT, DescriptorSetLayoutBindingFlagsCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDescriptorIndexingFeaturesEXT, PhysicalDeviceDescriptorIndexingFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDescriptorIndexingPropertiesEXT, PhysicalDeviceDescriptorIndexingProperties)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSetVariableDescriptorCountAllocateInfoEXT, DescriptorSetVariableDescriptorCountAllocateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DescriptorSetVariableDescriptorCountLayoutSupportEXT, DescriptorSetVariableDescriptorCountLayoutSupport)
VK_ENCAPSULATION_TYPE_ALIAS(RayTracingShaderGroupTypeNV, RayTracingShaderGroupTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryTypeNV, GeometryTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureTypeNV, AccelerationStructureTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(CopyAccelerationStructureModeNV, CopyAccelerationStructureModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryFlagsNV, GeometryFlagsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryFlagBitsNV, GeometryFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryInstanceFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryInstanceFlagsNV, GeometryInstanceFlagsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(GeometryInstanceFlagBitsNV, GeometryInstanceFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(BuildAccelerationStructureFlagsKHR, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(BuildAccelerationStructureFlagsNV, BuildAccelerationStructureFlagsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(BuildAccelerationStructureFlagBitsNV, BuildAccelerationStructureFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(TransformMatrixNV, TransformMatrixKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AabbPositionsNV, AabbPositionsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureInstanceNV, AccelerationStructureInstanceKHR)
VK_ENCAPSULATION_TYPE_ALIAS(QueueGlobalPriorityEXT, QueueGlobalPriority)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceQueueGlobalPriorityCreateInfoEXT, DeviceQueueGlobalPriorityCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCompilerControlFlagsAMD, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(TimeDomainEXT, TimeDomainKHR)
VK_ENCAPSULATION_TYPE_ALIAS(CalibratedTimestampInfoEXT, CalibratedTimestampInfoKHR)
VK_ENCAPSULATION_TYPE_ALIAS(VertexInputBindingDivisorDescriptionEXT, VertexInputBindingDivisorDescription)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineVertexInputDivisorStateCreateInfoEXT, PipelineVertexInputDivisorStateCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceVertexAttributeDivisorFeaturesEXT, PhysicalDeviceVertexAttributeDivisorFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreationFeedbackFlagBitsEXT, PipelineCreationFeedbackFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreationFeedbackFlagsEXT, PipelineCreationFeedbackFlags)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreationFeedbackCreateInfoEXT, PipelineCreationFeedbackCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCreationFeedbackEXT, PipelineCreationFeedback)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceComputeShaderDerivativesFeaturesNV, PhysicalDeviceComputeShaderDerivativesFeaturesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceFragmentShaderBarycentricFeaturesNV, PhysicalDeviceFragmentShaderBarycentricFeaturesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(QueryPoolCreateInfoINTEL, QueryPoolPerformanceQueryCreateInfoINTEL)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceScalarBlockLayoutFeaturesEXT, PhysicalDeviceScalarBlockLayoutFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSubgroupSizeControlFeaturesEXT, PhysicalDeviceSubgroupSizeControlFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSubgroupSizeControlPropertiesEXT, PhysicalDeviceSubgroupSizeControlProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineShaderStageRequiredSubgroupSizeCreateInfoEXT, PipelineShaderStageRequiredSubgroupSizeCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderCorePropertiesFlagsAMD, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceBufferAddressFeaturesEXT, PhysicalDeviceBufferDeviceAddressFeaturesEXT)
VK_ENCAPSULATION_TYPE_ALIAS(BufferDeviceAddressInfoEXT, BufferDeviceAddressInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ToolPurposeFlagBitsEXT, ToolPurposeFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(ToolPurposeFlagsEXT, ToolPurposeFlags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceToolPropertiesEXT, PhysicalDeviceToolProperties)
VK_ENCAPSULATION_TYPE_ALIAS(ImageStencilUsageCreateInfoEXT, ImageStencilUsageCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(ComponentTypeNV, ComponentTypeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(ScopeNV, ScopeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineCoverageReductionStateCreateFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(HeadlessSurfaceCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(LineRasterizationModeEXT, LineRasterizationMode)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceLineRasterizationFeaturesEXT, PhysicalDeviceLineRasterizationFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceLineRasterizationPropertiesEXT, PhysicalDeviceLineRasterizationProperties)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineRasterizationLineStateCreateInfoEXT, PipelineRasterizationLineStateCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceHostQueryResetFeaturesEXT, PhysicalDeviceHostQueryResetFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceIndexTypeUint8FeaturesEXT, PhysicalDeviceIndexTypeUint8Features)
VK_ENCAPSULATION_TYPE_ALIAS(HostImageCopyFlagBitsEXT, HostImageCopyFlagBits)
VK_ENCAPSULATION_TYPE_ALIAS(HostImageCopyFlagsEXT, HostImageCopyFlags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceHostImageCopyFeaturesEXT, PhysicalDeviceHostImageCopyFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceHostImageCopyPropertiesEXT, PhysicalDeviceHostImageCopyProperties)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryToImageCopyEXT, MemoryToImageCopy)
VK_ENCAPSULATION_TYPE_ALIAS(ImageToMemoryCopyEXT, ImageToMemoryCopy)
VK_ENCAPSULATION_TYPE_ALIAS(CopyMemoryToImageInfoEXT, CopyMemoryToImageInfo)
VK_ENCAPSULATION_TYPE_ALIAS(CopyImageToMemoryInfoEXT, CopyImageToMemoryInfo)
VK_ENCAPSULATION_TYPE_ALIAS(CopyImageToImageInfoEXT, CopyImageToImageInfo)
VK_ENCAPSULATION_TYPE_ALIAS(HostImageLayoutTransitionInfoEXT, HostImageLayoutTransitionInfo)
VK_ENCAPSULATION_TYPE_ALIAS(SubresourceHostMemcpySizeEXT, SubresourceHostMemcpySize)
VK_ENCAPSULATION_TYPE_ALIAS(HostImageCopyDevicePerformanceQueryEXT, HostImageCopyDevicePerformanceQuery)
VK_ENCAPSULATION_TYPE_ALIAS(SubresourceLayout2EXT, SubresourceLayout2)
VK_ENCAPSULATION_TYPE_ALIAS(ImageSubresource2EXT, ImageSubresource2)
VK_ENCAPSULATION_TYPE_ALIAS(PresentScalingFlagBitsEXT, PresentScalingFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PresentScalingFlagsEXT, PresentScalingFlagsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PresentGravityFlagBitsEXT, PresentGravityFlagBitsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PresentGravityFlagsEXT, PresentGravityFlagsKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SurfacePresentModeEXT, SurfacePresentModeKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SurfacePresentScalingCapabilitiesEXT, SurfacePresentScalingCapabilitiesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SurfacePresentModeCompatibilityEXT, SurfacePresentModeCompatibilityKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSwapchainMaintenance1FeaturesEXT, PhysicalDeviceSwapchainMaintenance1FeaturesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SwapchainPresentFenceInfoEXT, SwapchainPresentFenceInfoKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SwapchainPresentModesCreateInfoEXT, SwapchainPresentModesCreateInfoKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SwapchainPresentModeInfoEXT, SwapchainPresentModeInfoKHR)
VK_ENCAPSULATION_TYPE_ALIAS(SwapchainPresentScalingCreateInfoEXT, SwapchainPresentScalingCreateInfoKHR)
VK_ENCAPSULATION_TYPE_ALIAS(ReleaseSwapchainImagesInfoEXT, ReleaseSwapchainImagesInfoKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT, PhysicalDeviceShaderDemoteToHelperInvocationFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectStateFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsLayoutUsageFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceTexelBufferAlignmentPropertiesEXT, PhysicalDeviceTexelBufferAlignmentProperties)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceMemoryReportFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceRobustness2FeaturesEXT, PhysicalDeviceRobustness2FeaturesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceRobustness2PropertiesEXT, PhysicalDeviceRobustness2PropertiesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PrivateDataSlotEXT, PrivateDataSlot)
VK_ENCAPSULATION_TYPE_ALIAS(PrivateDataSlotCreateFlagsEXT, PrivateDataSlotCreateFlags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePrivateDataFeaturesEXT, PhysicalDevicePrivateDataFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(DevicePrivateDataCreateInfoEXT, DevicePrivateDataCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PrivateDataSlotCreateInfoEXT, PrivateDataSlotCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePipelineCreationCacheControlFeaturesEXT, PhysicalDevicePipelineCreationCacheControlFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceDiagnosticsConfigFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(TileShadingRenderPassFlagsQCOM, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(GraphicsPipelineLibraryFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureMotionInfoFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureMotionInstanceFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceImageRobustnessFeaturesEXT, PhysicalDeviceImageRobustnessFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(ImageCompressionFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ImageCompressionFixedRateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM, PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceMutableDescriptorTypeFeaturesVALVE, PhysicalDeviceMutableDescriptorTypeFeaturesEXT)
VK_ENCAPSULATION_TYPE_ALIAS(MutableDescriptorTypeListVALVE, MutableDescriptorTypeListEXT)
VK_ENCAPSULATION_TYPE_ALIAS(MutableDescriptorTypeCreateInfoVALVE, MutableDescriptorTypeCreateInfoEXT)
VK_ENCAPSULATION_TYPE_ALIAS(DeviceAddressBindingFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePresentModeFifoLatestReadyFeaturesEXT, PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PipelineInfoEXT, PipelineInfoKHR)
VK_ENCAPSULATION_TYPE_ALIAS(FrameBoundaryFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceGlobalPriorityQueryFeaturesEXT, PhysicalDeviceGlobalPriorityQueryFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(QueueFamilyGlobalPriorityPropertiesEXT, QueueFamilyGlobalPriorityProperties)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRgbModelConversionFlagsVALVE, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRgbRangeCompressionFlagsVALVE, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(VideoEncodeRgbChromaOffsetFlagsVALVE, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(BuildMicromapFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(MicromapCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSchedulingControlsFlagsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceSchedulingControlsFlagBitsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceDepthClampZeroOneFeaturesEXT, PhysicalDeviceDepthClampZeroOneFeaturesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM, PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM, PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT)
VK_ENCAPSULATION_TYPE_ALIAS(SubpassFragmentDensityMapOffsetEndInfoQCOM, RenderPassFragmentDensityMapOffsetEndInfoEXT)
VK_ENCAPSULATION_TYPE_ALIAS(CopyMemoryIndirectCommandNV, CopyMemoryIndirectCommandKHR)
VK_ENCAPSULATION_TYPE_ALIAS(CopyMemoryToImageIndirectCommandNV, CopyMemoryToImageIndirectCommandKHR)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDeviceCopyMemoryIndirectPropertiesNV, PhysicalDeviceCopyMemoryIndirectPropertiesKHR)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryDecompressionMethodFlagBitsNV, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(MemoryDecompressionMethodFlagsNV, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(DirectDriverLoadingFlagsLUNARG, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(TensorCreateFlagsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(TensorCreateFlagBitsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(TensorViewCreateFlagsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(TensorViewCreateFlagBitsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(TensorUsageFlagsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(TensorUsageFlagBitsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(PhysicalDevicePipelineProtectedAccessFeaturesEXT, PhysicalDevicePipelineProtectedAccessFeatures)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderCreateFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ShaderRequiredSubgroupSizeCreateInfoEXT, PipelineShaderStageRequiredSubgroupSizeCreateInfo)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelineSessionCreateFlagsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelineSessionCreateFlagBitsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelineDispatchFlagsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(DataGraphPipelineDispatchFlagBitsARM, Flags64)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureAddressResolutionFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureClusterFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureGeometryFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(ClusterAccelerationStructureIndexFormatFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(PartitionedAccelerationStructureInstanceFlagsNV, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsInputModeFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(IndirectCommandsLayoutUsageFlagsEXT, Flags)
VK_ENCAPSULATION_TYPE_ALIAS(AccelerationStructureCreateFlagsKHR, Flags)

VK_ENCAPSULATION_NAMESPACE_END

VK_ENCAPSULATION_RAII_NAMESPACE_BEGIN

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Buffer) {
	ObjectClassHeader(Buffer);
	Object(const VkBufferCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyBuffer(*this, Allocator());
	}
	RESULT Create(const VkBufferCreateInfo& createInfo) {
		VkResult result = CreateBuffer(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Buffer);

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Image) {
	ObjectClassHeader(Image);
	Object(const VkImageCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyImage(*this, Allocator());
	}
	RESULT Create(const VkImageCreateInfo& createInfo) {
		VkResult result = CreateImage(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Image)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_DEVICE(Instance) {
	ObjectClassHeader(Instance);
	Object(const VkInstanceCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyInstance(handle, Allocator());
	}
	RESULT Create(const VkInstanceCreateInfo& createInfo) {
		VkResult result = CreateInstance(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Instance)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(PhysicalDevice) {
	ObjectClassHeader(PhysicalDevice);
};
//VK_ENCAPSULATION_RAII_OBJECT_END(PhysicalDevice)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_DEVICE(Device) {
	ObjectClassHeader(Device);
	Object(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo& createInfo) {
		Create(physicalDevice, createInfo);
	}
	~Object() {
		if (handle)
			DestroyDevice(handle, Allocator());
	}
	void BindContext() const {
		struct _ : DeviceContext {
			using DeviceContext::PhysicalDevice;
			using DeviceContext::Device;
			using DeviceContext::FunctionTable;
		};
		_::PhysicalDevice(physicalDevice);
		_::Device(handle);
	#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
		_::FunctionTable(functionTable);
	#endif
	}
	RESULT Create(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo& createInfo) {
	#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
		this->physicalDevice = physicalDevice;
		VkResult result = CreateDevice(physicalDevice, createInfo, *this, functionTable);
	#else
		VkResult result = CreateDevice(physicalDevice, createInfo, *this);
	#endif
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
protected:
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
#ifdef VK_ENCAPSULATION_MAY_CREATE_MULTIPLE_DEVICE
	VolkDeviceTable functionTable = {};
#endif
};
VK_ENCAPSULATION_RAII_OBJECT_END(Device)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(Queue) {
	ObjectClassHeader(Queue);
	Object(uint32_t queueFamilyIndex, uint32_t queueIndex) {
		Get(queueFamilyIndex, queueIndex);
	}
	Object(const VkDeviceQueueInfo2& queueInfo) {
		Get2(queueInfo);
	}
	void Get(uint32_t queueFamilyIndex, uint32_t queueIndex) {
		GetDeviceQueue(queueFamilyIndex, queueIndex, handle);
	}
	void Get2(const VkDeviceQueueInfo2& queueInfo) {
		GetDeviceQueue2(queueInfo, handle);
	}
};
//VK_ENCAPSULATION_RAII_OBJECT_END(Queue)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Semaphore) {
	ObjectClassHeader(Semaphore);
	Object(const VkSemaphoreCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroySemaphore(*this, Allocator());
	}
	RESULT Create(const VkSemaphoreCreateInfo& createInfo) {
		VkResult result = CreateSemaphore(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Semaphore)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(CommandBuffer) {
	ObjectClassHeader(CommandBuffer);
};
//VK_ENCAPSULATION_RAII_OBJECT_END(CommandBuffer)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Fence) {
	ObjectClassHeader(Fence);
	Object(const VkFenceCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(const VkDeviceEventInfoEXT& deviceEventInfo) {
		RegisterDeviceEvent(deviceEventInfo);
	}
	Object(VkDisplayKHR display, const VkDisplayEventInfoEXT& deviceEventInfo) {
		RegisterDisplayEvent(display, deviceEventInfo);
	}
	~Object() {
		if (handle)
			DestroyFence(*this, Allocator());
	}
	RESULT Create(const VkFenceCreateInfo& createInfo) {
		VkResult result = CreateFence(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT RegisterDeviceEvent(const VkDeviceEventInfoEXT& deviceEventInfo) {
		VkResult result = VK_ENCAPSULATION_NAMESPACE::RegisterDeviceEventEXT(deviceEventInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT RegisterDisplayEvent(VkDisplayKHR display, const VkDisplayEventInfoEXT& deviceEventInfo) {
		VkResult result = VK_ENCAPSULATION_NAMESPACE::RegisterDisplayEventEXT(display, deviceEventInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Fence)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(DeviceMemory) {
	ObjectClassHeader(DeviceMemory);
	Object(const VkMemoryAllocateInfo& allocateInfo) {
		Allocate(allocateInfo);
	}
	~Object() {
		if (handle)
			FreeMemory(*this, Allocator());
	}
	RESULT Allocate(const VkMemoryAllocateInfo& allocateInfo) {
		VkResult result = AllocateMemory(allocateInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DeviceMemory)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Event) {
	ObjectClassHeader(Event);
	Object(const VkEventCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyEvent(*this, Allocator());
	}
	RESULT Create(const VkEventCreateInfo& createInfo) {
		VkResult result = CreateEvent(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Event)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(QueryPool) {
	ObjectClassHeader(QueryPool);
	Object(const VkQueryPoolCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyQueryPool(*this, Allocator());
	}
	RESULT Create(const VkQueryPoolCreateInfo& createInfo) {
		VkResult result = CreateQueryPool(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(QueryPool)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(BufferView) {
	ObjectClassHeader(BufferView);
	Object(const VkBufferViewCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyBufferView(*this, Allocator());
	}
	RESULT Create(const VkBufferViewCreateInfo& createInfo) {
		VkResult result = CreateBufferView(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(BufferView)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(ImageView) {
	ObjectClassHeader(ImageView);
	Object(const VkImageViewCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyImageView(*this, Allocator());
	}
	RESULT Create(const VkImageViewCreateInfo& createInfo) {
		VkResult result = CreateImageView(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(ImageView)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(ShaderModule) {
	ObjectClassHeader(ShaderModule);
	Object(const VkShaderModuleCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyShaderModule(*this, Allocator());
	}
	RESULT Create(const VkShaderModuleCreateInfo& createInfo) {
		VkResult result = CreateShaderModule(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(ShaderModule)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(PipelineCache) {
	ObjectClassHeader(PipelineCache);
	Object(const VkPipelineCacheCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyPipelineCache(*this, Allocator());
	}
	RESULT Create(const VkPipelineCacheCreateInfo& createInfo) {
		VkResult result = CreatePipelineCache(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(PipelineCache)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(PipelineLayout) {
	ObjectClassHeader(PipelineLayout);
	Object(const VkPipelineLayoutCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyPipelineLayout(*this, Allocator());
	}
	RESULT Create(const VkPipelineLayoutCreateInfo& createInfo) {
		VkResult result = CreatePipelineLayout(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(PipelineLayout)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Pipeline) {
	ObjectClassHeader(Pipeline);
	Object(VkPipelineCache pipelineCache, const VkGraphicsPipelineCreateInfo& createInfo) {
		CreateGraphics(pipelineCache, createInfo);
	}
	Object(VkPipelineCache pipelineCache, const VkComputePipelineCreateInfo& createInfo) {
		CreateCompute(pipelineCache, createInfo);
	}
	Object(VkPipelineCache pipelineCache, const VkRayTracingPipelineCreateInfoNV& createInfo) {
		CreateRayTracing(pipelineCache, createInfo);
	}
	Object(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, const VkDataGraphPipelineCreateInfoARM& createInfo) {
		CreateDataGraph(deferredOperation, pipelineCache, createInfo);
	}
	Object(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, const VkRayTracingPipelineCreateInfoKHR& createInfo) {
		CreateRayTracing(deferredOperation, pipelineCache, createInfo);
	}
	~Object() {
		if (handle)
			DestroyPipeline(*this, Allocator());
	}
	RESULT CreateGraphics(VkPipelineCache pipelineCache, const VkGraphicsPipelineCreateInfo& createInfo) {
		VkResult result = CreateGraphicsPipelines(pipelineCache, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT CreateCompute(VkPipelineCache pipelineCache, const VkComputePipelineCreateInfo& createInfo) {
		VkResult result = CreateComputePipelines(pipelineCache, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT CreateRayTracing(VkPipelineCache pipelineCache, const VkRayTracingPipelineCreateInfoNV& createInfo) {
		VkResult result = CreateRayTracingPipelinesNV(pipelineCache, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT CreateDataGraph(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, const VkDataGraphPipelineCreateInfoARM& createInfo) {
		VkResult result = CreateDataGraphPipelinesARM(deferredOperation, pipelineCache, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT CreateRayTracing(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, const VkRayTracingPipelineCreateInfoKHR& createInfo) {
		VkResult result = CreateRayTracingPipelinesKHR(deferredOperation, pipelineCache, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	static RESULT CreateGraphics(VkPipelineCache pipelineCache, ArrayRef<const VkGraphicsPipelineCreateInfo> createInfos, ArrayRef<Object> pipelines) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreateGraphicsPipelines(pipelineCache, createInfos, *pipelines);
		std::vector<Handle_T> _(createInfos.size());
		VkResult result = CreateGraphicsPipelines(pipelineCache, createInfos, _);
		if (result == VK_SUCCESS)
			for (auto p = pipelines.data(); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
	static RESULT CreateCompute(VkPipelineCache pipelineCache, ArrayRef<const VkComputePipelineCreateInfo> createInfos, ArrayRef<Object> pipelines) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreateComputePipelines(pipelineCache, createInfos, *pipelines);
		std::vector<Handle_T> _(createInfos.size());
		VkResult result = CreateComputePipelines(pipelineCache, createInfos, _);
		if (result == VK_SUCCESS)
			for (auto p = pipelines.data(); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
	static RESULT CreateRayTracing(VkPipelineCache pipelineCache, ArrayRef<const VkRayTracingPipelineCreateInfoNV> createInfos, ArrayRef<Object> pipelines) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreateRayTracingPipelinesNV(pipelineCache, createInfos, *pipelines);
		std::vector<Handle_T> _(createInfos.size());
		VkResult result = CreateRayTracingPipelinesNV(pipelineCache, createInfos, _);
		if (result == VK_SUCCESS)
			for (auto p = pipelines.data(); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
	static RESULT CreateDataGraph(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, ArrayRef<const VkDataGraphPipelineCreateInfoARM> createInfos, ArrayRef<Object> pipelines) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreateDataGraphPipelinesARM(deferredOperation, pipelineCache, createInfos, *pipelines);
		std::vector<Handle_T> _(createInfos.size());
		VkResult result = CreateDataGraphPipelinesARM(deferredOperation, pipelineCache, createInfos, _);
		if (result == VK_SUCCESS)
			for (auto p = pipelines.data(); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
	static RESULT CreateRayTracing(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, ArrayRef<const VkRayTracingPipelineCreateInfoKHR> createInfos, ArrayRef<Object> pipelines) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreateRayTracingPipelinesKHR(deferredOperation, pipelineCache, createInfos, *pipelines);
		std::vector<Handle_T> _(createInfos.size());
		VkResult result = CreateRayTracingPipelinesKHR(deferredOperation, pipelineCache, createInfos, _);
		if (result == VK_SUCCESS)
			for (auto p = pipelines.data(); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Pipeline)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(RenderPass) {
	ObjectClassHeader(RenderPass);
	Object(const VkRenderPassCreateInfo& createInfo) {
		Create(createInfo);
	}
	Object(const VkRenderPassCreateInfo2& createInfo) {
		Create2(createInfo);
	}
	~Object() {
		if (handle)
			DestroyRenderPass(*this, Allocator());
	}
	RESULT Create(const VkRenderPassCreateInfo& createInfo) {
		VkResult result = CreateRenderPass(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT Create2(const VkRenderPassCreateInfo2& createInfo) {
		VkResult result = M_ConditionalDispatch(CreateRenderPass2, KHR, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(RenderPass)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(DescriptorSetLayout) {
	ObjectClassHeader(DescriptorSetLayout);
	Object(const VkDescriptorSetLayoutCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyDescriptorSetLayout(*this, Allocator());
	}
	RESULT Create(const VkDescriptorSetLayoutCreateInfo& createInfo) {
		VkResult result = CreateDescriptorSetLayout(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DescriptorSetLayout)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Sampler) {
	ObjectClassHeader(Sampler);
	Object(const VkSamplerCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroySampler(*this, Allocator());
	}
	RESULT Create(const VkSamplerCreateInfo& createInfo) {
		VkResult result = CreateSampler(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Sampler)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(DescriptorSet) {
	ObjectClassHeader(DescriptorSet);
};
//VK_ENCAPSULATION_RAII_OBJECT_END(DescriptorSet)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(DescriptorPool) {
	ObjectClassHeader(DescriptorPool);
	Object(const VkDescriptorPoolCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyDescriptorPool(*this, Allocator());
	}
	RESULT Create(const VkDescriptorPoolCreateInfo& createInfo) {
		VkResult result = CreateDescriptorPool(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DescriptorPool)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(Framebuffer) {
	ObjectClassHeader(Framebuffer);
	Object(const VkFramebufferCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyFramebuffer(*this, Allocator());
	}
	RESULT Create(const VkFramebufferCreateInfo& createInfo) {
		VkResult result = CreateFramebuffer(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(Framebuffer)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(CommandPool) {
	ObjectClassHeader(CommandPool);
	Object(const VkCommandPoolCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyCommandPool(*this, Allocator());
	}
	RESULT Create(const VkCommandPoolCreateInfo& createInfo) {
		VkResult result = CreateCommandPool(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(CommandPool)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(SamplerYcbcrConversion) {
	ObjectClassHeader(SamplerYcbcrConversion);
	Object(const VkSamplerYcbcrConversionCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			M_ConditionalDispatch(DestroySamplerYcbcrConversion, KHR, *this, Allocator());
	}
	RESULT Create(const VkSamplerYcbcrConversionCreateInfo& createInfo) {
		VkResult result = M_ConditionalDispatch(CreateSamplerYcbcrConversion, KHR, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(SamplerYcbcrConversion)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(DescriptorUpdateTemplate) {
	ObjectClassHeader(DescriptorUpdateTemplate);
	Object(const VkDescriptorUpdateTemplateCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			M_ConditionalDispatch(DestroyDescriptorUpdateTemplate, KHR, *this, Allocator());
	}
	RESULT Create(const VkDescriptorUpdateTemplateCreateInfo& createInfo) {
		VkResult result = M_ConditionalDispatch(CreateDescriptorUpdateTemplate, KHR, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DescriptorUpdateTemplate)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(PrivateDataSlot) {
	ObjectClassHeader(PrivateDataSlot);
	Object(const VkPrivateDataSlotCreateInfo& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			M_ConditionalDispatch(DestroyPrivateDataSlot, EXT, *this, Allocator());
	}
	RESULT Create(const VkPrivateDataSlotCreateInfo& createInfo) {
		VkResult result = M_ConditionalDispatch(CreatePrivateDataSlot, EXT, createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(PrivateDataSlot)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_DEVICE(SurfaceKHR) {
	ObjectClassHeader(SurfaceKHR);
	Object(const VkHeadlessSurfaceCreateInfoEXT& createInfo) {
		CreateHeadless(createInfo);
	}
	Object(const VkDisplaySurfaceCreateInfoKHR& createInfo) {
		CreateDisplayPlane(createInfo);
	}
	~Object() {
		if (handle)
			DestroySurfaceKHR(*this, Allocator());
	}
	RESULT CreateHeadless(const VkHeadlessSurfaceCreateInfoEXT& createInfo) {
		VkResult result = CreateHeadlessSurfaceEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	RESULT CreateDisplayPlane(const VkDisplaySurfaceCreateInfoKHR& createInfo) {
		VkResult result = CreateDisplayPlaneSurfaceKHR(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(SurfaceKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(SwapchainKHR) {
	ObjectClassHeader(SwapchainKHR);
	Object(const VkSwapchainCreateInfoKHR& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroySwapchainKHR(*this, Allocator());
	}
	RESULT Create(const VkSwapchainCreateInfoKHR& createInfo) {
		VkResult result = CreateSwapchainKHR(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	static RESULT CreateShared(ArrayRef<const VkSwapchainCreateInfoKHR> createInfos, ArrayRef<Object> swapchains) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreateSharedSwapchainsKHR(createInfos, *swapchains);
		std::vector<Handle_T> _(createInfos.size());
		VkResult result = CreateSharedSwapchainsKHR(createInfos, _);
		if (result == VK_SUCCESS)
			for (auto p = swapchains.data(); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(SwapchainKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(DisplayKHR) {
	ObjectClassHeader(DisplayKHR);
};
//VK_ENCAPSULATION_RAII_OBJECT_END(DisplayKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(DisplayModeKHR) {
	ObjectClassHeader(DisplayModeKHR);
};
//VK_ENCAPSULATION_RAII_OBJECT_END(DisplayModeKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(VideoSessionKHR) {
	ObjectClassHeader(VideoSessionKHR);
	Object(const VkVideoSessionCreateInfoKHR& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyVideoSessionKHR(*this, Allocator());
	}
	RESULT Create(const VkVideoSessionCreateInfoKHR& createInfo) {
		VkResult result = CreateVideoSessionKHR(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(VideoSessionKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(VideoSessionParametersKHR) {
	ObjectClassHeader(VideoSessionParametersKHR);
	Object(const VkVideoSessionParametersCreateInfoKHR& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyVideoSessionParametersKHR(*this, Allocator());
	}
	RESULT Create(const VkVideoSessionParametersCreateInfoKHR& createInfo) {
		VkResult result = CreateVideoSessionParametersKHR(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(VideoSessionParametersKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(DeferredOperationKHR) {
	ObjectClassHeader(DeferredOperationKHR);
	Object(EmptyList) {
		Create();
	}
	~Object() {
		if (handle)
			DestroyDeferredOperationKHR(*this, Allocator());
	}
	RESULT Create() {
		VkResult result = CreateDeferredOperationKHR(*this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DeferredOperationKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(PipelineBinaryKHR) {
	ObjectClassHeader(PipelineBinaryKHR);
	~Object() {
		if (handle)
			DestroyPipelineBinaryKHR(*this, Allocator());
	}
	static RESULT Create(const VkPipelineBinaryCreateInfoKHR& createInfo, IsDynamicArray<Object> auto& pipelineBinaries) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreatePipelineBinariesKHR(createInfo, pipelineBinaries);
		PipelineBinaryHandlesInfoKHR binaryHandlesInfo;
		if (createInfo.pKeysAndDataInfo)
			binaryHandlesInfo.pipelineBinaryCount = createInfo.pKeysAndDataInfo->binaryCount;
		else
			if (VkResult result = CreatePipelineBinariesKHR(createInfo, binaryHandlesInfo);
				result != VK_SUCCESS)
				return result;
		std::vector<Handle_T> _(binaryHandlesInfo.pipelineBinaryCount);
		binaryHandlesInfo.pPipelineBinaries = std::ranges::data(_);
		VkResult result = CreatePipelineBinariesKHR(createInfo, binaryHandlesInfo);
		if (result == VK_SUCCESS)
			for (auto p = std::ranges::data(pipelineBinaries); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(PipelineBinaryKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_DEVICE(DebugReportCallbackEXT) {
	ObjectClassHeader(DebugReportCallbackEXT);
	Object(const VkDebugReportCallbackCreateInfoEXT& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyDebugReportCallbackEXT(*this, Allocator());
	}
	RESULT Create(const VkDebugReportCallbackCreateInfoEXT& createInfo) {
		VkResult result = CreateDebugReportCallbackEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DebugReportCallbackEXT)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(CuModuleNVX) {
	ObjectClassHeader(CuModuleNVX);
	Object(const VkCuModuleCreateInfoNVX& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyCuModuleNVX(*this, Allocator());
	}
	RESULT Create(const VkCuModuleCreateInfoNVX& createInfo) {
		VkResult result = CreateCuModuleNVX(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(CuModuleNVX)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(CuFunctionNVX) {
	ObjectClassHeader(CuFunctionNVX);
	Object(const VkCuFunctionCreateInfoNVX& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyCuFunctionNVX(*this, Allocator());
	}
	RESULT Create(const VkCuFunctionCreateInfoNVX& createInfo) {
		VkResult result = CreateCuFunctionNVX(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(CuFunctionNVX)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_DEVICE(DebugUtilsMessengerEXT) {
	ObjectClassHeader(DebugUtilsMessengerEXT);
	Object(const VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyDebugUtilsMessengerEXT(*this, Allocator());
	}
	RESULT Create(const VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
		VkResult result = CreateDebugUtilsMessengerEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DebugUtilsMessengerEXT)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(ValidationCacheEXT) {
	ObjectClassHeader(ValidationCacheEXT);
	Object(const VkValidationCacheCreateInfoEXT& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyValidationCacheEXT(*this, Allocator());
	}
	RESULT Create(const VkValidationCacheCreateInfoEXT& createInfo) {
		VkResult result = CreateValidationCacheEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(ValidationCacheEXT)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(AccelerationStructureNV) {
	ObjectClassHeader(AccelerationStructureNV);
	Object(const VkAccelerationStructureCreateInfoNV& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyAccelerationStructureNV(*this, Allocator());
	}
	RESULT Create(const VkAccelerationStructureCreateInfoNV& createInfo) {
		VkResult result = CreateAccelerationStructureNV(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(AccelerationStructureNV)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN_NO_ALLOCATOR(PerformanceConfigurationINTEL) {
	ObjectClassHeader(PerformanceConfigurationINTEL);
	Object(const VkPerformanceConfigurationAcquireInfoINTEL& acquireInfo) {
		Acquire(acquireInfo);
	}
	~Object() {
		if (handle)
			ReleasePerformanceConfigurationINTEL(*this);
	}
	RESULT Acquire(const VkPerformanceConfigurationAcquireInfoINTEL& acquireInfo) {
		return AcquirePerformanceConfigurationINTEL(acquireInfo, *this);
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(PerformanceConfigurationINTEL)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(IndirectCommandsLayoutNV) {
	ObjectClassHeader(IndirectCommandsLayoutNV);
	Object(const VkIndirectCommandsLayoutCreateInfoNV& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyIndirectCommandsLayoutNV(*this, Allocator());
	}
	RESULT Create(const VkIndirectCommandsLayoutCreateInfoNV& createInfo) {
		VkResult result = CreateIndirectCommandsLayoutNV(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(IndirectCommandsLayoutNV)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(AccelerationStructureKHR) {
	ObjectClassHeader(AccelerationStructureKHR);
	Object(const VkAccelerationStructureCreateInfoKHR& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyAccelerationStructureKHR(*this, Allocator());
	}
	RESULT Create(const VkAccelerationStructureCreateInfoKHR& createInfo) {
		VkResult result = CreateAccelerationStructureKHR(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(AccelerationStructureKHR)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(MicromapEXT) {
	ObjectClassHeader(MicromapEXT);
	Object(const VkMicromapCreateInfoEXT& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyMicromapEXT(*this, Allocator());
	}
	RESULT Create(const VkMicromapCreateInfoEXT& createInfo) {
		VkResult result = CreateMicromapEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(MicromapEXT)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(TensorARM) {
	ObjectClassHeader(TensorARM);
	Object(const VkTensorCreateInfoARM& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyTensorARM(*this, Allocator());
	}
	RESULT Create(const VkTensorCreateInfoARM& createInfo) {
		VkResult result = CreateTensorARM(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(TensorARM)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(TensorViewARM) {
	ObjectClassHeader(TensorViewARM);
	Object(const VkTensorViewCreateInfoARM& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyTensorViewARM(*this, Allocator());
	}
	RESULT Create(const VkTensorViewCreateInfoARM& createInfo) {
		VkResult result = CreateTensorViewARM(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(TensorViewARM)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(OpticalFlowSessionNV) {
	ObjectClassHeader(OpticalFlowSessionNV);
	Object(const VkOpticalFlowSessionCreateInfoNV& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyOpticalFlowSessionNV(*this, Allocator());
	}
	RESULT Create(const VkOpticalFlowSessionCreateInfoNV& createInfo) {
		VkResult result = CreateOpticalFlowSessionNV(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(OpticalFlowSessionNV)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(ShaderEXT) {
	ObjectClassHeader(ShaderEXT);
	Object(const VkShaderCreateInfoEXT& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyShaderEXT(*this, Allocator());
	}
	RESULT Create(const VkShaderCreateInfoEXT& createInfo) {
		VkResult result = CreateShadersEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
	static RESULT Create(ArrayRef<const VkShaderCreateInfoEXT> createInfos, ArrayRef<Object> shaders) {
		if (sizeof(Object) == sizeof(Handle_T))
			return CreateShadersEXT(createInfos, *shaders);
		std::vector<Handle_T> _(createInfos.size());
		VkResult result = CreateShadersEXT(createInfos, _);
		if (result == VK_SUCCESS)
			for (auto p = shaders.data(); auto& i : _)
				p->Allocator(), p->handle = i, p++;
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(ShaderEXT)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(DataGraphPipelineSessionARM) {
	ObjectClassHeader(DataGraphPipelineSessionARM);
	Object(const VkDataGraphPipelineSessionCreateInfoARM& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyDataGraphPipelineSessionARM(*this, Allocator());
	}
	RESULT Create(const VkDataGraphPipelineSessionCreateInfoARM& createInfo) {
		VkResult result = CreateDataGraphPipelineSessionARM(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(DataGraphPipelineSessionARM)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(ExternalComputeQueueNV) {
	ObjectClassHeader(ExternalComputeQueueNV);
	Object(const VkExternalComputeQueueCreateInfoNV& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyExternalComputeQueueNV(*this, Allocator());
	}
	RESULT Create(const VkExternalComputeQueueCreateInfoNV& createInfo) {
		VkResult result = CreateExternalComputeQueueNV(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(ExternalComputeQueueNV)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(IndirectExecutionSetEXT) {
	ObjectClassHeader(IndirectExecutionSetEXT);
	Object(const VkIndirectExecutionSetCreateInfoEXT& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyIndirectExecutionSetEXT(*this, Allocator());
	}
	RESULT Create(const VkIndirectExecutionSetCreateInfoEXT& createInfo) {
		VkResult result = CreateIndirectExecutionSetEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(IndirectExecutionSetEXT)

VK_ENCAPSULATION_RAII_OBJECT_BEGIN(IndirectCommandsLayoutEXT) {
	ObjectClassHeader(IndirectCommandsLayoutEXT);
	Object(const VkIndirectCommandsLayoutCreateInfoEXT& createInfo) {
		Create(createInfo);
	}
	~Object() {
		if (handle)
			DestroyIndirectCommandsLayoutEXT(*this, Allocator());
	}
	RESULT Create(const VkIndirectCommandsLayoutCreateInfoEXT& createInfo) {
		VkResult result = CreateIndirectCommandsLayoutEXT(createInfo, *this);
		if (result == VK_SUCCESS)
			Allocator();
		return result;
	}
};
VK_ENCAPSULATION_RAII_OBJECT_END(IndirectCommandsLayoutEXT)

VK_ENCAPSULATION_NAMESPACE_END

#undef TemplateTypeName
#undef DefineFunctionRaiiClass
#undef DefineFunctionRaiiClass_L
#undef DefineFunctionRaiiClass_R
#undef DefineFunctionRaiiClass_Result
#undef DefineFunctionRaiiClass_ResultL
#undef DefineFunctionRaiiClass_ResultR
#undef DefineFunctionRaiiClass_TwoStruct
#undef DefineRaiiFunction
#undef DefineRaiiFunction_L
#undef DefineRaiiFunction_R
#undef DefineRaiiFunction_Result
#undef DefineRaiiFunction_ResultL
#undef DefineRaiiFunction_ResultR
#undef DefineRaiiFunction_TwoStruct
#undef DefineSetter_Copy
#undef DefineSetter_CopyOptional
#undef DefineSetter_ArrayCopy
#undef DefineSetter_Ref
#undef DefineSetter_PointerAndRef
#undef DefineSetter_ArrayRef
#undef DefineSetter_ArrayRefIgnoreC
#undef DefineSetter_ArrayRefSpecialP
#undef DefineSetterForUnionWrapper_Copy
#undef DefineSetterForUnionWrapper_ArrayCopy
#undef UsingRefType
#undef StructureClassHeader
#undef StructureClassHeader_NoSType
#undef StructureClassHeader_UnionWrapper
#undef ObjectClassHeader