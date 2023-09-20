#pragma once

#if !defined(QTMVVM_VM_HPP)
#define QTMVVM_VM_HPP

#include <stdexcept>
#include <type_traits>
#include <memory>
/* ----------------------------------- Qt ----------------------------------- */
#include <QCoreApplication>
#include <QObject>

#include "vm_iface.h"
/* -------------------------------------------------------------------------- */
/*                                Widget model                                */
/* -------------------------------------------------------------------------- */
namespace qtmvvm
{
  template <class IView, class Model>
  class ViewModel : public IViewModel
  {
  protected:
    QList<IView *> m_views;
    std::unique_ptr<Model> m_model;

  public:
    ViewModel(std::unique_ptr<Model> a_model) : m_model(std::move(a_model)) {}

  public:
    void addView(IView *view)
    {
      if (m_views.contains(view))
      {
        return;
      }
      QObject *viewObj = qobject_cast<QObject *>(view);
      if (viewObj == 0)
      {
        throw std::runtime_error("Invalid type of view passed into WidgetModel.addView method");
      }

      connectView(view);
      refreshView(view);
      m_views.append(view);
    }

  protected:
    /**
     * @brief Refresh views connected with this <WidgetModel>
     */
    void refreshView()
    {
      for (typename QList<IView *>::const_interator it = m_views.constBegin(); it != m_views.constEnd(); ++it)
      {
        refreshView(*it);
        QCoreApplication::processEvents();
      }
    }
  protected:
    /**
     * @brief Connects necessary signals and slots of <IView> and this <WidgetModel>
     * 
     * @param view Connectable view
     */
    virtual void connectView(IView *view) const = 0;

    /**
     * @brief Refreshes concrete view connected with this <WidgetModel>
     * 
     * @param view <IView> which should be refreshed
     */
    virtual void refreshView(IView *view) = 0;
  };
} // namespace qtmvvm

#endif // QTMVVM_VM_HPP
