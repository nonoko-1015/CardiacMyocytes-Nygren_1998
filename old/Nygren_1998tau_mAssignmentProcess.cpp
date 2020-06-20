
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_mAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_mAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_mAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_m  = getVariableReference( "tau_m" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_m->setValue( 1 * (4.20000e-05*exp(-(pow((V->getValue()+25.5700)/28.8000, 2.00000)))+2.40000e-05) );

  }

 protected:

  Variable* tau_m;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_mAssignmentProcess, Process );
