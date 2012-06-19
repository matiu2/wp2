#include "db.hpp"
#include <Wt/WApplication>
#include "BaseApp.hpp"

namespace wp2 {

Wt::Dbo::Session& db() {
    return dynamic_cast<wp2::BaseApp*>(Wt::WApplication::instance())->dbSession();
}

} // namespace wittyPlus
