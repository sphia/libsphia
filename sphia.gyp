{
  "variables": {
    "library%": "static_library"
  },
  "target_defaults": {
    "default_configuration": "Release",
    "configurations": {
      "Debug": {
        "defines": ["DEBUG"]
      },
      "Release": {
        "defines": ["NDEBUG"]
      }
    },
    "cflags": [
      "-std=c99",
      "-Wall",
      "-Wextra",
      "-fvisibility=hidden",
      "-g",
      "-O2"
    ],
    "target_conditions": [
      ["_type=='shared_library'", {
        "cflags": ["-fPIC"]
      }]
    ],
    "link_settings": {
      "libraries": ["-lsophia", "-lpthread"]
    },
    "include_dirs": [
      "deps",
      "include"
    ],
    "direct_dependent_settings": {
      "cflags": [
        "-std=c99",
        "-Wall",
        "-Wextra",
        "-fvisibility=hidden",
        "-g",
        "-O2",
        "-fPIC"
      ]
    }
  },
  "targets": [
    {
      "target_name": "sphia",
      "product_prefix": "lib",
      "type": "<(library)",
      "dependencies": [
        "deps/str-ends-with/str-ends-with.gyp:str-ends-with"
      ],
      "sources": [
        "src/clear.c",
        "src/count.c",
        "src/error.c",
        "src/free.c",
        "src/get.c",
        "src/new.c",
        "src/purge.c",
        "src/rm.c",
        "src/set.c"
      ]
    },
    {
      "target_name": "sphia-test",
      "type": "executable",
      "dependencies": [ "sphia" ],
      "sources": [
        "test/clear.c",
        "test/count.c",
        "test/error.c",
        "test/free.c",
        "test/get.c",
        "test/new.c",
        "test/purge.c",
        "test/rm.c",
        "test/set.c",
        "test.c"
      ],
      "defines": [
        "DEBUG",
        # TODO: Once Windows support is added, change this.
        'SPHIA_TEST_DB="/tmp/libsphia-test-db"'
      ]
    }
  ]
}
