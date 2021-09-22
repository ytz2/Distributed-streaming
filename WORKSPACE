load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
http_archive(
    name = "rules_foreign_cc",
    strip_prefix = "rules_foreign_cc-7da37f815b3b58e05308fbf4940c327c3cb0669b",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/7da37f815b3b58e05308fbf4940c327c3cb0669b.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

http_archive(
    name = "com_github_jsoncpp",
    url = "https://github.com/open-source-parsers/jsoncpp/archive/1.8.4.zip",
    build_file = "//third_party:jsoncpp.BUILD",
    strip_prefix = "jsoncpp-1.8.4",
)

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "1e3a69bf2d5cd10c34b74f066054cd335d033d71",
    remote = "https://github.com/nelhage/rules_boost",
    shallow_since = "1591047380 -0700",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

http_archive(
    name = "com_github_gflags_gflags",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
    strip_prefix = "gflags-2.2.2",
    urls = ["https://github.com/gflags/gflags/archive/v2.2.2.tar.gz"],
)

bind(
    name = "gflags",
    actual = "@com_github_gflags_gflags//:gflags",
)

http_archive(
    name = "com_github_google_glog",
    sha256 = "21bc744fb7f2fa701ee8db339ded7dce4f975d0d55837a97be7d46e8382dea5a",
    strip_prefix = "glog-0.5.0",
    urls = ["https://github.com/google/glog/archive/v0.5.0.zip"],
)

bind(
    name = "glog",
    actual = "@com_github_google_glog//:glog",
)

http_archive(
    name = "com_github_jbeder_yaml_cpp",
    sha256 = "1df36d25ff796a79bee69ea42ee2b86be09ac9f3582efaf5a26037f09033297b",
    strip_prefix = "yaml-cpp-yaml-cpp-0.6.4",
    urls = [
        "https://github.com/sammi/yaml-cpp/archive/yaml-cpp-0.6.4.tar.gz",
    ],
)

git_repository(
    name = "com_google_googletest",
    remote = "https://github.com/google/googletest",
    branch = "v1.10.x",
)

bind(
    name = "gtest",
    actual = "@com_google_googletest//:gtest",
)

new_git_repository(
    name = "com_github_morganstanley_moderncppkafka",
    remote = "https://github.com/morganstanley/modern-cpp-kafka.git",
    commit = "82bdae9a29fda7bac94a40c80cc2e6ff3bda51bd",
    build_file = "//third_party:moderncppkafka.BUILD",
    shallow_since = "1631534515 +0800",
)

http_archive(
    name = "librdkafka",
    build_file_content = """load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "sources",
    srcs = glob(["**"]),
)

cmake(
    name = "librdkafka",
    cache_entries = {
        "RDKAFKA_BUILD_STATIC": "ON",
        "RDKAFKA_BUILD_TESTS": "OFF",
        "RDKAFKA_BUILD_EXAMPLES": "OFF",
        "WITH_ZLIB": "OFF",
        "WITH_ZSTD": "OFF",
        "WITH_SSL": "OFF",
        "WITH_SASL": "OFF",
        "ENABLE_LZ4_EXT": "OFF",
        "WITH_LIBDL": "OFF",
    },
    lib_source = ":sources",
    out_static_libs = [
        "librdkafka++.a",
        "librdkafka.a",
    ],
    visibility = ["//visibility:public"],
)
""",
    strip_prefix = "librdkafka-1.7.0",
    urls = ["https://github.com/edenhill/librdkafka/archive/v1.7.0.tar.gz"],
)


http_archive(
    name = "com_github_facebook_rocksdb",
    url = "https://github.com/facebook/rocksdb/archive/v6.8.1.tar.gz",
    strip_prefix = "rocksdb-6.8.1",
    sha256 = "ca192a06ed3bcb9f09060add7e9d0daee1ae7a8705a3d5ecbe41867c5e2796a2",
    build_file = "//third_party/com_github_facebook_rocksdb:rocksdb.BUILD",
)

bind(
    name = "rocksdb",
    actual = "@com_github_facebook_rocksdb//:rocksdb",
)

# snappy
http_archive(
    name = "com_github_google_snappy",
    url = "https://github.com/google/snappy/archive/ed3b7b2.tar.gz",
    strip_prefix = "snappy-ed3b7b242bd24de2ca6750c73f64bee5b7505944",
    sha256 = "88a644b224f54edcd57d01074c2d6fd6858888e915c21344b8622c133c35a337",
    build_file = "//third_party:snappy.BUILD",
)

# zlib
new_git_repository(
    name = "com_github_madler_zlib",
    remote = "https://github.com/madler/zlib.git",
    tag = "v1.2.11",
    #sha256 = "629380c90a77b964d896ed37163f5c3a34f6e6d897311f1df2a7016355c45eff",
    build_file = "//third_party:zlib.BUILD",
)

bind(
    name = "zlib",
    actual = "@com_github_madler_zlib//:zlib",
)

bind(
    name = "snappy",
    actual = "@com_github_google_snappy//:snappy",
)

bind(
    name = "snappy_config",
    actual = "//third_party/snappy_config:config"
)

# lz4
http_archive(
    name = "com_github_lz4_lz4",
    urls = ["https://github.com/lz4/lz4/archive/v1.9.2.tar.gz"],
    strip_prefix = "lz4-1.9.2",
    build_file = "//third_party:lz4.BUILD",
    sha256 = "658ba6191fa44c92280d4aa2c271b0f4fbc0e34d249578dd05e50e76d0e5efcc",
)
bind(
    name = "lz4",
    actual = "@com_github_lz4_lz4//:lz4",
)

#zstd
http_archive(
    name = "com_github_facebook_zstd",
    urls = ["https://github.com/facebook/zstd/archive/v1.4.4.tar.gz",],
    strip_prefix = "zstd-1.4.4",
    build_file = "//third_party:zstd.BUILD",
    sha256 = "a364f5162c7d1a455cc915e8e3cf5f4bd8b75d09bc0f53965b0c9ca1383c52c8",
)

bind(
    name = "zstd",
    actual = "@com_github_facebook_zstd//:zstd",
)

#hash ring
new_git_repository(
    name = "com_github_hash_ring",
    remote = "https://github.com/chrismoos/hash-ring.git",
    tag = "v1.0.2",
    build_file = "//third_party:hashring.BUILD",
)

