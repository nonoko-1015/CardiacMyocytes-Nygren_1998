
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_r_susAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_r_susAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_r_susAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_r_sus  = getVariableReference( "tau_r_sus" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_r_sus->setValue( 1 * (0.00900000/(1.00000+exp((V->getValue()+5.00000)/12.0000))+0.000500000) );

  }

 protected:

  Variable* tau_r_sus;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_r_susAssignmentProcess, Process );
