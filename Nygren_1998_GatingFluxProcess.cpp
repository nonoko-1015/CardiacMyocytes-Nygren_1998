
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_GatingFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_GatingFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998_GatingFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    gate  = getVariableReference( "gate" ).getVariable();
    g_inf  = getVariableReference( "g_inf" ).getVariable();
    g_tau  = getVariableReference( "g_tau" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (g_inf->getValue() - gate->getValue())/ g_tau->getValue() );
  }

 protected:

  Variable* gate;
  Variable* g_inf;
  Variable* g_tau;


};

LIBECS_DM_INIT( Nygren_1998_GatingFluxProcess, Process );
