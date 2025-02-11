#pragma once

#include <filesystem>
#include <functional>
#include <unordered_map>
#include <vector>

namespace fs = std::filesystem;

namespace std
{
template <> struct hash<fs::path> {
    size_t operator()(const fs::path &x) const
    {
        return fs::hash_value(x);
    }
};
} // namespace std

class Mod
{
  public:
    explicit Mod(const fs::path &root);

    std::string Name() const;
    bool        HasFile(const fs::path &file) const;
    void        ForEachFile(std::function<void(const fs::path &, const fs::path &)>) const;

  private:
    fs::path                               root_path;
    std::unordered_map<fs::path, fs::path> file_mappings;
};
