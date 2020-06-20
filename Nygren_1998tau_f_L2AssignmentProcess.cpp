
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_f_L2AssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_f_L2AssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_f_L2AssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_f_L2  = getVariableReference( "tau_f_L2" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_f_L2->setValue( 1 * (1.33230*exp(-(pow((V->getValue()+40.0000)/14.2000, 2.00000)))+0.0626000) );

  }

 protected:

  Variable* tau_f_L2;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_f_L2AssignmentProcess, Process );
