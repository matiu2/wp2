/* /*! \file db.hpp
* =====================================================================================
* \brief Include this if you need to use the DB 
* \author Matthew Sherborne (), msherborne@gmail.com
* \version 1.0
* \date   06/08/11 06:45:55
*  \bug       None known to date
*  \warning   Improper use can crash your application
*  \copyright GNU Public License.
* =====================================================================================*/


#ifndef DB_HPP
#define DB_HPP

#include <Wt/Dbo/Session>

namespace dbo = Wt::Dbo;

namespace wp2 {

/// Returns the db session for the current app/thread
Wt::Dbo::Session& db();

} // namespace wittyPlus

#endif // DB_HPP
