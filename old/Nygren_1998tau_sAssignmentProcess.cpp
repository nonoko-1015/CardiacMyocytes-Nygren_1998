
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_sAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_sAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_sAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_s  = getVariableReference( "tau_s" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_s->setValue( 1 * (0.481200*exp(-(pow((V->getValue()+52.4500)/14.9700, 2.00000)))+0.0141400) );

  }

 protected:

  Variable* tau_s;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_sAssignmentProcess, Process );
