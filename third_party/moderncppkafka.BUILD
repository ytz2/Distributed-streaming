cc_library(
    name = "modern_cpp_kafka",
    hdrs = glob(["include/kafka/*.h", "include/kafka/addons/*.h"]),
    includes = ["include"],
    copts = [
            "-std=c++17",
    ],
    deps = [
        "@librdkafka//:librdkafka",
    ],
    visibility = ["//visibility:public"],
)
