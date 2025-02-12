.. _changes_0_13:

Version 0.13 (2016-09-27)
-------------------------

Changelog
~~~~~~~~~

- Add new class :class:`AcqParserFIF` to parse Elekta/Neuromag MEG acquisition info, allowing e.g. collecting epochs according to acquisition-defined averaging categories by `Jussi Nurminen`_

- Adds automatic determination of FIR filter parameters ``filter_length``, ``l_trans_bandwidth``, and ``h_trans_bandwidth`` and adds ``phase`` argument in e.g. in :meth:`mne.io.Raw.filter` by `Eric Larson`_

- Adds faster ``n_fft='auto'`` option to :meth:`mne.io.Raw.apply_hilbert` by `Eric Larson`_

- Adds new function ``mne.time_frequency.csd_array`` to compute the cross-spectral density of multivariate signals stored in an array, by `Nick Foti`_

- Add order params 'selection' and 'position' for :func:`mne.viz.plot_raw` to allow plotting of specific brain regions by `Jaakko Leppakangas`_

- Added the ability to decimate :class:`mne.Evoked` objects with :func:`mne.Evoked.decimate` by `Eric Larson`_

- Add generic array-filtering function :func:`mne.filter.filter_data` by `Eric Larson`_

- ``mne.viz.plot_trans`` now also shows head position indicators by `Christian Brodbeck`_

- Add label center of mass function :func:`mne.Label.center_of_mass` by `Eric Larson`_

- Added :func:`mne.viz.plot_ica_properties` that allows plotting of independent component properties similar to ``pop_prop`` in EEGLAB. Also :class:`mne.preprocessing.ICA` has :func:`mne.preprocessing.ICA.plot_properties` method now. Added by `Mikołaj Magnuski`_

- Add second-order sections (instead of ``(b, a)`` form) IIR filtering for reduced numerical error by `Eric Larson`_

- Add interactive colormap option to image plotting functions by `Jaakko Leppakangas`_

- Add support for the University of Maryland KIT system by `Christian Brodbeck`_

- Add support for \*.elp and \*.hsp files to the KIT2FIFF converter and ``mne.channels.read_dig_montage`` by `Teon Brooks`_ and `Christian Brodbeck`_

- Add option to preview events in the KIT2FIFF GUI by `Christian Brodbeck`_

- Add approximation of size of :class:`io.Raw`, :class:`Epochs`, and :class:`Evoked` in :func:`repr` by `Eric Larson`_

- Add possibility to select a subset of sensors by lasso selector to :func:`mne.viz.plot_sensors` and :func:`mne.viz.plot_raw` when using order='selection' or order='position' by `Jaakko Leppakangas`_

- Add the option to plot brain surfaces and source spaces to :func:`viz.plot_bem` by `Christian Brodbeck`_

- Add the ``--filterchpi`` option to :ref:`mne browse_raw`, by `Felix Raimundo`_

- Add the ``--no-decimate`` option to :ref:`mne make_scalp_surfaces` to skip the high-resolution surface decimation step, by `Eric Larson`_

- Add new class :class:`mne.decoding.EMS` to transform epochs with the event-matched spatial filters and add 'cv' parameter to :func:`mne.decoding.compute_ems`, by `Jean-Remi King`_

- Added :class:`mne.time_frequency.EpochsTFR` and average parameter in :func:`mne.time_frequency.tfr_morlet` and :func:`mne.time_frequency.tfr_multitaper` to compute time-frequency transforms on single trial epochs without averaging, by `Jean-Remi King`_ and `Alex Gramfort`_

- Added :class:`mne.decoding.TimeFrequency` to transform signals in scikit-learn pipelines, by `Jean-Remi King`_

- Added :class:`mne.decoding.UnsupervisedSpatialFilter` providing interface for scikit-learn decomposition algorithms to be used with MNE data, by `Jean-Remi King`_ and `Asish Panda`_

- Added support for multiclass decoding in :class:`mne.decoding.CSP`, by `Jean-Remi King`_ and `Alexandre Barachant`_

- Components obtained from :class:`mne.preprocessing.ICA` are now sorted by explained variance, by `Mikołaj Magnuski`_

- Adding an EEG reference channel using :func:`mne.add_reference_channels` will now use its digitized location from the FIFF file, if present, by `Chris Bailey`_

- Added interactivity to :func:`mne.preprocessing.ICA.plot_components` - passing an instance of :class:`io.Raw` or :class:`Epochs` in ``inst`` argument allows to open component properties by clicking on component topomaps, by `Mikołaj Magnuski`_

- Adds new function :func:`mne.viz.plot_compare_evokeds` to show multiple evoked time courses at a single location, or the mean over a ROI, or the GFP, automatically averaging and calculating a CI if multiple subjects are given, by `Jona Sassenhagen`_

- Added ``transform_into`` parameter into :class:`mne.decoding.CSP` to retrieve the average power of each source or the time course of each source, by `Jean-Remi King`_

- Added support for reading MaxShield (IAS) evoked data (e.g., from the acquisition machine) in :func:`mne.read_evokeds` by `Eric Larson`_

- Added support for functional near-infrared spectroscopy (fNIRS) channels by `Jaakko Leppakangas`_

- Added :attr:`mne.io.Raw.acqparser` convenience attribute for :class:`mne.AcqParserFIF` by `Eric Larson`_

- Added example of Representational Similarity Analysis, by `Jean-Remi King`_

BUG
~~~

- Fixed a bug where selecting epochs using hierarchical event IDs (HIDs) was *and*-like instead of *or*-like. When doing e.g. ``epochs[('Auditory', 'Left')]``, previously all trials that contain ``'Auditory'`` *and* ``'Left'`` (like ``'Auditory/Left'``) would be selected, but now any conditions matching ``'Auditory'`` *or* ``'Left'`` will be selected (like ``'Auditory/Left'``, ``'Auditory/Right'``, and ``'Visual/Left'``). This is now consistent with how epoch selection was done without HID tags, e.g. ``epochs[['a', 'b']]`` would select all epochs of type ``'a'`` and type ``'b'``. By `Eric Larson`_

- Fixed Infomax/Extended Infomax when the user provides an initial weights matrix by `Jair Montoya Martinez`_

- Fixed the default raw FIF writing buffer size to be 1 second instead of 10 seconds by `Eric Larson`_

- Fixed channel selection order when MEG channels do not come first in :func:`mne.preprocessing.maxwell_filter` by `Eric Larson`_

- Fixed color ranges to correspond to the colorbar when plotting several time instances with :func:`mne.viz.plot_evoked_topomap` by `Jaakko Leppakangas`_

- Added units to :func:`mne.io.read_raw_brainvision` for reading non-data channels and enable default behavior of inferring channel type by unit by `Jaakko Leppakangas`_ and `Pablo-Arias`_

- Fixed minor bugs with :func:`mne.Epochs.resample` and :func:`mne.Epochs.decimate` by `Eric Larson`_

- Fixed a bug where duplicate vertices were not strictly checked by :func:`mne.simulation.simulate_stc` by `Eric Larson`_

- Fixed a bug where some FIF files could not be read with :func:`mne.io.show_fiff` by `Christian Brodbeck`_ and `Eric Larson`_

- Fixed a bug where ``merge_grads=True`` causes :func:`mne.viz.plot_evoked_topo` to fail when plotting a list of evokeds by `Jaakko Leppakangas`_

- Fixed a bug when setting multiple bipolar references with :func:`set_bipolar_reference` by `Marijn van Vliet`_.

- Fixed image scaling in :func:`mne.viz.plot_epochs_image` when plotting more than one channel by `Jaakko Leppakangas`_

- Fixed :class:`mne.preprocessing.Xdawn` to fit shuffled epochs by `Jean-Remi King`_

- Fixed a bug with channel order determination that could lead to an ``AssertionError`` when using :class:`mne.Covariance` matrices by `Eric Larson`_

- Fixed the check for CTF gradient compensation in :func:`mne.preprocessing.maxwell_filter` by `Eric Larson`_

- Fixed the import of EDF files with encoding characters in :func:`mne.io.read_raw_edf` by `Guillaume Dumas`_

- Fixed :class:`mne.Epochs` to ensure that detrend parameter is not a boolean by `Jean-Remi King`_

- Fixed bug with ``mne.realtime.FieldTripClient.get_data_as_epoch`` when ``picks=None`` which crashed the function by `Mainak Jas`_

- Fixed reading of units in ``.elc`` montage files (from ``UnitsPosition`` field) so that ``mne.channels.Montage`` objects are now returned with the ``pos`` attribute correctly in meters, by `Chris Mullins`_

- Fixed reading of BrainVision files by `Phillip Alday`_:

- Greater support for BVA files, especially older ones: alternate text coding schemes with fallback to Latin-1 as well as units in column headers

- Use online software filter information when present

- Fix comparisons of filter settings for determining "strictest"/"weakest" filter

- Weakest filter is now used for heterogeneous channel filter settings, leading to more consistent behavior with filtering methods applied to a subset of channels (e.g. ``Raw.filter`` with ``picks != None``).

- Fixed plotting and timing of :class:`Annotations` and restricted addition of annotations outside data range to prevent problems with cropping and concatenating data by `Jaakko Leppakangas`_

- Fixed ICA plotting functions to refer to IC index instead of component number by `Andreas Hojlund`_ and `Jaakko Leppakangas`_

- Fixed bug with ``picks`` when interpolating MEG channels by `Mainak Jas`_.

- Fixed bug in padding of Stockwell transform for signal of length a power of 2 by `Johannes Niediek`_

API
~~~

- The ``add_eeg_ref`` argument in core functions like :func:`mne.io.read_raw_fif` and :class:`mne.Epochs` has been deprecated in favor of using :func:`mne.set_eeg_reference` and equivalent instance methods like :meth:`raw.set_eeg_reference() <mne.io.Raw.set_eeg_reference>`. In functions like :func:`mne.io.read_raw_fif` where the default in 0.13 and older versions is ``add_eeg_ref=True``, the default will change to ``add_eeg_ref=False`` in 0.14, and the argument will be removed in 0.15.

- Multiple aspects of FIR filtering in MNE-Python has been refactored:

  1. New recommended defaults for ``l_trans_bandwidth='auto'``, ``h_trans_bandwidth='auto'``, and ``filter_length='auto'``. This should generally reduce filter artifacts at the expense of slight decrease in effective filter stop-band attenuation. For details see :ref:`tut_filtering_in_python`. The default values of ``l_trans_bandwidth=h_trans_bandwidth=0.5`` and ``filter_length='10s'`` will change to ``'auto'`` in 0.14.

  2. The ``filter_length=None`` option (i.e. use ``len(x)``) has been deprecated.

  3. An improved ``phase='zero'`` zero-phase FIR filtering has been added. Instead of running the designed filter forward and backward, the filter is applied once and we compensate for the linear phase of the filter. The previous ``phase='zero-double'`` default will change to ``phase='zero'`` in 0.14.

  4. A warning is provided when the filter is longer than the signal of interest, as this is unlikely to produce desired results.

  5. Previously, if the filter was as long or longer than the signal of interest, direct FFT-based computations were used. Now a single code path (overlap-add filtering) is used for all FIR filters. This could cause minor changes in how short signals are filtered.

- Support for Python 2.6 has been dropped, and the minimum supported dependencies are NumPy_ 1.8, SciPy_ 0.12, and Matplotlib_ 1.3 by `Eric Larson`_

- When CTF gradient compensation is applied to raw data, it is no longer reverted on save of :meth:`mne.io.Raw.save` by `Eric Larson`_

- Adds ``mne.time_frequency.csd_epochs`` to replace ``mne.time_frequency.csd_compute_epochs`` for naming consistency. ``mne.time_frequency.csd_compute_epochs`` is now deprecated and will be removed in mne 0.14, by `Nick Foti`_

- Weighted addition and subtraction of :class:`Evoked` as ``ev1 + ev2`` and ``ev1 - ev2`` have been deprecated, use explicit :func:`mne.combine_evoked(..., weights='nave') <mne.combine_evoked>` instead by `Eric Larson`_

- Deprecated support for passing a list of filenames to :class:`mne.io.Raw` constructor, use :func:`mne.io.read_raw_fif` and :func:`mne.concatenate_raws` instead by `Eric Larson`_

- Added options for setting data and date formats manually in :func:`mne.io.read_raw_cnt` by `Jaakko Leppakangas`_

- Now channels with units of 'C', 'µS', 'uS', 'ARU' and 'S' will be turned to misc by default in :func:`mne.io.read_raw_brainvision` by `Jaakko Leppakangas`_

- Add :func:`mne.io.anonymize_info` function to anonymize measurements and add methods to :class:`mne.io.Raw`, :class:`mne.Epochs` and :class:`mne.Evoked`, by `Jean-Remi King`_

- Now it is possible to plot only a subselection of channels in :func:`mne.viz.plot_raw` by using an array for order parameter by `Jaakko Leppakangas`_

- EOG channels can now be included when calling :func:`mne.preprocessing.ICA.fit` and a proper error is raised when trying to include unsupported channels by `Alexander Rudiuk`_

- :func:`mne.concatenate_epochs` and :func:`mne.compute_covariance` now check to see if all :class:`Epochs` instances have the same MEG-to-Head transformation, and errors by default if they do not by `Eric Larson`_

- Added option to pass a list of axes to :func:`mne.viz.plot_epochs_image` by `Mikołaj Magnuski`_

- Constructing IIR filters in :func:`mne.filter.construct_iir_filter` defaults to ``output='ba'`` in 0.13 but this will be changed to ``output='sos'`` by `Eric Larson`_

- Add ``zorder`` parameter to :func:`mne.Evoked.plot` and derived functions to sort allow sorting channels by e.g. standard deviation, by `Jona Sassenhagen`_

- The ``baseline`` parameter of :func:`mne.Epochs.apply_baseline` is set by default (None, 0), by `Felix Raimundo`_

- Adds :func:`mne.Evoked.apply_baseline` to be consistent with :func:`mne.Epochs.apply_baseline`, by `Felix Raimundo`_

- Deprecated the ``baseline`` parameter in :class:`mne.Evoked`, by `Felix Raimundo`_

- The API of :meth:`mne.SourceEstimate.plot` and :func:`mne.viz.plot_source_estimates` has been updated to reflect current PySurfer 0.6 API. The ``config_opts`` parameter is now deprecated and will be removed in mne 0.14, and the default representation for time will change from ``ms`` to ``s`` in mne 0.14. By `Christian Brodbeck`_

- The default dataset location has been changed from ``examples/`` in the MNE-Python root directory to ``~/mne_data`` in the user's home directory, by `Eric Larson`_

- A new option ``set_env`` has been added to :func:`mne.set_config` that defaults to ``False`` in 0.13 but will change to ``True`` in 0.14, by `Eric Larson`_

- The ``compensation`` parameter in :func:`mne.io.read_raw_fif` has been deprecated in favor of the method :meth:`mne.io.Raw.apply_gradient_compensation` by `Eric Larson`_

- ``mne.decoding.EpochsVectorizer`` has been deprecated in favor of :class:`mne.decoding.Vectorizer` by `Asish Panda`_

- The ``epochs_data`` parameter has been deprecated in :class:`mne.decoding.CSP`, in favour of the ``X`` parameter to comply to scikit-learn API, by `Jean-Remi King`_

- Deprecated ``mne.time_frequency.cwt_morlet`` and ``mne.time_frequency.single_trial_power`` in favour of :func:`mne.time_frequency.tfr_morlet` with parameter average=False, by `Jean-Remi King`_ and `Alex Gramfort`_

- Add argument ``mask_type`` to func:`mne.read_events` and func:`mne.find_events` to support MNE-C style of trigger masking by `Teon Brooks`_ and `Eric Larson`_

- Extended Infomax is now the new default in :func:`mne.preprocessing.infomax` (``extended=True``), by `Clemens Brunner`_

- :func:`mne.io.read_raw_eeglab` and :func:`mne.read_epochs_eeglab` now take additional argument ``uint16_codec`` that allows to define the encoding of character arrays in set file. This helps in rare cases when reading a set file fails with ``TypeError: buffer is too small for requested array``. By `Mikołaj Magnuski`_

- Added :class:`mne.decoding.TemporalFilter` to filter data in scikit-learn pipelines, by `Asish Panda`_

- :func:`mne.preprocessing.create_ecg_epochs` now includes all the channels when ``picks=None`` by `Jaakko Leppakangas`_

- :func:`mne.set_eeg_reference` now allows moving from a custom to an average EEG reference by `Marijn van Vliet`_

Authors
~~~~~~~

The committer list for this release is the following (sorted by alphabetical order):

* Alexander Rudiuk
* Alexandre Barachant
* Alexandre Gramfort
* Asish Panda
* Camilo Lamus
* Chris Holdgraf
* Christian Brodbeck
* Christopher J. Bailey
* Christopher Mullins
* Clemens Brunner
* Denis A. Engemann
* Eric Larson
* Federico Raimondo
* Félix Raimundo
* Guillaume Dumas
* Jaakko Leppakangas
* Jair Montoya
* Jean-Remi King
* Johannes Niediek
* Jona Sassenhagen
* Jussi Nurminen
* Keith Doelling
* Mainak Jas
* Marijn van Vliet
* Michael Krause
* Mikolaj Magnuski
* Nick Foti
* Phillip Alday
* Simon-Shlomo Poil
* Teon Brooks
* Yaroslav Halchenko
