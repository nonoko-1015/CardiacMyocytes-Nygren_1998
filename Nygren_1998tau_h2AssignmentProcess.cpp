
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_h2AssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_h2AssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_h2AssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_h2  = getVariableReference( "tau_h2" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_h2->setValue( 1 * (0.120000/(1.00000+exp((V->getValue()+35.1000)/3.20000))+0.00300000) );

  }

 protected:

  Variable* tau_h2;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_h2AssignmentProcess, Process );
