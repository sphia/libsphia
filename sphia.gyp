{
  "targets": [
    {
      "target_name": "sphia",
      "product_prefix": "lib",
      "type": "static_library",
      "link_settings": {
        "libraries": [ "-lsophia" ]
      },
      "dependencies": [
        "deps/str-ends-with/str-ends-with.gyp:str-ends-with"
      ],
      "include_dirs": [
        "deps",
        "include"
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
        "src/set.c",
        "src/iterator.c"
      ]
    },
    {
      "target_name": "sphia-test",
      "type": "executable",
      "dependencies": [ "sphia" ],
      "include_dirs": [ "deps", "include" ],
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
      "linkflags": [ "-lsophia" ],
      "defines": [
        'SPHIA_TEST_DB="/tmp/libsphia-test-db"'
      ]
    }
  ]
}
