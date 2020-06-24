
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_sFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_sFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_sFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    s  = getVariableReference( "s" ).getVariable();
    s_infinity  = getVariableReference( "s_infinity" ).getVariable();
    tau_s  = getVariableReference( "tau_s" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (s_infinity->getValue()-s->getValue())/tau_s->getValue() );
  }

 protected:

  Variable* s;
  Variable* s_infinity;
  Variable* tau_s;


};

LIBECS_DM_INIT( Nygren_1998v_sFluxProcess, Process );
