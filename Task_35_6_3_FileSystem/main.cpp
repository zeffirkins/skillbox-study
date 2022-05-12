#include <iostream>
#include <filesystem>
#include <string>
using namespace std;

int main() {
    cout << "Enter path  to the catalog=>";
    filesystem::path path;
    cin >> path;
    cout << "Enter extension in format '.format' =>";
    string extension;
    cin >> extension;

    auto recursiveGetFileNamesByExtension = [](filesystem::path path, const string extension) {
        if (filesystem::is_regular_file(path) && path.extension().compare(extension) == 0)
            cout << path << "\n";
    };

    for (auto p : filesystem::recursive_directory_iterator(path)) {
        recursiveGetFileNamesByExtension(p.path(), extension);
    }
}