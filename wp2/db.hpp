/*
 * =====================================================================================
 *
 *       Filename:  db.hpp
 *
 *    Description:  Include this if you need to use the DB
 *
 *        Version:  1.0
 *        Created:  06/08/11 06:45:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Sherborne (), msherborne@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef DB_HPP
#define DB_HPP

#include <Wt/Dbo/Session>

namespace dbo = Wt::Dbo;

namespace wp2 {

/// Returns the db session for the current app/thread
Wt::Dbo::Session& db();

} // namespace wittyPlus

#endif // DB_HPP
