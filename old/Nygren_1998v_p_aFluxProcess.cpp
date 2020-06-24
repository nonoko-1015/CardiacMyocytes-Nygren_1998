
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_p_aFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_p_aFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_p_aFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    p_a  = getVariableReference( "p_a" ).getVariable();
    p_a_infinity  = getVariableReference( "p_a_infinity" ).getVariable();
    tau_p_a  = getVariableReference( "tau_p_a" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (p_a_infinity->getValue()-p_a->getValue())/tau_p_a->getValue() );
  }

 protected:

  Variable* p_a;
  Variable* p_a_infinity;
  Variable* tau_p_a;


};

LIBECS_DM_INIT( Nygren_1998v_p_aFluxProcess, Process );
