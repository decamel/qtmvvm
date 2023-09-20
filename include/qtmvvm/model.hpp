#pragma once

#if !defined(QTMVVM_MODEL_H)
#define QTMVVM_MODEL_H

namespace qtmvvm
{
  class IModel
  {
  public:
    virtual ~IModel() {}
    virtual void initState() = 0;
  };
} // namespace qtmvvm

#endif // QTMVVM_MODEL_H
