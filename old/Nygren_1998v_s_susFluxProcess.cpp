
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_s_susFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_s_susFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_s_susFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    s_sus  = getVariableReference( "s_sus" ).getVariable();
    s_sus_infinity  = getVariableReference( "s_sus_infinity" ).getVariable();
    tau_s_sus  = getVariableReference( "tau_s_sus" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (s_sus_infinity->getValue()-s_sus->getValue())/tau_s_sus->getValue() );
  }

 protected:

  Variable* s_sus;
  Variable* s_sus_infinity;
  Variable* tau_s_sus;


};

LIBECS_DM_INIT( Nygren_1998v_s_susFluxProcess, Process );
