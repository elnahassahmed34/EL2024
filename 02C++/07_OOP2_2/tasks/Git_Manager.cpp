#include <iostream>
#include <map>
#include <vector>
#include <string>

class GitManager {
public:
    // Constructor
    GitManager() {
        std::cout << "Initialized new Git repository." << std::endl;
    }

    // Initialize a new repository
    void init() {
        files.clear();
        commits.clear();
        currentCommit = -1;
        std::cout << "Git repository initialized." << std::endl;
    }

    // Add a file to the staging area
    void add(const std::string& fileName) {
        stagedFiles.push_back(fileName);
        std::cout << "Added file to staging: " << fileName << std::endl;
    }

    // Commit changes to the repository
    void commit(const std::string& message) {
        if (stagedFiles.empty()) {
            std::cout << "No files staged for commit." << std::endl;
            return;
        }

        currentCommit++;
        commits[currentCommit] = {message, stagedFiles};
        stagedFiles.clear();
        std::cout << "Committed changes with message: \"" << message << "\"" << std::endl;
    }

    // Show the current status of the repository
    void status() const {
        std::cout << "Staged files:" << std::endl;
        for (const auto& file : stagedFiles) {
            std::cout << "  " << file << std::endl;
        }

        std::cout << "Commits:" << std::endl;
        for (const auto& commit : commits) {
            std::cout << "Commit " << commit.first << ": " << commit.second.first << std::endl;
            std::cout << "  Files:" << std::endl;
            for (const auto& file : commit.second.second) {
                std::cout << "    " << file << std::endl;
            }
        }
    }

private:
    std::vector<std::string> stagedFiles; // Files staged for commit
    std::map<int, std::pair<std::string, std::vector<std::string>>> commits; // Commit history
    int currentCommit; // ID of the current commit
};

int main() {
    GitManager git;

    git.init();
    git.add("file1.txt");
    git.add("file2.txt");
    git.commit("Initial commit");

    git.add("file3.txt");
    git.commit("Added file3");

    git.status();

    return 0;
}
