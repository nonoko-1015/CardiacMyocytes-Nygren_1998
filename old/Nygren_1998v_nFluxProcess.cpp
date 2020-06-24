
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_nFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_nFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_nFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    n  = getVariableReference( "n" ).getVariable();
    n_infinity  = getVariableReference( "n_infinity" ).getVariable();
    tau_n  = getVariableReference( "tau_n" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (n_infinity->getValue()-n->getValue())/tau_n->getValue() );
  }

 protected:

  Variable* n;
  Variable* n_infinity;
  Variable* tau_n;


};

LIBECS_DM_INIT( Nygren_1998v_nFluxProcess, Process );
