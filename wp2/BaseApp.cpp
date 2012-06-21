/* /*! \file BaseApp.cpp
 * =====================================================================================
 *      \brief this file holds the code  all nicely documented file
 * 
 * \author Matthew Sherborne (), msherborne@gmail.com
* \version 0.1
* \date 6 septembre 2007
* *  \bug       None known to date
 *  \warning   Improper use can crash your application
 *  \copyright GNU Public License.
* =====================================================================================*/
#include "BaseApp.hpp"
#include <string>

namespace wp2 {

BaseApp::connectDB (const std::string& postgresConnectionString) {
    // Set up the db
    _postgres.connect(postgresConnectionString);
    _db.setConnection(_postgres);
}

} // namespace wp2
