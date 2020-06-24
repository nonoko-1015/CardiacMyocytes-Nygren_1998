
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_f_L_1FluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_f_L_1FluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_f_L_1FluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    f_L_1  = getVariableReference( "f_L_1" ).getVariable();
    f_L_infinity  = getVariableReference( "f_L_infinity" ).getVariable();
    tau_f_L1  = getVariableReference( "tau_f_L1" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (f_L_infinity->getValue()-f_L_1->getValue())/tau_f_L1->getValue() );
  }

 protected:

  Variable* f_L_1;
  Variable* f_L_infinity;
  Variable* tau_f_L1;


};

LIBECS_DM_INIT( Nygren_1998v_f_L_1FluxProcess, Process );
