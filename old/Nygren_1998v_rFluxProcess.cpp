
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_rFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_rFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_rFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    r  = getVariableReference( "r" ).getVariable();
    r_infinity  = getVariableReference( "r_infinity" ).getVariable();
    tau_r  = getVariableReference( "tau_r" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (r_infinity->getValue()-r->getValue())/tau_r->getValue() );
  }

 protected:

  Variable* r;
  Variable* r_infinity;
  Variable* tau_r;


};

LIBECS_DM_INIT( Nygren_1998v_rFluxProcess, Process );
