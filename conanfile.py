from conans import ConanFile, tools


class WebServerAdapterConan(ConanFile):
    name = "WebServerAdapter"
    description = "Library-agnostic API for C++ to work with a web server"
    url = "https://github.com/systelab/cpp-webserver-adapter"
    homepage = "https://github.com/systelab/cpp-webserver-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "web", "server", "http", "adapter", "wrapper")	
    license = "MIT"
    generators = "cmake"
    settings = "os", "compiler", "build_type", "arch"

    def package(self):
        self.copy("*.h", dst="include/WebServerAdapterInterface", src="WebServerAdapterInterface")
        self.copy("*.h", dst="include/WebServerAdapterTestUtilities", src="WebServerAdapterTestUtilities")
        self.copy("*WebServerAdapterTestUtilities.lib", dst="lib", keep_path=False)
        self.copy("*WebServerAdapterTestUtilities.pdb", dst="lib", keep_path=False)
        self.copy("*WebServerAdapterTestUtilities.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
