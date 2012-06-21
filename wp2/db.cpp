/* /*! \file db.cpp
 * =====================================================================================
 *      \brief this file is the core of  code  nicely documented file
 * 
 * \author Matthew Sherborne (), msherborne@gmail.com
* \version 0.1
* \date 6 septembre 2007
* *  \bug       None known to date
 *  \warning   Improper use can crash your application
 *  \copyright GNU Public License.
* =====================================================================================*/
#include"db.hpp"
#include <Wt/WApplication>
#include "BaseApp.hpp"

namespace wp2 {

Wt::Dbo::Session& db() {
    return dynamic_cast<wp2::BaseApp*>(Wt::WApplication::instance())->dbSession();
}

} // namespace wittyPlus
