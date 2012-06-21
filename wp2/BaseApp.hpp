/* /*! \file BaseApp.hpp
 * =====================================================================================
 *      \brief this file is a header 
 * with it self a brief documentation
 * \author Matthew Sherborne (), msherborne@gmail.com
* \version 0.1
* \date 6 septembre 2007
* *  \bug       None known to date
 *  \warning   Improper use can crash your application
 *  \copyright GNU Public License.
* =====================================================================================*/
#ifndef WP2_BASEAPP_HPP
#define WP2_BASEAPP_HPP

#include <string>
#include <Wt/WApplication>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/Session>

namespace wp2 {

/** The base class for all wp2 applications.
  * One must derive from this in order to use wp2 features.
  */
class BaseApp : public Wt::WApplication {
private:
    Wt::Dbo::Session _dbSession;
    Wt::Dbo::backend::Postgres _postgres;
protected:
    /// Call this in your constructor before using db()
    void connectDB(const std::string& postgresConnectionString) {
        _postgres.connect(postgresConnectionString);
        _dbSession.setConnection(_postgres);
    }
public:
    BaseApp(const Wt::WEnvironment& env) : Wt::WApplication(env), _dbSession() {}
    Wt::Dbo::Session& dbSession() { return _dbSession; }
};

} // namespace wp2

#endif // WP2_BASEAPP_HPP
