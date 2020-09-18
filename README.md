CardiacMyocytes-Nygren_1998
==========================

Reference Publication
---------------------

* Nygren A, Fiset C, Firek L, et al. Mathematical model of an adult human atrial cell: the role of K+ currents in repolarization. *Circ Res*. 1998;82(1):63-81. doi:[10.1161/01.res.82.1.63](https://doi.org/10.1161/01.res.82.1.63) PMID: [9440706](https://pubmed.ncbi.nlm.nih.gov/9440706/)

Model Files
-----------

* `Nygren_1998.em`
  * Based on the python code generated by the CellML API from this CellML file. (see below)
* `Nygren_1998_custom.em`
  * A model using custom `Process`. Just execute `$ make`to build cpp files.
  * This model runs about twice as fast as `Nygren_1998.em` which uses Expression Process.

References
-----------

* CellML Nygren, Fiset, Firek, Clark, Lindblad, Clark, Giles, 1998
  * [Workspaces](https://models.physiomeproject.org/workspace/nygren_fiset_firek_clark_lindblad_clark_giles_1998)
  * [Exposures](https://models.physiomeproject.org/exposure/ad761ce160f3b4077bbae7a004c229e3)
  * [Generated Code (Python)](https://models.physiomeproject.org/exposure/ad761ce160f3b4077bbae7a004c229e3/nygren_fiset_firek_clark_lindblad_clark_giles_1998.cellml/@@cellml_codegen/Python)

Benchmark
-----------

* The custom Process model `Nygren_1998_custom.em` is 145% faster than the Expression-based Process model `Nygren_1998.em`.

```bash
$ ECELL3_DM_PATH="." ecell3-session -f Nygren_1998.em
session_history_file : /Volumes/Home/ynaito/.ecell/session-history
ecell3-session [ E-Cell SE Version 3.2.8, on Python Version 2.7.16 ]
Copyright (C) 1996-2019 Keio University
Copyright (C) 2008-2019 RIKEN
Copyright (C) 2005-2009 The Molecular Sciences Institute
More info: http://www.e-cell.org/software
<Nygren_1998.em, t=0>>> import time
<Nygren_1998.em, t=0>>> t0 = time.time(); run(3); t1 = time.time()
<Nygren_1998.em, t=3>>> print(t1-t0)
4.30589008331
```



```bash
$ ECELL3_DM_PATH="." ecell3-session -f Nygren_1998_custom.em
session_history_file : /Volumes/Home/ynaito/.ecell/session-history
ecell3-session [ E-Cell SE Version 3.2.8, on Python Version 2.7.16 ]
Copyright (C) 1996-2019 Keio University
Copyright (C) 2008-2019 RIKEN
Copyright (C) 2005-2009 The Molecular Sciences Institute
More info: http://www.e-cell.org/software
<Nygren_1998_custom.em, t=0>>> import time
<Nygren_1998_custom.em, t=0>>> t0 = time.time(); run(3); t1 = time.time()
<Nygren_1998_custom.em, t=3>>> print(t1-t0)
1.75741791725
```

Verification
--------------
INaの各パラメーター
ICaLの各パラメーター
Isus、Itの各パラメーター
IKr、IKsの各パラメーター
Isus、ICaL、Vm、INa、Itの値
↑検証済
