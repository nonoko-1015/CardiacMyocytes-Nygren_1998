
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_f_L1AssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_f_L1AssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_f_L1AssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_f_L1  = getVariableReference( "tau_f_L1" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_f_L1->setValue( 1 * (0.161000*exp(-(pow((V->getValue()+40.0000)/14.4000, 2.00000)))+0.0100000) );

  }

 protected:

  Variable* tau_f_L1;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_f_L1AssignmentProcess, Process );
