#include <iostream>
#include <vector>
#include <string>

#include <esx/file.hpp>
#include <esx/math.hpp>

int main() {
    using namespace esx::file;
    using namespace esx::math;

    const std::string fileName = "example_test.txt";

    bool ok = writeTextFile(fileName, "Hello You!\nThis is a small test.\n");
    if (!ok) {
        std::cerr << "writeTextFile failed" << std::endl;
        return 1;
    }
    std::cout << "Wrote file: " << fileName << std::endl;

    std::string content = readTextFile(fileName);
    std::cout << "Full content:" << std::endl << "---" << std::endl << content << std::endl << "---" << std::endl;

    std::vector<std::string> lines = readTextFileLines(fileName);
    std::cout << "Read " << lines.size() << " lines:" << std::endl;
    for (size_t i = 0; i < lines.size(); ++i) {
        std::cout << i << ": " << lines[i] << std::endl;
    }

    // int idx = findChar(content, "E");
    // std::cout << "Index of 'E' in full content: " << idx << std::endl;

    std::vector<std::string> newLines = {"First", "Second", "Third"};
    if (!writeTextFileLines("lines_out.txt", newLines)) {
        std::cerr << "writeTextFileLines failed" << std::endl;
    }
    else {
        std::cout << "Wrote lines_out.txt\n";
    }

    if (!deleteFile(fileName)) {
        std::cerr << "deleteFile failed for " << fileName << "\n";
    }
    else {
        std::cout << "Deleted " << fileName << "\n";
    }

    int array[]{-42, -53, -74};

    std::cout << pos(arraySum(array)) << std::endl;


    return 0;
}
