
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_h2FluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_h2FluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_h2FluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    h2  = getVariableReference( "h2" ).getVariable();
    h_infinity  = getVariableReference( "h_infinity" ).getVariable();
    tau_h2  = getVariableReference( "tau_h2" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (h_infinity->getValue()-h2->getValue())/tau_h2->getValue() );
  }

 protected:

  Variable* h2;
  Variable* h_infinity;
  Variable* tau_h2;


};

LIBECS_DM_INIT( Nygren_1998v_h2FluxProcess, Process );
