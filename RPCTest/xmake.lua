target("RPCTest")
    set_kind("binary")
    add_headerfiles("*.h")
    add_files("*.cpp")
    add_includedirs("$(projectdir)/RPCTest")