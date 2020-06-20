
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_s_susAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_s_susAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_s_susAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_s_sus  = getVariableReference( "tau_s_sus" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_s_sus->setValue( 1 * (0.0470000/(1.00000+exp((V->getValue()+60.0000)/10.0000))+0.300000) );

  }

 protected:

  Variable* tau_s_sus;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_s_susAssignmentProcess, Process );
