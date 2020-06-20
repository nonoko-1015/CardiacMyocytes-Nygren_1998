
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998tau_p_aAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998tau_p_aAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998tau_p_aAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    tau_p_a  = getVariableReference( "tau_p_a" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    tau_p_a->setValue( 1 * (0.0311800+0.217180*exp(-(pow((V->getValue()+20.1376)/22.1996, 2.00000)))) );

  }

 protected:

  Variable* tau_p_a;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998tau_p_aAssignmentProcess, Process );
