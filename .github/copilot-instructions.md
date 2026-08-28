# Project C++ Guidelines

- Target standard: **C++23**
- Header management: Always include required standard library headers explicitly (`<numeric>`, `<fstream>`, `<iomanip>`).
- Const correctness: Use `const` accessors and pass parameters by `const &` where appropriate.
- Class Serialization: Use `nlohmann/json` patterns (`toJson()` and `fromJson()`).