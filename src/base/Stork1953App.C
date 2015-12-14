#include "Stork1953App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Stork1953App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Stork1953App::Stork1953App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Stork1953App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Stork1953App::associateSyntax(_syntax, _action_factory);
}

Stork1953App::~Stork1953App()
{
}

// External entry point for dynamic application loading
extern "C" void Stork1953App__registerApps() { Stork1953App::registerApps(); }
void
Stork1953App::registerApps()
{
  registerApp(Stork1953App);
}

// External entry point for dynamic object registration
extern "C" void Stork1953App__registerObjects(Factory & factory) { Stork1953App::registerObjects(factory); }
void
Stork1953App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Stork1953App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Stork1953App::associateSyntax(syntax, action_factory); }
void
Stork1953App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
