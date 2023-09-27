#pragma once

#if !defined(QTMVVM_VM_HPP)
#define QTMVVM_VM_HPP

#include <stdexcept>
#include <type_traits>
#include <memory>
/* ----------------------------------- Qt ----------------------------------- */
#include <QCoreApplication>
#include <QObject>

#include "vm_iface.hpp"
/* -------------------------------------------------------------------------- */
/*                                Widget model                                */
/* -------------------------------------------------------------------------- */
namespace qtmvvm
{
  template <class IView, class Model>
  class ViewModel : public IViewModel<IView>
  {
  public:
    using ModelPtr = std::shared_ptr<Model>;

  protected:
    IView *view_;
    ModelPtr model_;

  public:
    ViewModel(ModelPtr a_model) : model_(a_model) {}

  public:
    virtual void setView(IView *view) override
    {
      IView *viewObj = dynamic_cast<IView *>(view);
      if (viewObj == 0)
      {
        throw std::runtime_error("Invalid type of view passed into WidgetModel.setView method");
      }

      view_ = viewObj;
      connectView();
      refreshView();
    }

  protected:
    /**
     * @brief Connects necessary signals and slots of <IView> and this <WidgetModel>
     *
     * @param view Connectable view
     */
    virtual void connectView() const {};

    /**
     * @brief Refreshes view connected with this <WidgetModel>
     *
     * Must call super
     *
     * @param view <IView> which should be refreshed
     */
    virtual void refreshView()
    {
      QCoreApplication::processEvents();
    };
  };
} // namespace qtmvvm

#endif // QTMVVM_VM_HPP
