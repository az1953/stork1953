#ifndef STORK1953APP_H
#define STORK1953APP_H

#include "MooseApp.h"

class Stork1953App;

template<>
InputParameters validParams<Stork1953App>();

class Stork1953App : public MooseApp
{
public:
  Stork1953App(InputParameters parameters);
  virtual ~Stork1953App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* STORK1953APP_H */
