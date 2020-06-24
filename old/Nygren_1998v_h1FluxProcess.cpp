
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_h1FluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_h1FluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_h1FluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    h1  = getVariableReference( "h1" ).getVariable();
    h_infinity  = getVariableReference( "h_infinity" ).getVariable();
    tau_h1  = getVariableReference( "tau_h1" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (h_infinity->getValue()-h1->getValue())/tau_h1->getValue() );
  }

 protected:

  Variable* h1;
  Variable* h_infinity;
  Variable* tau_h1;


};

LIBECS_DM_INIT( Nygren_1998v_h1FluxProcess, Process );
