# Capstone Project Architecture Rules

## Project Guidelines
- Target Language Standard: C++23.
- Namespace Requirement: Enclose all classes and functions within `namespace DataPipeline`.
- Included Libraries: Use header-only `json.hpp` (`nlohmann::json`) for JSON operations.
- Coding Standards:
  - Apply `[[nodiscard]]` to all pure functions returning values.
  - Pre-allocate memory using `vector::reserve()` when dynamic buffers are populated.
  - Implement robust exception handling (`std::invalid_argument`, `std::runtime_error`, `nlohmann::json::parse_error`).
  - Prefer single-pass standard library algorithms (e.g., `std::minmax_element`, `std::copy_if`, `std::accumulate`).
  - Do NOT write raw multi-pass loops where an STL algorithm applies.