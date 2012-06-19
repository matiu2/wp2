#include "LabelWidgetPair.hpp"
#include <Wt/WLabel>
#include <Wt/WContainerWidget>
#include <Wt/WHBoxLayout>
#include <Wt/WFormWidget>

namespace wp2 {

LabelWidgetPair::LabelWidgetPair(Wt::WContainerWidget* parent, const Wt::WString& labelName, Wt::WFormWidget* widget)
    : Wt::WCompositeWidget(parent), _widget(widget)
{
    setImplementation(_root = new Wt::WContainerWidget());
    _label = new Wt::WLabel(labelName, _root);
    _root->addWidget(_widget);
    _label->setBuddy(_widget);
    // Layout
    Wt::WHBoxLayout* layout = new Wt::WHBoxLayout(_root);
    layout->addWidget(_label);
    layout->addWidget(_widget);
    _root->setLayout(layout);
}

} // namespace wp2
