#include "filter.hpp"

namespace mbgl {
namespace android {
namespace style {

jni::Object<Filter> Filter::fromFilter(jni::JNIEnv& env, mbgl::style::Filter) {
    static auto constructor = Filter::javaClass.template GetConstructor<>(env);
    return Filter::javaClass.New(env, constructor);
}

void Filter::registerNative(jni::JNIEnv& env) {
    // Lookup the class
    Filter::javaClass = *jni::Class<Filter>::Find(env).NewGlobalRef(env).release();
}

jni::Class<Filter> Filter::javaClass;


} // namespace style
} // namespace android
} // namespace mbgl