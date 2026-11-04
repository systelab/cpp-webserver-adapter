import os
from conan import ConanFile
from conan.tools.files import copy

required_conan_version = ">=2.0.0"


class WebServerAdapterInterfaceConan(ConanFile):
    name = "web-server-adapter-interface"
    description = "Interface of library-agnostic API for C++ to work with a web server"
    url = "https://github.com/systelab/cpp-webserver-adapter"
    homepage = "https://github.com/systelab/cpp-webserver-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "web", "server", "http", "adapter", "wrapper")
    license = "MIT"
    package_type = "header-library"
    # No settings/options are necessary, this is header only
    exports_sources = "*"

    def package(self):
        copy(self, "*.h", src=self.source_folder, dst=os.path.join(self.package_folder, "include", "WebServerAdapterInterface"), excludes="WebServerAdapterTestUtilities/*.*")
        copy(self, "*.inl", src=self.source_folder, dst=os.path.join(self.package_folder, "include", "WebServerAdapterInterface"), excludes="WebServerAdapterTestUtilities/*.*")

    def package_id(self):
        self.info.clear()

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "WebServerAdapterInterface")
        self.cpp_info.set_property("cmake_target_name", "WebServerAdapterInterface::WebServerAdapterInterface")
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
