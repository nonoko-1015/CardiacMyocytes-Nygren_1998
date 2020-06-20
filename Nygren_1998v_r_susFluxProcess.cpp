
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_r_susFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_r_susFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_r_susFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    r_sus  = getVariableReference( "r_sus" ).getVariable();
    r_sus_infinity  = getVariableReference( "r_sus_infinity" ).getVariable();
    tau_r_sus  = getVariableReference( "tau_r_sus" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (r_sus_infinity->getValue()-r_sus->getValue())/tau_r_sus->getValue() );
  }

 protected:

  Variable* r_sus;
  Variable* r_sus_infinity;
  Variable* tau_r_sus;


};

LIBECS_DM_INIT( Nygren_1998v_r_susFluxProcess, Process );
