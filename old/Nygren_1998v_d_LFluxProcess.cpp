
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_d_LFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_d_LFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_d_LFluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    d_L  = getVariableReference( "d_L" ).getVariable();
    d_L_infinity  = getVariableReference( "d_L_infinity" ).getVariable();
    tau_d_L  = getVariableReference( "tau_d_L" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (d_L_infinity->getValue()-d_L->getValue())/tau_d_L->getValue() );
  }

 protected:

  Variable* d_L;
  Variable* d_L_infinity;
  Variable* tau_d_L;


};

LIBECS_DM_INIT( Nygren_1998v_d_LFluxProcess, Process );
