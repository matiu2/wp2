#include "BaseApp.hpp"
#include <string>

namespace wp2 {

BaseApp::connectDB (const std::string& postgresConnectionString) {
    // Set up the db
    _postgres.connect(postgresConnectionString);
    _db.setConnection(_postgres);
}

} // namespace wp2
