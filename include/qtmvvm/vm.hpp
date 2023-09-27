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
  class ViewModel : public IViewModel
  {
  protected:
    IView *view_;
    std::shared_ptr<Model> model_;

  public:
    ViewModel(std::shared_ptr<Model> a_model) : m_model(a_model) {}

  public:
    void setView(IView *view)
    {
      QObject *viewObj = qobject_cast<QObject *>(view);
      if (viewObj == 0)
      {
        throw std::runtime_error("Invalid type of view passed into WidgetModel.setView method");
      }

      view_ = view;
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
    virtual void refreshView() {
      QCoreApplication::processEvents();
    };
  };
} // namespace qtmvvm

#endif // QTMVVM_VM_HPP
