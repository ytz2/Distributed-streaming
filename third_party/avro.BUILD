genrule(
    name = "api_hdrs",
    srcs = glob(
        ["lang/c++/api/**/*.hh"],
    ),
    outs = [
        "avro/AvroTraits.hh",
        "avro/Boost.hh",
        "avro/Compiler.hh",
        "avro/Config.hh",
        "avro/DataFile.hh",
        "avro/Decoder.hh",
        "avro/Encoder.hh",
        "avro/Exception.hh",
        "avro/Generic.hh",
        "avro/GenericDatum.hh",
        "avro/Layout.hh",
        "avro/Node.hh",
        "avro/NodeConcepts.hh",
        "avro/NodeImpl.hh",
        "avro/Reader.hh",
        "avro/Resolver.hh",
        "avro/ResolverSchema.hh",
        "avro/Schema.hh",
        "avro/SchemaResolution.hh",
        "avro/Specific.hh",
        "avro/Stream.hh",
        "avro/Types.hh",
        "avro/Validator.hh",
        "avro/ValidSchema.hh",
        "avro/Zigzag.hh",
        "avro/buffer/Buffer.hh",
        "avro/buffer/BufferReader.hh",
        "avro/buffer/detail/BufferDetail.hh",
        "avro/buffer/detail/BufferDetailIterator.hh",
    ],
    cmd = "cp -r external/avro_archive/lang/c++/api/*.hh $(@D)/avro/;" +
        "cp -r external/avro_archive/lang/c++/api/buffer/*.hh $(@D)/avro/buffer/;" +
        "cp -r external/avro_archive/lang/c++/api/buffer/detail/*.hh $(@D)/avro/buffer/detail/",
)

cc_library(
    name = "avro",
    srcs = [
        ":api_hdrs",
        "lang/c++/impl/BinaryDecoder.cc",
        "lang/c++/impl/BinaryEncoder.cc",
        "lang/c++/impl/Compiler.cc",
        "lang/c++/impl/DataFile.cc",
        "lang/c++/impl/FileStream.cc",
        "lang/c++/impl/Generic.cc",
        "lang/c++/impl/GenericDatum.cc",
        "lang/c++/impl/Node.cc",
        "lang/c++/impl/NodeImpl.cc",
        "lang/c++/impl/Resolver.cc",
        "lang/c++/impl/ResolverSchema.cc",
        "lang/c++/impl/Schema.cc",
        "lang/c++/impl/Stream.cc",
        "lang/c++/impl/Types.cc",
        "lang/c++/impl/ValidSchema.cc",
        "lang/c++/impl/Validator.cc",
        "lang/c++/impl/Zigzag.cc",
        "lang/c++/impl/json/JsonIO.hh",
        "lang/c++/impl/json/JsonIO.cc",
        "lang/c++/impl/json/JsonDom.hh",
        "lang/c++/impl/json/JsonDom.cc",
        "lang/c++/impl/parsing/JsonCodec.cc",
        "lang/c++/impl/parsing/ResolvingDecoder.cc",
        "lang/c++/impl/parsing/Symbol.hh",
        "lang/c++/impl/parsing/Symbol.cc",
        "lang/c++/impl/parsing/ValidatingCodec.hh",
        "lang/c++/impl/parsing/ValidatingCodec.cc",
    ],
    includes = [
        "avro",
        "avro/buffer",
    ],
    copts = [
        "-Wno-deprecated-declarations",
        "-Wno-int-in-bool-context",
        "-Wno-mismatched-tags",
        "-Wno-unused-const-variable",
        "-std=c++14",
    ],
    deps = [
        "//external:zlib",
        "//external:boost_system",
        "//external:boost_program_options",
        "//external:boost_iostreams",
        "//external:boost_format",
        "//external:boost_ptr_container",
    ],
    linkstatic = 1,
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "avrogen",
    srcs = [
        "lang/c++/impl/avrogencpp.cc",
    ],
    deps = [
        ":avro",
        "//external:boost_algorithm",
    ],
    linkstatic = 1,
)