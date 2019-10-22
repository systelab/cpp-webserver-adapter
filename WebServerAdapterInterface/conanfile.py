from conans import ConanFile


class WebServerAdapterInterfaceConan(ConanFile):
    name = "WebServerAdapterInterface"
    description = "Interface of library-agnostic API for C++ to work with a web server"
    url = "https://github.com/systelab/cpp-webserver-adapter"
    homepage = "https://github.com/systelab/cpp-webserver-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "web", "server", "http", "adapter", "wrapper")
    license = "MIT"
    generators = "cmake_find_package"
    # No settings/options are necessary, this is header only

    def package(self):
        self.copy("*.h", dst="include/WebServerAdapterInterface")
        self.copy("*.inl", dst="include/WebServerAdapterInterface")

    def package_info(self):
        self.info.header_only()
