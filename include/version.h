#include <ostream>
#include <string>

namespace jg {

struct version_t {
  int major;
  int minor;
  int revision;
  std::string tag;
  bool modified;
};

inline std::ostream &operator<<(std::ostream &s, const version_t &x) {
  s << x.major << "." << x.minor;
  if (x.revision != 0) {
    s << "." << x.revision;
  }
  if (!x.tag.empty()) {
    s << "-" << x.tag;
  }
  if (x.modified) {
    s << "-MODIFIED";
  }
  return s;
}

inline bool operator<(const version_t &a, const version_t &b) {
  if (a.major < b.major) return true;
  if (a.major > b.major) return false;
  if (a.minor < b.minor) return true;
  if (a.minor > b.minor) return false;
  if (a.revision < b.revision) return true;
  if (a.revision > b.revision) return false;
  if (a.modified || b.modified) return false;
  if (a.tag.empty() && !b.tag.empty()) return true;
  return false;
}

inline bool operator<=(const version_t &a, const version_t &b) {
  if (a.major < b.major) return true;
  if (a.major > b.major) return false;
  if (a.minor < b.minor) return true;
  if (a.minor > b.minor) return false;
  if (a.revision < b.revision) return true;
  if (a.revision > b.revision) return false;
  if (a.modified || b.modified) return false;
  if (a.tag.empty() && !b.tag.empty()) return true;
  return a.tag == b.tag;
}

inline bool operator>(const version_t &a, const version_t &b) {
  if (a.major > b.major) return true;
  if (a.major < b.major) return false;
  if (a.minor > b.minor) return true;
  if (a.minor < b.minor) return false;
  if (a.revision > b.revision) return true;
  if (a.revision < b.revision) return false;
  if (a.modified || b.modified) return false;
  if (!a.tag.empty() && b.tag.empty()) return true;
  return false;
}

inline bool operator>=(const version_t &a, const version_t &b) {
  if (a.major > b.major) return true;
  if (a.major < b.major) return false;
  if (a.minor > b.minor) return true;
  if (a.minor < b.minor) return false;
  if (a.revision > b.revision) return true;
  if (a.revision < b.revision) return false;
  if (a.modified || b.modified) return false;
  if (!a.tag.empty() && b.tag.empty()) return true;
  return a.tag == b.tag;
}

inline bool operator==(const version_t &a, const version_t &b) {
  if (a.modified || b.modified) return false;
  return a.major == b.major && b.minor == b.minor && a.revision == b.revision &&
         a.tag == b.tag;
}

inline bool operator!=(const version_t &a, const version_t &b) {
  if (a.modified || b.modified) return false;
  return !(a == b);
}

}  // namespace jg
