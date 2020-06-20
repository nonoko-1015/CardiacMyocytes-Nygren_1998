@{
"""
Coder: Yasuhiro Naito <ynaito@sfc.keio.ac.jp>
"""
R  = 8314.0  # R in component membrane (millijoule_per_mole_kelvin)
T  = 306.15  # T in component membrane (kelvin)
F  = 96487   # F in component membrane (coulomb_per_mole)

stim_start     = 0.1        # stim_start in component membrane (second)
stim_end       = 100000000  # stim_end in component membrane (second)
stim_period    = 1          # stim_period in component membrane (second)
stim_duration  = 0.006      # stim_duration in component membrane (second)
stim_amplitude = -280       # stim_amplitude in component membrane (picoA)

Vol_i   = 0.005884          # Vol_i in component intracellular_ion_concentrations (nanolitre)
Vol_up  = 0.0003969         # Vol_up in component Ca_handling_by_the_SR (nanolitre)
Vol_rel = 4.41e-5           # Vol_rel in component Ca_handling_by_the_SR (nanolitre)
Vol_d   = 0.0200000 * Vol_i # Vol_d in component intracellular_ion_concentrations (nanolitre)
Vol_c   = 0.136000 * Vol_i  # Vol_c in component cleft_space_ion_concentrations (nanolitre)

Cm = 0.05          # Cm in component membrane (nanoF)
phi_Na_en = -1.68  # phi_Na_en in component intracellular_ion_concentrations (picoA)
k_rel_i = 0.0003   # k_rel_i in component Ca_handling_by_the_SR (millimolar)

}


Stepper FixedODE1Stepper( Default ){ StepInterval 1.0e-6; }

Stepper PassiveStepper( PSV ) {}

System System( / )
{
    StepperID    Default;

  Variable Variable(voi)
  {
    Name "time in component environment (second)";
    Value  0.0;
  }

  Process ExpressionFluxProcess(voi)
  {
    Name "time in component environment (second)";
    Expression "1.0";

    VariableReferenceList
      [voi :.:voi  1];
  }

  ### Size
  Variable Variable( SIZE )
  {
      Value    @(Vol_i * 1.0e-9);
  }

  Variable Variable(Vol_i)
  {
    Name "Vol_i in component intracellular_ion_concentrations (litre)";
    Value  @(Vol_i * 1.0e-9);
  }

  Variable Variable(Vol_up)
  {
    Name "Vol_up in component Ca_handling_by_the_SR (litre)";
    Value  @(Vol_up * 1.0e-9);
  }

  Variable Variable(Vol_rel)
  {
    Name "Vol_rel in component Ca_handling_by_the_SR (litre)";
    Value  @(Vol_rel * 1.0e-9);
  }

  Variable Variable(Vol_d)
  {
    Name "Vol_d in component intracellular_ion_concentrations (litre)";
    Value  @(Vol_d * 1.0e-9);
  }

  Variable Variable(Vol_c)
  {
    Name "Vol_c in component cleft_space_ion_concentrations (litre)";
    Value  @(Vol_c * 1.0e-9);
  }


  ### status

  Variable Variable(V)
  {
    Name "V in component membrane (millivolt)";
    Value  -74.2525;
  }

  Variable Variable(Na_c)
  {
    Name "Na_c in component cleft_space_ion_concentrations (molar)";
    MolarConc  130.011e-3;
  }

  Variable Variable(Na_i)
  {
    Name "Na_i in component intracellular_ion_concentrations (molar)";
    MolarConc  8.5547e-3;
  }

  Variable Variable(m)
  {
    Name "m in component sodium_current_m_gate (dimensionless)";
    Value  0.0032017;
  }

  Variable Variable(h1)
  {
    Name "h1 in component sodium_current_h1_gate (dimensionless)";
    Value  0.8814;
  }

  Variable Variable(h2)
  {
    Name "h2 in component sodium_current_h2_gate (dimensionless)";
    Value  0.8742;
  }

  Variable Variable(Ca_d)
  {
    Name "Ca_d in component intracellular_ion_concentrations (molar)";
    MolarConc  7.2495e-8;
  }

  Variable Variable(d_L)
  {
    Name "d_L in component L_type_Ca_channel_d_L_gate (dimensionless)";
    Value  1.3005e-5;
  }

  Variable Variable(f_L_1)
  {
    Name "f_L_1 in component L_type_Ca_channel_f_L1_gate (dimensionless)";
    Value  0.9986;
  }

  Variable Variable(f_L_2)
  {
    Name "f_L_2 in component L_type_Ca_channel_f_L2_gate (dimensionless)";
    Value  0.9986;
  }

  Variable Variable(K_c)
  {
    Name "K_c in component cleft_space_ion_concentrations (molar)";
    MolarConc  5.3581e-3;
  }

  Variable Variable(K_i)
  {
    Name "K_i in component intracellular_ion_concentrations (molar)";
    MolarConc  129.435e-3;
  }

  Variable Variable(r)
  {
    Name "r in component Ca_independent_transient_outward_K_current_r_gate (dimensionless)";
    Value  0.0010678;
  }

  Variable Variable(s)
  {
    Name "s in component Ca_independent_transient_outward_K_current_s_gate (dimensionless)";
    Value  0.949;
  }

  Variable Variable(r_sus)
  {
    Name "r_sus in component sustained_outward_K_current_r_sus_gate (dimensionless)";
    Value  0.00015949;
  }

  Variable Variable(s_sus)
  {
    Name "s_sus in component sustained_outward_K_current_s_sus_gate (dimensionless)";
    Value  0.9912;
  }

  Variable Variable(n)
  {
    Name "n in component delayed_rectifier_K_currents_n_gate (dimensionless)";
    Value  0.0048357;
  }

  Variable Variable(p_a)
  {
    Name "p_a in component delayed_rectifier_K_currents_pa_gate (dimensionless)";
    Value  0.0001;
  }

  Variable Variable(Ca_c)
  {
    Name "Ca_c in component cleft_space_ion_concentrations (molar)";
    MolarConc  1.8147e-3;
  }

  Variable Variable(Ca_i)
  {
    Name "Ca_i in component intracellular_ion_concentrations (molar)";
    MolarConc  6.729e-8;
  }

  Variable Variable(O_C)
  {
    Name "O_C in component intracellular_Ca_buffering (dimensionless)";
    Value  0.0275;
  }

  Variable Variable(O_TC)
  {
    Name "O_TC in component intracellular_Ca_buffering (dimensionless)";
    Value  0.0133;
  }

  Variable Variable(O_TMgC)
  {
    Name "O_TMgC in component intracellular_Ca_buffering (dimensionless)";
    Value  0.1961;
  }

  Variable Variable(O_TMgMg)
  {
    Name "O_TMgMg in component intracellular_Ca_buffering (dimensionless)";
    Value  0.7094;
  }

  Variable Variable(Ca_rel)
  {
    Name "Ca_rel in component Ca_handling_by_the_SR (molar)";
    MolarConc  0.6465e-3;
  }

  Variable Variable(Ca_up)
  {
    Name "Ca_up in component Ca_handling_by_the_SR (molar)";
    MolarConc  0.6646e-3;
  }

  Variable Variable(O_Calse)
  {
    Name "O_Calse in component Ca_handling_by_the_SR (dimensionless)";
    Value  0.4369;
  }

  Variable Variable(F1)
  {
    Name "F1 in component Ca_handling_by_the_SR (dimensionless)";
    Value  0.4284;
  }

  Variable Variable(F2)
  {
    Name "F2 in component Ca_handling_by_the_SR (dimensionless)";
    Value  0.0028;
  }


  ### algebraic

  Variable Variable(i_Stim)
  {
    Name "i_Stim in component membrane (picoA)";
    Value  0.0;
  }

  Variable Variable(m_infinity)
  {
    Name "m_infinity in component sodium_current_m_gate (dimensionless)";
    Value  0.0032017055046363744;
  }

  Variable Variable(h_infinity)
  {
    Name "h_infinity in component sodium_current_h1_gate (dimensionless)";
    Value  0.8818331920341357;
  }

  Variable Variable(d_L_infinity)
  {
    Name "d_L_infinity in component L_type_Ca_channel_d_L_gate (dimensionless)";
    Value  1.3001523226591241e-05;
  }

  Variable Variable(f_L_infinity)
  {
    Name "f_L_infinity in component L_type_Ca_channel_f_L1_gate (dimensionless)";
    Value  0.9986400461877076;
  }

  Variable Variable(r_infinity)
  {
    Name "r_infinity in component Ca_independent_transient_outward_K_current_r_gate (dimensionless)";
    Value  0.0010677467619427574;
  }

  Variable Variable(s_infinity)
  {
    Name "s_infinity in component Ca_independent_transient_outward_K_current_s_gate (dimensionless)";
    Value  0.949549739332083;
  }

  Variable Variable(r_sus_infinity)
  {
    Name "r_sus_infinity in component sustained_outward_K_current_r_sus_gate (dimensionless)";
    Value  0.00015937958206002146;
  }

  Variable Variable(s_sus_infinity)
  {
    Name "s_sus_infinity in component sustained_outward_K_current_s_sus_gate (dimensionless)";
    Value  0.998246137934045;
  }

  Variable Variable(n_infinity)
  {
    Name "n_infinity in component delayed_rectifier_K_currents_n_gate (dimensionless)";
    Value  0.0006026430448910566;
  }

  Variable Variable(p_a_infinity)
  {
    Name "p_a_infinity in component delayed_rectifier_K_currents_pa_gate (dimensionless)";
    Value  5.142078505326955e-05;
  }

  Variable Variable(r_act)
  {
    Name "r_act in component Ca_handling_by_the_SR (per_second)";
    Value  0.22966210288261288;
  }

  Variable Variable(E_Na)
  {
    Name "E_Na in component sodium_current (millivolt)";
    Value  71.78374025254665;
  }

  Variable Variable(tau_m)
  {
    Name "tau_m in component sodium_current_m_gate (second)";
    Value  2.6411712783673727e-05;
  }

  Variable Variable(tau_h1)
  {
    Name "tau_h1 in component sodium_current_h1_gate (second)";
    Value  0.03029985430041965;
  }

  Variable Variable(tau_h2)
  {
    Name "tau_h2 in component sodium_current_h2_gate (second)";
    Value  0.12299941720167859;
  }

  Variable Variable(tau_d_L)
  {
    Name "tau_d_L in component L_type_Ca_channel_d_L_gate (second)";
    Value  0.0024873842753601674;
  }

  Variable Variable(tau_f_L1)
  {
    Name "tau_f_L1 in component L_type_Ca_channel_f_L1_gate (second)";
    Value  0.010561832433011065;
  }

  Variable Variable(tau_f_L2)
  {
    Name "tau_f_L2 in component L_type_Ca_channel_f_L2_gate (second)";
    Value  0.06655984396077287;
  }

  Variable Variable(tau_r)
  {
    Name "tau_r in component Ca_independent_transient_outward_K_current_r_gate (second)";
    Value  0.0015076482796525805;
  }

  Variable Variable(tau_s)
  {
    Name "tau_s in component Ca_independent_transient_outward_K_current_s_gate (second)";
    Value  0.07183350864577431;
  }

  Variable Variable(tau_r_sus)
  {
    Name "tau_r_sus in component sustained_outward_K_current_r_sus_gate (second)";
    Value  0.009472038556972982;
  }

  Variable Variable(tau_s_sus)
  {
    Name "tau_s_sus in component sustained_outward_K_current_s_sus_gate (second)";
    Value  0.33788952618800877;
  }

  Variable Variable(tau_n)
  {
    Name "tau_n in component delayed_rectifier_K_currents_n_gate (second)";
    Value  0.7000000000905494;
  }

  Variable Variable(tau_p_a)
  {
    Name "tau_p_a in component delayed_rectifier_K_currents_pa_gate (second)";
    Value  0.031750398000436095;
  }

  Variable Variable(r_inact)
  {
    Name "r_inact in component Ca_handling_by_the_SR (per_second)";
    Value  34.342589791678876;
  }

  Variable Variable(i_Na)
  {
    Name "i_Na in component sodium_current (picoA)";
    Value  0.0;
  }

  Variable Variable(f_Ca)
  {
    Name "f_Ca in component L_type_Ca_channel (dimensionless)";
    Value  0.002891415473410205;
  }

  Variable Variable(i_Ca_L)
  {
    Name "i_Ca_L in component L_type_Ca_channel (picoA)";
    Value  0.0;
  }

  Variable Variable(E_K)
  {
    Name "E_K in component Ca_independent_transient_outward_K_current (millivolt)";
    Value  -84.00907384905881;
  }

  Variable Variable(i_t)
  {
    Name "i_t in component Ca_independent_transient_outward_K_current (picoA)";
    Value  0.0;
  }

  Variable Variable(i_sus)
  {
    Name "i_sus in component sustained_outward_K_current (picoA)";
    Value  0.0;
  }

  Variable Variable(p_i)
  {
    Name "p_i in component delayed_rectifier_K_currents_pi_gate (dimensionless)";
    Value  0.6904422140268597;
  }

  Variable Variable(i_K1)
  {
    Name "i_K1 in component inward_rectifier (picoA)";
    Value  0.0;
  }

  Variable Variable(i_Kr)
  {
    Name "i_Kr in component delayed_rectifier_K_currents (picoA)";
    Value  0.0;
  }

  Variable Variable(i_Ks)
  {
    Name "i_Ks in component delayed_rectifier_K_currents (picoA)";
    Value  0.0;
  }

  Variable Variable(i_B_Na)
  {
    Name "i_B_Na in component background_currents (picoA)";
    Value  0.0;
  }

  Variable Variable(E_Ca)
  {
    Name "E_Ca in component background_currents (millivolt)";
    Value  134.5701213309398;
  }

  Variable Variable(i_B_Ca)
  {
    Name "i_B_Ca in component background_currents (picoA)";
    Value  0.0;
  }

  Variable Variable(i_NaK)
  {
    Name "i_NaK in component sodium_potassium_pump (picoA)";
    Value  0.0;
  }

  Variable Variable(i_CaP)
  {
    Name "i_CaP in component sarcolemmal_calcium_pump_current (picoA)";
    Value  0.0;
  }

  Variable Variable(i_NaCa)
  {
    Name "i_NaCa in component Na_Ca_ion_exchanger_current (picoA)";
    Value  0.0;
  }

  Variable Variable(i_di)
  {
    Name "i_di in component intracellular_ion_concentrations (picoA)";
    Value  0.0;
  }

  Variable Variable(dOCdt)
  {
    Name "dOCdt in component intracellular_Ca_buffering (per_second)";
    Value  0.0;
  }

  Variable Variable(dOTCdt)
  {
    Name "dOTCdt in component intracellular_Ca_buffering (per_second)";
    Value  0.0;
  }

  Variable Variable(dOTMgCdt)
  {
    Name "dOTMgCdt in component intracellular_Ca_buffering (per_second)";
    Value  0.0;
  }

  Variable Variable(i_up)
  {
    Name "i_up in component Ca_handling_by_the_SR (picoA)";
    Value  0.0;
  }

  Variable Variable(i_tr)
  {
    Name "i_tr in component Ca_handling_by_the_SR (picoA)";
    Value  0.0;
  }

  Variable Variable(i_rel)
  {
    Name "i_rel in component Ca_handling_by_the_SR (picoA)";
    Value  0.0;
  }

  Variable Variable(v_O_Calse)
  {
    Name "d/dt O_Calse in component Ca_handling_by_the_SR (dimensionless)";
    Value  0.0;
  }


  Process ExpressionFluxProcess(v_O_TMgMg)
  {
    Expression "2000.00*Mg_i*((1.00000-O_TMgC.Value)-O_TMgMg.Value)-666.000*O_TMgMg.Value";
    Mg_i  2.5; # Mg_i in component intracellular_Ca_buffering (millimolar)

    VariableReferenceList
      [O_TMgMg :.:O_TMgMg 1]
      [O_TMgC  :.:O_TMgC  0];
  }

  Process ExpressionAssignmentProcess(r_act)
  {
    StepperID    PSV;

    Expression "203.800*(pow((Ca_i.MolarConc*1000)/((Ca_i.MolarConc*1000)+k_rel_i), 4.00000)+pow((Ca_d.MolarConc*1000)/((Ca_d.MolarConc*1000)+k_rel_d), 4.00000))";
    k_rel_d  0.003; # k_rel_d in component Ca_handling_by_the_SR (millimolar)
    k_rel_i  @k_rel_i;

    VariableReferenceList
      [r_act :.:r_act  1]
      [Ca_i  :.:Ca_i   0]
      [Ca_d  :.:Ca_d   0];
  }

  Process ExpressionFluxProcess(v_F1)
  {
    Expression "r_recov*((1.00000-F1.Value)-F2.Value)-r_act.Value*F1.Value";
    r_recov  0.815; # r_recov in component Ca_handling_by_the_SR (per_second)

    VariableReferenceList
      [F1    :.:F1     1]
      [F2    :.:F2     0]
      [r_act :.:r_act  0];
  }

  Process ExpressionAssignmentProcess(m_infinity)
  {
    StepperID    PSV;

    Name "m_infinity in component sodium_current_m_gate (dimensionless)";
    Expression "1.00000/(1.00000+exp((V.Value+27.1200)/-8.21000))";

    VariableReferenceList
      [m_infinity :.:m_infinity  1]
      [V          :.:V           0];
  }

  Process ExpressionAssignmentProcess(tau_m)
  {
    StepperID    PSV;

    Expression "4.20000e-05*exp(-(pow((V.Value+25.5700)/28.8000, 2.00000)))+2.40000e-05";

    VariableReferenceList
      [tau_m :.:tau_m  1]
      [V     :.:V      0];
  }

  Process ExpressionFluxProcess(v_m)
  {
    Expression "(m_infinity.Value-m.Value)/tau_m.Value";

    VariableReferenceList
      [m          :.:m           1]
      [m_infinity :.:m_infinity  0]
      [tau_m      :.:tau_m       0];
  }

  Process ExpressionAssignmentProcess(h_infinity)
  {
    StepperID    PSV;

    Name "h_infinity in component sodium_current_h1_gate (dimensionless)";
    Expression "1.00000/(1.00000+exp((V.Value+63.6000)/5.30000))";

    VariableReferenceList
      [h_infinity :.:h_infinity  1]
      [V          :.:V           0];
  }

  Process ExpressionAssignmentProcess(tau_h1)
  {
    StepperID    PSV;

    Expression "0.0300000/(1.00000+exp((V.Value+35.1000)/3.20000))+0.000300000";

    VariableReferenceList
      [tau_h1 :.:tau_h1  1]
      [V      :.:V       0];
  }

  Process ExpressionFluxProcess(v_h1)
  {
    Name "d/dt h1 in component sodium_current_h1_gate (dimensionless)";
    Expression "(h_infinity.Value-h1.Value)/tau_h1.Value";

    VariableReferenceList
      [h1         :.:h1          1]
      [h_infinity :.:h_infinity  0]
      [tau_h1     :.:tau_h1      0];
  }

  Process ExpressionAssignmentProcess(tau_h2)
  {
    StepperID    PSV;

    Expression "0.120000/(1.00000+exp((V.Value+35.1000)/3.20000))+0.00300000";

    VariableReferenceList
      [tau_h2 :.:tau_h2  1]
      [V      :.:V       0];
  }

  Process ExpressionFluxProcess(v_h2)
  {
    Name "d/dt h2 in component sodium_current_h2_gate (dimensionless)";
    Expression "(h_infinity.Value-h2.Value)/tau_h2.Value";

    VariableReferenceList
      [h2         :.:h2          1]
      [h_infinity :.:h_infinity  0]
      [tau_h2     :.:tau_h2      0];
  }

  Process ExpressionAssignmentProcess(d_L_infinity)
  {
    StepperID    PSV;

    Name "d_L_infinity in component L_type_Ca_channel_d_L_gate (dimensionless)";
    Expression "1.00000/(1.00000+exp((V.Value+9.00000)/-5.80000))";

    VariableReferenceList
      [d_L_infinity :.:d_L_infinity  1]
      [V            :.:V             0];
  }

  Process ExpressionAssignmentProcess(tau_d_L)
  {
    StepperID    PSV;

    Expression "0.00270000*exp(-(pow((V.Value+35.0000)/30.0000, 2.00000)))+0.00200000";

    VariableReferenceList
      [tau_d_L :.:tau_d_L  1]
      [V       :.:V        0];
  }

  Process ExpressionFluxProcess(v_d_L)
  {
    Name "d/dt d_L in component L_type_Ca_channel_d_L_gate (dimensionless)";
    Expression "(d_L_infinity.Value-d_L.Value)/tau_d_L.Value";

    VariableReferenceList
      [d_L          :.:d_L           1]
      [d_L_infinity :.:d_L_infinity  0]
      [tau_d_L      :.:tau_d_L       0];
  }

  Process ExpressionAssignmentProcess(f_L_infinity)
  {
    StepperID    PSV;

    Expression "1.00000/(1.00000+exp((V.Value+27.4000)/7.10000))";

    VariableReferenceList
      [f_L_infinity :.:f_L_infinity  1]
      [V            :.:V             0];
  }

  Process ExpressionAssignmentProcess(tau_f_L1)
  {
    StepperID    PSV;

    Expression "0.161000*exp(-(pow((V.Value+40.0000)/14.4000, 2.00000)))+0.0100000";

    VariableReferenceList
      [tau_f_L1 :.:tau_f_L1  1]
      [V        :.:V         0];
  }

  Process ExpressionFluxProcess(v_f_L_1)
  {
    Name "d/dt f_L_1 in component L_type_Ca_channel_f_L1_gate (dimensionless)";
    Expression "(f_L_infinity.Value-f_L_1.Value)/tau_f_L1.Value";

    VariableReferenceList
      [f_L_1        :.:f_L_1         1]
      [f_L_infinity :.:f_L_infinity  0]
      [tau_f_L1     :.:tau_f_L1      0];
  }

  Process ExpressionAssignmentProcess(tau_f_L2)
  {
    StepperID    PSV;

    Expression "1.33230*exp(-(pow((V.Value+40.0000)/14.2000, 2.00000)))+0.0626000";

    VariableReferenceList
      [tau_f_L2 :.:tau_f_L2  1]
      [V        :.:V         0];
  }

  Process ExpressionFluxProcess(v_f_L_2)
  {
    Name "d/dt f_L_2 in component L_type_Ca_channel_f_L2_gate (dimensionless)";
    Expression "(f_L_infinity.Value-f_L_2.Value)/tau_f_L2.Value";

    VariableReferenceList
      [f_L_2        :.:f_L_2         1]
      [f_L_infinity :.:f_L_infinity  0]
      [tau_f_L2     :.:tau_f_L2      0];
  }

  Process ExpressionAssignmentProcess(tau_r)
  {
    StepperID    PSV;

    Expression "0.00350000*exp(-(pow(V.Value/30.0000, 2.00000)))+0.00150000";

    VariableReferenceList
      [tau_r :.:tau_r  1]
      [V     :.:V      0];
  }

  Process ExpressionAssignmentProcess(r_infinity)
  {
    StepperID    PSV;

    Expression "1.00000/(1.00000+exp((V.Value-1.00000)/-11.0000))";

    VariableReferenceList
      [r_infinity :.:r_infinity  1]
      [V          :.:V           0];
  }

  Process ExpressionFluxProcess(v_r)
  {
    Name "d/dt r in component Ca_independent_transient_outward_K_current_r_gate (dimensionless)";
    Expression "(r_infinity.Value-r.Value)/tau_r.Value";

    VariableReferenceList
      [r          :.:r           1]
      [r_infinity :.:r_infinity  0]
      [tau_r      :.:tau_r       0];
  }

  Process ExpressionAssignmentProcess(tau_s)
  {
    StepperID    PSV;

    Expression "0.481200*exp(-(pow((V.Value+52.4500)/14.9700, 2.00000)))+0.0141400";

    VariableReferenceList
      [tau_s :.:tau_s  1]
      [V     :.:V      0];
  }

  Process ExpressionAssignmentProcess(s_infinity)
  {
    StepperID    PSV;

    Expression "1.00000/(1.00000+exp((V.Value+40.5000)/11.5000))";

    VariableReferenceList
      [s_infinity :.:s_infinity  1]
      [V          :.:V           0];
  }

  Process ExpressionFluxProcess(v_s)
  {
    Name "d/dt s in component Ca_independent_transient_outward_K_current_s_gate (dimensionless)";
    Expression "(s_infinity.Value-s.Value)/tau_s.Value";

    VariableReferenceList
      [s          :.:s           1]
      [s_infinity :.:s_infinity  0]
      [tau_s      :.:tau_s       0];
  }

  Process ExpressionAssignmentProcess(tau_r_sus)
  {
    StepperID    PSV;

    Expression "0.00900000/(1.00000+exp((V.Value+5.00000)/12.0000))+0.000500000";

    VariableReferenceList
      [tau_r_sus :.:tau_r_sus  1]
      [V         :.:V          0];
  }

  Process ExpressionAssignmentProcess(r_sus_infinity)
  {
    StepperID    PSV;

    Expression "1.00000/(1.00000+exp((V.Value+4.30000)/-8.00000))";

    VariableReferenceList
      [r_sus_infinity :.:r_sus_infinity  1]
      [V              :.:V               0];
  }

  Process ExpressionFluxProcess(v_r_sus)
  {
    Name "d/dt r_sus in component sustained_outward_K_current_r_sus_gate (dimensionless)";
    Expression "(r_sus_infinity.Value-r_sus.Value)/tau_r_sus.Value";

    VariableReferenceList
      [r_sus          :.:r_sus           1]
      [r_sus_infinity :.:r_sus_infinity  0]
      [tau_r_sus      :.:tau_r_sus       0];
  }

  Process ExpressionAssignmentProcess(tau_s_sus)
  {
    StepperID    PSV;

    Expression "0.0470000/(1.00000+exp((V.Value+60.0000)/10.0000))+0.300000";

    VariableReferenceList
      [tau_s_sus :.:tau_s_sus  1]
      [V         :.:V          0];
  }

  Process ExpressionAssignmentProcess(s_sus_infinity)
  {
    StepperID    PSV;

    Expression "0.400000/(1.00000+exp((V.Value+20.0000)/10.0000))+0.600000";

    VariableReferenceList
      [s_sus_infinity :.:s_sus_infinity  1]
      [V              :.:V               0];
  }

  Process ExpressionFluxProcess(v_s_sus)
  {
    Name "d/dt s_sus in component sustained_outward_K_current_s_sus_gate (dimensionless)";
    Expression "(s_sus_infinity.Value-s_sus.Value)/tau_s_sus.Value";

    VariableReferenceList
      [s_sus          :.:s_sus           1]
      [s_sus_infinity :.:s_sus_infinity  0]
      [tau_s_sus      :.:tau_s_sus       0];
  }

  Process ExpressionAssignmentProcess(tau_n)
  {
    StepperID    PSV;

    Expression "0.700000+0.400000*exp(-(pow((V.Value-20.0000)/20.0000, 2.00000)))";

    VariableReferenceList
      [tau_n :.:tau_n  1]
      [V     :.:V      0];
  }

  Process ExpressionAssignmentProcess(n_infinity)
  {
    StepperID    PSV;

    Expression "1.00000/(1.00000+exp((V.Value-19.9000)/-12.7000))";

    VariableReferenceList
      [n_infinity :.:n_infinity  1]
      [V          :.:V           0];
  }

  Process ExpressionFluxProcess(v_n)
  {
    Name "d/dt n in component delayed_rectifier_K_currents_n_gate (dimensionless)";
    Expression "(n_infinity.Value-n.Value)/tau_n.Value";

    VariableReferenceList
      [n          :.:n           1]
      [n_infinity :.:n_infinity  0]
      [tau_n      :.:tau_n       0];
  }

  Process ExpressionAssignmentProcess(tau_p_a)
  {
    StepperID    PSV;

    Expression "0.0311800+0.217180*exp(-(pow((V.Value+20.1376)/22.1996, 2.00000)))";

    VariableReferenceList
      [tau_p_a :.:tau_p_a  1]
      [V       :.:V        0];
  }

  Process ExpressionAssignmentProcess(p_a_infinity)
  {
    StepperID    PSV;

    Expression "1.00000/(1.00000+exp((V.Value+15.0000)/-6.00000))";

    VariableReferenceList
      [p_a_infinity :.:p_a_infinity  1]
      [V            :.:V             0];
  }

  Process ExpressionFluxProcess(v_p_a)
  {
    Name "d/dt p_a in component delayed_rectifier_K_currents_pa_gate (dimensionless)";
    Expression "(p_a_infinity.Value-p_a.Value)/tau_p_a.Value";

    VariableReferenceList
      [p_a          :.:p_a           1]
      [p_a_infinity :.:p_a_infinity  0]
      [tau_p_a      :.:tau_p_a       0];
  }

  Process ExpressionAssignmentProcess(r_inact)
  {
    StepperID    PSV;

    Expression "33.9600+339.600*(pow((Ca_i.MolarConc*1000)/((Ca_i.MolarConc*1000)+k_rel_i), 4.00000))";
    k_rel_i  @k_rel_i;

    VariableReferenceList
      [r_inact :.:r_inact  1]
      [Ca_i    :.:Ca_i     0];
  }

  Process ExpressionFluxProcess(v_F2)
  {
    Name "d/dt F2 in component Ca_handling_by_the_SR (dimensionless)";
    Expression "r_act.Value*F1.Value-r_inact.Value*F2.Value";

    VariableReferenceList
      [F2      :.:F2       1]
      [r_act   :.:r_act    0]
      [F1      :.:F1       0]
      [r_inact :.:r_inact  0];
  }

  Process ExpressionAssignmentProcess(E_K)
  {
    StepperID    PSV;

    Expression "((R*T)/F)*log((K_c.MolarConc*1000)/(K_i.MolarConc*1000))";
    F  @F;
    T  @T;
    R  @R;

    VariableReferenceList
      [E_K :.:E_K  1]
      [K_c :.:K_c  0]
      [K_i :.:K_i  0];
  }

  Process ExpressionAssignmentProcess(i_t)
  {
    StepperID    PSV;

    Expression "g_t*r.Value*s.Value*(V.Value-E_K.Value)";
    g_t  7.5; # g_t in component Ca_independent_transient_outward_K_current (nanoS)

    VariableReferenceList
      [i_t :.:i_t  1]
      [r   :.:r    0]
      [s   :.:s    0]
      [V   :.:V    0]
      [E_K :.:E_K  0];
  }

  Process ExpressionAssignmentProcess(i_sus)
  {
    StepperID    PSV;

    Expression "g_sus*r_sus.Value*s_sus.Value*(V.Value-E_K.Value)";
    g_sus  2.75; # g_sus in component sustained_outward_K_current (nanoS)

    VariableReferenceList
      [i_sus :.:i_sus  1]
      [r_sus :.:r_sus  0]
      [s_sus :.:s_sus  0]
      [V     :.:V      0]
      [E_K   :.:E_K    0];
  }

  Process ExpressionAssignmentProcess(i_K1)
  {
    StepperID    PSV;

    Expression "(g_K1*(pow((K_c.MolarConc*1000)/1.00000, 0.445700))*(V.Value-E_K.Value))/(1.00000+exp((1.50000*((V.Value-E_K.Value)+3.60000)*F)/(R*T)))";
    T  @T;
    R  @R;
    F  @F;
    g_K1  3; # g_K1 in component inward_rectifier (nanoS)

    VariableReferenceList
      [i_K1 :.:i_K1  1]
      [K_c  :.:K_c   0]
      [V    :.:V     0]
      [E_K  :.:E_K   0];
  }

  Process ExpressionAssignmentProcess(p_i)
  {
    StepperID    PSV;

    Expression "1.00000/(1.00000+exp((V.Value+55.0000)/24.0000))";

    VariableReferenceList
      [p_i :.:p_i  1]
      [V   :.:V    0];
  }

  Process ExpressionAssignmentProcess(i_Kr)
  {
    StepperID    PSV;

    Expression "g_Kr*p_a.Value*p_i.Value*(V.Value-E_K.Value)";
    g_Kr  0.5; # g_Kr in component delayed_rectifier_K_currents (nanoS)

    VariableReferenceList
      [i_Kr :.:i_Kr  1]
      [p_a  :.:p_a   0]
      [p_i  :.:p_i   0]
      [V    :.:V     0]
      [E_K  :.:E_K   0];
  }

  Process ExpressionAssignmentProcess(i_Ks)
  {
    StepperID    PSV;

    Expression "g_Ks*n.Value*(V.Value-E_K.Value)";
    g_Ks  1; # g_Ks in component delayed_rectifier_K_currents (nanoS)

    VariableReferenceList
      [i_Ks :.:i_Ks  1]
      [n    :.:n     0]
      [V    :.:V     0]
      [E_K  :.:E_K   0];
  }

  Process ExpressionAssignmentProcess(i_NaK)
  {
    StepperID    PSV;

    Expression "(((((i_NaK_max*(K_c.MolarConc*1000))/((K_c.MolarConc*1000)+k_NaK_K))*(pow((Na_i.MolarConc*1000), 1.50000)))/(pow((Na_i.MolarConc*1000), 1.50000)+pow(k_NaK_Na, 1.50000)))*(V.Value+150.000))/(V.Value+200.000)";
    k_NaK_Na  11; # k_NaK_Na in component sodium_potassium_pump (millimolar)
    k_NaK_K  1; # k_NaK_K in component sodium_potassium_pump (millimolar)
    i_NaK_max  70.8253; # i_NaK_max in component sodium_potassium_pump (picoA)

    VariableReferenceList
      [i_NaK :.:i_NaK  1]
      [K_c   :.:K_c    0]
      [Na_i  :.:Na_i   0]
      [V     :.:V      0];
  }

  Process ExpressionFluxProcess(j_K_i)
  {
    Name "d/dt K_i in component intracellular_ion_concentrations (millimolar)";
    Expression "-((i_t.Value+i_sus.Value+i_K1.Value+i_Kr.Value+i_Ks.Value)-2.00000*i_NaK.Value)/(Vol_i*F) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_i  @Vol_i;

    VariableReferenceList
      [K_i   :.:K_i    1]
      [i_t   :.:i_t    0]
      [i_sus :.:i_sus  0]
      [i_K1  :.:i_K1   0]
      [i_Kr  :.:i_Kr   0]
      [i_Ks  :.:i_Ks   0]
      [i_NaK :.:i_NaK  0];
  }

  Process ExpressionFluxProcess(j_K_c)
  {
    Name "d/dt K_c in component cleft_space_ion_concentrations (millimolar)";
    Expression "(K_b-(K_c.MolarConc*1000))/tau_K * self.getSuperSystem().SizeN_A/1000 + ((i_t.Value+i_sus.Value+i_K1.Value+i_Kr.Value+i_Ks.Value)-2.00000*i_NaK.Value)/(Vol_c*F) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_c  @Vol_c;
    tau_K  10; # tau_K in component cleft_space_ion_concentrations (second)
    K_b  5.4; # K_b in component cleft_space_ion_concentrations (millimolar)

    VariableReferenceList
      [K_c   :.:K_c    1]
      [i_t   :.:i_t    0]
      [i_sus :.:i_sus  0]
      [i_K1  :.:i_K1   0]
      [i_Kr  :.:i_Kr   0]
      [i_Ks  :.:i_Ks   0]
      [i_NaK :.:i_NaK  0];
  }

  Process ExpressionAssignmentProcess(E_Na)
  {
    StepperID    PSV;

    Expression "((R*T)/F)*log((Na_c.MolarConc*1000)/(Na_i.MolarConc*1000))";
    F  @F;
    T  @T;
    R  @R;

    VariableReferenceList
      [E_Na :.:E_Na  1]
      [Na_c :.:Na_c  0]
      [Na_i :.:Na_i  0];
  }

  Process ExpressionAssignmentProcess(i_Na)
  {
    StepperID    PSV;

    Expression "(((P_Na*(pow(m.Value, 3.00000))*(0.900000*h1.Value+0.100000*h2.Value)*(Na_c.MolarConc*1000)*V.Value*(pow(F, 2.00000)))/(R*T))*(exp(((V.Value-E_Na.Value)*F)/(R*T))-1.00000))/(exp((V.Value*F)/(R*T))-1.00000)";
    T  @T;
    R  @R;
    F  @F;
    P_Na  0.0016; # P_Na in component sodium_current (nanolitre_per_second)

    VariableReferenceList
      [i_Na :.:i_Na  1]
      [m    :.:m     0]
      [h1   :.:h1    0]
      [h2   :.:h2    0]
      [Na_c :.:Na_c  0]
      [V    :.:V     0]
      [E_Na :.:E_Na  0];
  }

  Process ExpressionAssignmentProcess(f_Ca)
  {
    StepperID    PSV;

    Expression "(Ca_d.MolarConc*1000)/((Ca_d.MolarConc*1000)+k_Ca)";
    k_Ca  0.025; # k_Ca in component L_type_Ca_channel (millimolar)

    VariableReferenceList
      [f_Ca :.:f_Ca  1]
      [Ca_d :.:Ca_d  0];
  }

  Process ExpressionAssignmentProcess(i_Ca_L)
  {
    StepperID    PSV;

    Expression "g_Ca_L*d_L.Value*(f_Ca.Value*f_L_1.Value+(1.00000-f_Ca.Value)*f_L_2.Value)*(V.Value-E_Ca_app)";
    E_Ca_app  60; # E_Ca_app in component L_type_Ca_channel (millivolt)
    g_Ca_L  6.75; # g_Ca_L in component L_type_Ca_channel (nanoS)

    VariableReferenceList
      [i_Ca_L :.:i_Ca_L  1]
      [d_L    :.:d_L     0]
      [f_Ca   :.:f_Ca    0]
      [f_L_1  :.:f_L_1   0]
      [f_L_2  :.:f_L_2   0]
      [V      :.:V       0];
  }

  Process ExpressionAssignmentProcess(i_B_Na)
  {
    StepperID    PSV;

    Expression "g_B_Na*(V.Value-E_Na.Value)";
    g_B_Na  0.060599; # g_B_Na in component background_currents (nanoS)

    VariableReferenceList
      [i_B_Na :.:i_B_Na  1]
      [V      :.:V       0]
      [E_Na   :.:E_Na    0];
  }

  Process ExpressionAssignmentProcess(E_Ca)
  {
    StepperID    PSV;

    Expression "((R*T)/(2.00000*F))*log((Ca_c.MolarConc*1000)/(Ca_i.MolarConc*1000))";
    F  @F;
    T  @T;
    R  @R;

    VariableReferenceList
      [E_Ca :.:E_Ca  1]
      [Ca_c :.:Ca_c  0]
      [Ca_i :.:Ca_i  0];
  }

  Process ExpressionAssignmentProcess(i_B_Ca)
  {
    StepperID    PSV;

    Expression "g_B_Ca*(V.Value-E_Ca.Value)";
    g_B_Ca  0.078681; # g_B_Ca in component background_currents (nanoS)

    VariableReferenceList
      [i_B_Ca :.:i_B_Ca  1]
      [V      :.:V       0]
      [E_Ca   :.:E_Ca    0];
  }

  Process ExpressionAssignmentProcess(i_CaP)
  {
    StepperID    PSV;

    Expression "(i_CaP_max*(Ca_i.MolarConc*1000))/((Ca_i.MolarConc*1000)+k_CaP)";
    k_CaP  0.0002; # k_CaP in component sarcolemmal_calcium_pump_current (millimolar)
    i_CaP_max  4; # i_CaP_max in component sarcolemmal_calcium_pump_current (picoA)

    VariableReferenceList
      [i_CaP :.:i_CaP  1]
      [Ca_i  :.:Ca_i   0];
  }

  Process ExpressionAssignmentProcess(i_NaCa)
  {
    StepperID    PSV;

    Expression "(k_NaCa*((pow((Na_i.MolarConc*1000), 3.00000))*(Ca_c.MolarConc*1000)*exp((gamma*F*V.Value)/(R*T))-(pow((Na_c.MolarConc*1000), 3.00000))*(Ca_i.MolarConc*1000)*exp(((gamma-1.00000)*V.Value*F)/(R*T))))/(1.00000+d_NaCa*((pow((Na_c.MolarConc*1000), 3.00000))*(Ca_i.MolarConc*1000)+(pow((Na_i.MolarConc*1000), 3.00000))*(Ca_c.MolarConc*1000)))";
    T  @T;
    R  @R;
    F  @F;
    gamma  0.45; # gamma in component Na_Ca_ion_exchanger_current (dimensionless)
    k_NaCa  0.0374842; # k_NaCa in component Na_Ca_ion_exchanger_current (picoA_per_millimolar_4)
    d_NaCa  0.0003; # d_NaCa in component Na_Ca_ion_exchanger_current (per_millimolar_4)

    VariableReferenceList
      [i_NaCa :.:i_NaCa  1]
      [Na_i   :.:Na_i    0]
      [Ca_c   :.:Ca_c    0]
      [V      :.:V       0]
      [Na_c   :.:Na_c    0]
      [Ca_i   :.:Ca_i    0];
  }

  Process ExpressionAssignmentProcess(i_Stim)
  {
    StepperID    PSV;

    Name "i_Stim in component membrane (picoA)";
    Expression "piecewise(stim_amplitude, and(and(geq(voi.Value , stim_start), leq(voi.Value , stim_end)), leq((voi.Value-stim_start)-floor((voi.Value-stim_start)/stim_period)*stim_period , stim_duration)), 0.00000)";
    stim_amplitude  @stim_amplitude;
    stim_duration  @stim_duration;
    stim_period  @stim_period;
    stim_start  @stim_start;
    stim_end  @stim_end;

    VariableReferenceList
      [i_Stim :.:i_Stim  1]
      [voi    :.:voi     0];
  }

  Process ExpressionFluxProcess(v_V)
  {
    Name "d/dt V in component membrane (millivolt)";
    Expression "(-1.00000/Cm)*(i_Stim.Value+i_Na.Value+i_Ca_L.Value+i_t.Value+i_sus.Value+i_K1.Value+i_Kr.Value+i_Ks.Value+i_B_Na.Value+i_B_Ca.Value+i_NaK.Value+i_CaP.Value+i_NaCa.Value)";
    Cm  @Cm;

    VariableReferenceList
      [V      :.:V       1]
      [i_Stim :.:i_Stim  0]
      [i_Na   :.:i_Na    0]
      [i_Ca_L :.:i_Ca_L  0]
      [i_t    :.:i_t     0]
      [i_sus  :.:i_sus   0]
      [i_K1   :.:i_K1    0]
      [i_Kr   :.:i_Kr    0]
      [i_Ks   :.:i_Ks    0]
      [i_B_Na :.:i_B_Na  0]
      [i_B_Ca :.:i_B_Ca  0]
      [i_NaK  :.:i_NaK   0]
      [i_CaP  :.:i_CaP   0]
      [i_NaCa :.:i_NaCa  0];
  }

  Process ExpressionFluxProcess(j_Na_i)
  {
    Name "d/dt Na_i in component intracellular_ion_concentrations (millimolar)";
    Expression "-(i_Na.Value+i_B_Na.Value+3.00000*i_NaK.Value+3.00000*i_NaCa.Value+phi_Na_en)/(Vol_i*F) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_i  @Vol_i;
    phi_Na_en  @phi_Na_en;

      VariableReferenceList
        [Na_i   :.:Na_i    1]
        [i_Na   :.:i_Na    0]
        [i_B_Na :.:i_B_Na  0]
        [i_NaK  :.:i_NaK   0]
        [i_NaCa :.:i_NaCa  0];
  }

  Process ExpressionFluxProcess(j_Na_c)
  {
    Name "d/dt Na_c in component cleft_space_ion_concentrations (millimolar)";
    Expression "(Na_b-(Na_c.MolarConc*1000))/tau_Na * self.getSuperSystem().SizeN_A/1000 + (i_Na.Value+i_B_Na.Value+3.00000*i_NaK.Value+3.00000*i_NaCa.Value+phi_Na_en)/(Vol_c*F) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_c  @Vol_c;
    phi_Na_en  @phi_Na_en;
    tau_Na  14.3; # tau_Na in component cleft_space_ion_concentrations (second)
    Na_b  130; # Na_b in component cleft_space_ion_concentrations (millimolar)

      VariableReferenceList
        [Na_c   :.:Na_c    1]
        [i_Na   :.:i_Na    0]
        [i_B_Na :.:i_B_Na  0]
        [i_NaK  :.:i_NaK   0]
        [i_NaCa :.:i_NaCa  0];
  }

  Process ExpressionFluxProcess(j_Ca_c)
  {
    Name "d/dt Ca_c in component cleft_space_ion_concentrations (millimolar)";
    Expression "(Ca_b-(Ca_c.MolarConc*1000))/tau_Ca * self.getSuperSystem().SizeN_A/1000 + ((i_Ca_L.Value+i_B_Ca.Value+i_CaP.Value)-2.00000*i_NaCa.Value)/(2.00000*Vol_c*F) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_c  @Vol_c;
    tau_Ca  24.7; # tau_Ca in component cleft_space_ion_concentrations (second)
    Ca_b  1.8; # Ca_b in component cleft_space_ion_concentrations (millimolar)

    VariableReferenceList
      [Ca_c   :.:Ca_c    1]
      [i_Ca_L :.:i_Ca_L  0]
      [i_B_Ca :.:i_B_Ca  0]
      [i_CaP  :.:i_CaP   0]
      [i_NaCa :.:i_NaCa  0];
  }

  Process ExpressionFluxProcess(v_O_C)
  {
    Name "d/dt O_C in component intracellular_Ca_buffering (dimensionless)";
    Expression "dOCdt.Value";

    VariableReferenceList
      [O_C   :.:O_C    1]
      [dOCdt :.:dOCdt  0];
  }

  Process ExpressionAssignmentProcess(dOCdt)
  {
    StepperID    PSV;

    Expression "200000.0*(Ca_i.MolarConc*1000)*(1.00000-O_C.Value)-476.000*O_C.Value";

    VariableReferenceList
      [dOCdt :.:dOCdt  1]
      [O_C   :.:O_C    0]
      [Ca_i  :.:Ca_i   0];
  }

  Process ExpressionAssignmentProcess(i_di)
  {
    StepperID    PSV;

    Expression "(((Ca_d.MolarConc*1000)-(Ca_i.MolarConc*1000))*2.00000*F*Vol_d)/tau_di";
    tau_di  0.01; # tau_di in component intracellular_ion_concentrations (second)
    Vol_d  @Vol_d;
    F  @F;

    VariableReferenceList
      [i_di :.:i_di  1]
      [Ca_d :.:Ca_d  0]
      [Ca_i :.:Ca_i  0];
  }

  Process ExpressionFluxProcess(j_Ca_d)
  {
    Name "d/dt Ca_d in component intracellular_ion_concentrations (millimolar)";
    Expression "-(i_Ca_L.Value+i_di.Value)/(2.00000*Vol_d*F) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_d  @Vol_d;

    VariableReferenceList
      [Ca_d   :.:Ca_d    1]
      [i_di   :.:i_di    0]
      [i_Ca_L :.:i_Ca_L  0];
  }

  Process ExpressionFluxProcess(v_O_TC)
  {
    Name "d/dt O_TC in component intracellular_Ca_buffering (dimensionless)";
    Expression "dOTCdt.Value";

    VariableReferenceList
      [O_TC   :.:O_TC    1]
      [dOTCdt :.:dOTCdt  0];
  }

  Process ExpressionAssignmentProcess(dOTCdt)
  {
    StepperID    PSV;

  Expression "78400.0*(Ca_i.MolarConc*1000)*(1.00000-O_TC.Value)-392.000*O_TC.Value";

    VariableReferenceList
      [dOTCdt :.:dOTCdt  1]
      [O_TC   :.:O_TC    0]
      [Ca_i   :.:Ca_i    0];
  }

  Process ExpressionFluxProcess(v_O_TMgC)
  {
    Name "d/dt O_TMgC in component intracellular_Ca_buffering (dimensionless)";
    Expression "dOTMgCdt.Value";

    VariableReferenceList
      [O_TMgC   :.:O_TMgC    1]
      [dOTMgCdt :.:dOTMgCdt  0];
  }

  Process ExpressionAssignmentProcess(dOTMgCdt)
  {
    StepperID    PSV;

    Expression "200000.0*(Ca_i.MolarConc*1000)*((1.00000-O_TMgC.Value)-O_TMgMg.Value)-6.60000*O_TMgC.Value";

    VariableReferenceList
      [dOTMgCdt :.:dOTMgCdt  1]
      [O_TMgC   :.:O_TMgC    0]
      [Ca_i     :.:Ca_i      0]
      [O_TMgMg  :.:O_TMgMg   0];
  }

  Process ExpressionAssignmentProcess(i_up)
  {
    StepperID    PSV;

    Expression "(I_up_max*((Ca_i.MolarConc*1000)/k_cyca-((pow(k_xcs, 2.00000))*(Ca_up.MolarConc*1000))/k_srca))/(((Ca_i.MolarConc*1000)+k_cyca)/k_cyca+(k_xcs*((Ca_up.MolarConc*1000)+k_srca))/k_srca)";
    k_srca  0.5; # k_srca in component Ca_handling_by_the_SR (millimolar)
    k_xcs  0.4; # k_xcs in component Ca_handling_by_the_SR (dimensionless)
    k_cyca  0.0003; # k_cyca in component Ca_handling_by_the_SR (millimolar)
    I_up_max  2800; # I_up_max in component Ca_handling_by_the_SR (picoA)

    VariableReferenceList
      [i_up  :.:i_up   1]
      [Ca_i  :.:Ca_i   0]
      [Ca_up :.:Ca_up  0];
  }

  Process ExpressionAssignmentProcess(i_tr)
  {
    StepperID    PSV;

    Expression "(((Ca_up.MolarConc*1000)-(Ca_rel.MolarConc*1000))*2.00000*F*Vol_rel)/tau_tr";
    tau_tr  0.01; # tau_tr in component Ca_handling_by_the_SR (second)
    Vol_rel  @Vol_rel;
    F  @F;

    VariableReferenceList
      [i_tr   :.:i_tr    1]
      [Ca_up  :.:Ca_up   0]
      [Ca_rel :.:Ca_rel  0];
  }

  Process ExpressionFluxProcess(j_Ca_up)
  {
    Name "d/dt Ca_up in component Ca_handling_by_the_SR (millimolar)";
    Expression "(i_up.Value-i_tr.Value)/(2.00000*Vol_up*F) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_up  @Vol_up; # Vol_up in component Ca_handling_by_the_SR (nanolitre)

    VariableReferenceList
      [Ca_up :.:Ca_up  1]
      [i_up  :.:i_up   0]
      [i_tr  :.:i_tr   0];
  }

  Process ExpressionAssignmentProcess(i_rel)
  {
    StepperID    PSV;

    Expression "alpha_rel*(pow(F2.Value/(F2.Value+0.250000), 2.00000))*((Ca_rel.MolarConc*1000)-(Ca_i.MolarConc*1000))";
    alpha_rel  200000; # alpha_rel in component Ca_handling_by_the_SR (picoA_per_millimolar)

    VariableReferenceList
      [i_rel  :.:i_rel   1]
      [F2     :.:F2      0]
      [Ca_rel :.:Ca_rel  0]
      [Ca_i   :.:Ca_i    0];
  }

  Process ExpressionFluxProcess(j_Ca_i)
  {
    Name "d/dt Ca_i in component intracellular_ion_concentrations (millimolar)";
    Expression "-((((-i_di.Value+i_B_Ca.Value+i_CaP.Value)-2.00000*i_NaCa.Value)+i_up.Value)-i_rel.Value)/(2.00000*Vol_i*F) * self.getSuperSystem().SizeN_A/1000 -(0.0800000*dOTCdt.Value+0.160000*dOTMgCdt.Value+0.0450000*dOCdt.Value) * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_i  @Vol_i;

    VariableReferenceList
      [Ca_i     :.:Ca_i      1]
      [i_di     :.:i_di      0]
      [i_B_Ca   :.:i_B_Ca    0]
      [i_CaP    :.:i_CaP     0]
      [i_NaCa   :.:i_NaCa    0]
      [i_up     :.:i_up      0]
      [i_rel    :.:i_rel     0]
      [dOTCdt   :.:dOTCdt    0]
      [dOTMgCdt :.:dOTMgCdt  0]
      [dOCdt    :.:dOCdt     0];
  }

  Process ExpressionAssignmentProcess(v_O_Calse_assign)
  {
    StepperID    PSV;

    Name "d/dt O_Calse in component Ca_handling_by_the_SR (dimensionless)";
    Expression "480.000*(Ca_rel.MolarConc*1000)*(1.00000-O_Calse.Value)-400.000*O_Calse.Value";

      VariableReferenceList
        [v_O_Calse :.:v_O_Calse  1]
        [O_Calse   :.:O_Calse    0]
        [Ca_rel    :.:Ca_rel     0];
  }

  Process ExpressionFluxProcess(v_O_Calse)
  {
    Name "d/dt O_Calse in component Ca_handling_by_the_SR (dimensionless)";
    Expression "v_O_Calse.Value";

      VariableReferenceList
        [O_Calse   :.:O_Calse    1]
        [v_O_Calse :.:v_O_Calse  0];
  }

  Process ExpressionFluxProcess(j_Ca_rel)
  {
    Name "d/dt Ca_rel in component Ca_handling_by_the_SR (millimolar)";
    Expression "(i_tr.Value-i_rel.Value)/(2.00000*Vol_rel*F) * self.getSuperSystem().SizeN_A/1000 -31.0000*v_O_Calse.Value * self.getSuperSystem().SizeN_A/1000";
    F  @F;
    Vol_rel  @Vol_rel;

    VariableReferenceList
      [Ca_rel    :.:Ca_rel     1]
      [i_tr      :.:i_tr       0]
      [i_rel     :.:i_rel      0]
      [v_O_Calse :.:v_O_Calse  0];
  }

}
