import os
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain
from conan.tools.files import copy

required_conan_version = ">=2.0.0"


class WebServerAdapterTestUtilitiesConan(ConanFile):
    name = "web-server-adapter-test-utilities"
    description = "Test utilities for library-agnostic API for C++ to work with a web server"
    url = "https://github.com/systelab/cpp-webserver-adapter"
    homepage = "https://github.com/systelab/cpp-webserver-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "web", "server", "http", "adapter", "wrapper", "test", "gtest")
    license = "MIT"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "*.h", "*.cpp", "CMakeLists.txt"

    def requirements(self):
        self.requires("gtest/1.14.0")

        self.requires("test-utilities-interface/1.1.0")
        if self.version is None:
            self.requires(f"web-server-adapter-interface/{os.environ['VERSION']}")
        else:
            self.requires(f"web-server-adapter-interface/{self.version}")

    def generate(self):
        CMakeDeps(self).generate()
        CMakeToolchain(self).generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(self, "*.h", src=self.source_folder, dst=os.path.join(self.package_folder, "include", "WebServerAdapterTestUtilities"), keep_path=True)
        copy(self, "*WebServerAdapterTestUtilities.lib", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*WebServerAdapterTestUtilities.pdb", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*WebServerAdapterTestUtilities.a", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "WebServerAdapterTestUtilities")
        self.cpp_info.set_property("cmake_target_name", "WebServerAdapterTestUtilities::WebServerAdapterTestUtilities")
        self.cpp_info.libs = ["WebServerAdapterTestUtilities"]
        self.cpp_info.requires = [
            "gtest::gtest",
            "test-utilities-interface::test-utilities-interface",
            "web-server-adapter-interface::web-server-adapter-interface",
        ]
