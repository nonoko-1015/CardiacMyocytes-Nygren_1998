
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_h1AssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_h1AssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_h1AssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_h1  = getVariableReference( "tau_h1" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_h1->setValue( 1 * (0.0300000/(1.00000+exp((V->getValue()+35.1000)/3.20000))+0.000300000) );

  }

 protected:

  Variable* tau_h1;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_h1AssignmentProcess, Process );
